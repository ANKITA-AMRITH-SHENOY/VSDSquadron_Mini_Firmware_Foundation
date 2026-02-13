#include "gpio.h"

void gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = (1 << LED_PIN);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_SetBits(GPIOD, (1 << LED_PIN)); // LED OFF (active-low)
}

void gpio_set(int pin)
{
    GPIO_SetBits(GPIOD, (1 << pin));   // LED OFF
}

void gpio_clear(int pin)
{
    GPIO_ResetBits(GPIOD, (1 << pin)); // LED ON
}
