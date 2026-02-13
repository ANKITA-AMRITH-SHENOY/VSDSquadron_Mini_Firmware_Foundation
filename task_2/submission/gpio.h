#ifndef GPIO_H
#define GPIO_H

#include "ch32v00x.h"

#define LED_PIN 6   // PD6

void led_init(void);
void led_on(void);
void led_off(void);

#endif

