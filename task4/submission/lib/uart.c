#include "uart.h"
#include "ch32v00x.h"

/*
 * UART1 is used
 * TX : PD5
 * RX : PD6   (change if your board uses different pins)
 */

void uart_init(uint32_t baud)
{
    /* Enable clocks */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);

    /* Configure TX (PD5) */
    GPIO_InitTypeDef gpio;
    gpio.GPIO_Pin = GPIO_Pin_5;
    gpio.GPIO_Mode = GPIO_Mode_AF_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &gpio);

    /* Configure RX (PD6) */
    gpio.GPIO_Pin = GPIO_Pin_6;
    gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &gpio);

    /* UART configuration */
    USART_InitTypeDef usart;
    usart.USART_BaudRate = baud;
    usart.USART_WordLength = USART_WordLength_8b;
    usart.USART_StopBits = USART_StopBits_1;
    usart.USART_Parity = USART_Parity_No;
    usart.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    usart.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(USART1, &usart);

    USART_Cmd(USART1, ENABLE);
}

/* Send single character */
void uart_send_char(char c)
{
    while (!(USART1->STATR & USART_STATR_TXE));
    USART1->DATAR = c;
}

/* Send string */
void uart_send_string(const char *s)
{
    while (*s)
        uart_send_char(*s++);
}

/* Blocking receive */
char uart_receive_char(void)
{
    while (!(USART1->STATR & USART_STATR_RXNE));
    return (char)USART1->DATAR;
}

/* Non-blocking receive check */
uint8_t uart_char_available(void)
{
    return (USART1->STATR & USART_STATR_RXNE) ? 1 : 0;
}

