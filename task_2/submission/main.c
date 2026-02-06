#include <stdint.h>
#include <stdio.h>
#include "ch32v00x.h"
#include "debug.h"

/* Simple delay */
void delay_ms(uint32_t ms)
{
    for (volatile uint32_t i = 0; i < ms * 4000; i++);
}

int main(void)
{
    /* System init */
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    /* Enable GPIOD clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    /* LED on PD6 */
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    /* UART init (USART on PD5 TX, PD6 RX) */
    USART_Printf_Init(115200);

    printf("\r\nVSDSquadron Mini UART :\r\n");

    while (1)
    {
        GPIO_WriteBit(GPIOD, GPIO_Pin_6, Bit_SET);
        printf("LED ON !\r\n");
        delay_ms(1000);

        GPIO_WriteBit(GPIOD, GPIO_Pin_6, Bit_RESET);
        printf("LED OFF !\r\n");
        delay_ms(1000);
    }
}

