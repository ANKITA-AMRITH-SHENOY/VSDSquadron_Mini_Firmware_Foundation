#include "gpio.h"

void led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = (1 << LED_PIN);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_SetBits(GPIOD, (1 << LED_PIN));  // Start with LED OFF
}

void led_on(void)
{
    GPIO_SetBits(GPIOD, (1 << LED_PIN));
}

void led_off(void)
{
    GPIO_ResetBits(GPIOD, (1 << LED_PIN));
}
