#include "uart.h"
#include "ch32v00x.h"

void uart_init(uint32_t baud)
{
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1;

    /* PD5 = TX (AF push-pull) */
    GPIOD->CFGLR &= ~(0xF << (5 * 4));
    GPIOD->CFGLR |=  (0xB << (5 * 4));

    USART1->BRR = SystemCoreClock / baud;
    USART1->CTLR1 |= USART_CTLR1_TE | USART_CTLR1_UE;
}

void uart_putc(char c)
{
    while (!(USART1->STATR & USART_STATR_TXE));
    USART1->DATAR = c;
}

void uart_print(const char *s)
{
    while (*s)
        uart_putc(*s++);
}

void uart_print_uint(uint32_t val)
{
    char buf[10];
    int i = 0;

    if (val == 0)
    {
        uart_putc('0');
        return;
    }

    while (val)
    {
        buf[i++] = (val % 10) + '0';
        val /= 10;
    }

    while (i--)
        uart_putc(buf[i]);
}

