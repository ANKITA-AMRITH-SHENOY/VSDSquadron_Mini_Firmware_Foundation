#ifndef GPIO_H
#define GPIO_H

#include "ch32v00x.h"

/* External LED on PC6 */
#define LED_PIN  GPIO_Pin_6
#define LED_PORT GPIOC

void gpio_init(void);
void gpio_set_high(uint16_t pin);
void gpio_set_low(uint16_t pin);
void gpio_toggle(uint16_t pin);

#endif

