#include "gpio.h"
#include "ch32v00x.h"

void gpio_led_init(void)
{
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOD;

    /* PD6 output push-pull */
    GPIOD->CFGLR &= ~(0xF << (6 * 4));
    GPIOD->CFGLR |=  (0x3 << (6 * 4));
}

void gpio_led_toggle(void)
{
    GPIOD->OUTDR ^= (1 << 6);
}

