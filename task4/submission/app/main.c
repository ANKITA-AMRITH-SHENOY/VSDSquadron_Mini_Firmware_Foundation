#include "ch32v00x.h"
#include "uart.h"
#include "gpio.h"
#include "pwm.h"
#include "timer.h"
#include <stdio.h>

/* ---------------- Global variables ---------------- */

uint8_t mode = 0;
uint32_t last = 0;
uint8_t duty = 0;
int8_t dir = 1;

char cmd_buf[8];
uint8_t cmd_pos = 0;

/* Pattern mode */
const uint8_t pattern[] = {1,0,1,1,0,0,1,1};
uint8_t pattern_idx = 0;

/* Game mode */
uint8_t game_state = 0;
uint32_t game_start = 0;

/* -------------------------------------------------- */

void process_cmd(void);

int main(void)
{
    SystemCoreClockUpdate();

    uart_init(115200);
    timer_init(1000);      // 1 ms tick
    gpio_init();
    pwm_init();

    uart_send_string("\r\n=== UART Controlled Mode Machine ===\r\n");
    uart_send_string("h=help, m0-m6=mode, s=status\r\n> ");

    while (1)
    {
        uint32_t now = timer_get_tick();

        /* -------- UART input (non-blocking) -------- */
        if (uart_char_available())
        {
            char c = uart_receive_char();

            if (c == '\r' || c == '\n')
            {
                uart_send_string("\r\n");
                if (cmd_pos > 0)
                    process_cmd();

                cmd_pos = 0;
                uart_send_string("> ");
            }
            else if (cmd_pos < sizeof(cmd_buf) - 1)
            {
                cmd_buf[cmd_pos++] = c;
            }
        }

        /* ---------------- Mode execution ---------------- */

        /* m0: OFF */
        if (mode == 0)
        {
            pwm_set_duty(0);
        }

        /* m1: ON */
        else if (mode == 1)
        {
            pwm_set_duty(100);
        }

        /* m2: Blink 500 ms */
        else if (mode == 2 && now - last > 500)
        {
            duty = (duty == 0) ? 100 : 0;
            pwm_set_duty(duty);
            last = now;
        }

        /* m3: Fast blink 100 ms */
        else if (mode == 3 && now - last > 100)
        {
            duty = (duty == 0) ? 100 : 0;
            pwm_set_duty(duty);
            last = now;
        }

        /* m4: Breathing PWM */
        else if (mode == 4 && now - last > 20)
        {
            duty += dir * 2;

            if (duty >= 98) { duty = 98; dir = -1; }
            else if (duty <= 2) { duty = 2; dir = 1; }

            pwm_set_duty(duty);
            last = now;
        }

        /* m5: Pattern mode */
        else if (mode == 5 && now - last > 200)
        {
            if (pattern[pattern_idx])
                pwm_set_duty(100);
            else
                pwm_set_duty(0);

            pattern_idx++;
            if (pattern_idx >= sizeof(pattern))
                pattern_idx = 0;

            last = now;
        }

        /* m6: Reaction-time game */
        else if (mode == 6)
        {
            if (game_state == 0)
            {
                uart_send_string("Get ready...\r\n");

                /* random delay: 1–3 seconds */
                timer_delay_ms(1000 + (timer_get_tick() % 2000));

                pwm_set_duty(100);   // LED ON
                game_start = timer_get_tick();
                game_state = 1;
            }
            else if (game_state == 1)
            {
                if (uart_char_available())
                {
                    uart_receive_char();   // clear input
                    pwm_set_duty(0);       // LED OFF

                    uint32_t reaction = timer_get_tick() - game_start;

                    char buf[20];
                    sprintf(buf, "Reaction time: %lu ms\r\n", reaction);
                    uart_send_string(buf);

                    game_state = 0;
                    mode = 0;   // back to OFF
                }
            }
        }
    }
}

/* ---------------- Command processing ---------------- */

void process_cmd(void)
{
    cmd_buf[cmd_pos] = 0;

    if (cmd_buf[0] == 'h')
    {
        uart_send_string(
            "Modes:\r\n"
            "0 OFF\r\n"
            "1 ON\r\n"
            "2 BLINK (500ms)\r\n"
            "3 FAST BLINK (100ms)\r\n"
            "4 BREATHE\r\n"
            "5 PATTERN\r\n"
            "6 GAME\r\n"
        );
    }
    else if (cmd_buf[0] == 'm' && cmd_pos == 2)
    {
        char m = cmd_buf[1];
        if (m >= '0' && m <= '6')
        {
            mode = m - '0';
            uart_send_string("Mode ");
            uart_send_char('0' + mode);
            uart_send_string("\r\n");

            /* reset helpers */
            pattern_idx = 0;
            game_state = 0;
        }
    }
    else if (cmd_buf[0] == 's')
    {
        uart_send_string("Current mode: ");
        uart_send_char('0' + mode);
        uart_send_string("\r\n");
    }
    else
    {
        uart_send_string("Unknown command\r\n");
    }
}


