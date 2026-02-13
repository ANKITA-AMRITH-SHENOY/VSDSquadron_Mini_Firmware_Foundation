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

    gpio_init();
    uart_init(115200);

    uart_send_string("\r\nVSDSquadron Mini UART:\r\n");

    while (1)
    {
        gpio_clear(LED_PIN);   // LED ON
        uart_send_string("LED ON!\r\n");
        delay_ms(1000);

        gpio_set(LED_PIN);     // LED OFF
        uart_send_string("LED OFF!\r\n");
        delay_ms(1000);
    }
}
