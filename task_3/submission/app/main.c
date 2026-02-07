#include "timer.h"
#include "uart.h"
#include "gpio.h"

int main(void)
{
    timer_init();
    uart_init(9600);
    gpio_led_init();

    uart_print("Task-3 Timer Demo Started\r\n");

    while (1)
    {
        gpio_led_toggle();

        uart_print("Timestamp(ms): ");
        uart_print_uint(timer_get_ms());
        uart_print("\r\n");

        timer_delay_ms(1000);
    }
}

