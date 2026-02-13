#include "gpio.h"
#include "uart.h"
#include "debug.h"

void delay_ms(uint32_t ms)
{
    for (volatile uint32_t i = 0; i < ms * 4000; i++);
}

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    led_init();
    uart_init(115200);

    uart_send_string("\r\nVSDSquadron Mini UART:\r\n");

    while (1)
    {
        led_on();                               // TURN ON FIRST
        uart_send_string("LED ON\r\n");         // THEN PRINT
        delay_ms(1000);

        led_off();                              // TURN OFF
        uart_send_string("LED OFF\r\n");        // THEN PRINT
        delay_ms(1000);
    }
}
