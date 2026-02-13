#ifndef GPIO_H
#define GPIO_H

#include "ch32v00x.h"

#define LED_PIN 6   // PD6

void gpio_init(void);
void gpio_set(int pin);
void gpio_clear(int pin);

#endif

