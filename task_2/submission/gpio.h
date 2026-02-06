#ifndef GPIO_H
#define GPIO_H

#include "ch32v00x.h"

#define LED_PIN 6 // PD6 for VSDSquadron Mini (pin number only)

void gpio_init(void);
void gpio_set(int pin);
void gpio_clear(int pin);
void gpio_toggle(int pin);

#endif
