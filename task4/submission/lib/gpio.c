#include "gpio.h"

void gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    /* Enable GPIOC clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    /* PC6 as output */
    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(LED_PORT, &GPIO_InitStructure);
}

void gpio_set_high(uint16_t pin)
{
    GPIO_SetBits(LED_PORT, pin);
}

void gpio_set_low(uint16_t pin)
{
    GPIO_ResetBits(LED_PORT, pin);
}

void gpio_toggle(uint16_t pin)
{
    if (GPIO_ReadOutputDataBit(LED_PORT, pin))
        GPIO_ResetBits(LED_PORT, pin);
    else
        GPIO_SetBits(LED_PORT, pin);
}

