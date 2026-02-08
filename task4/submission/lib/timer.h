#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>

void timer_init(uint32_t tick_hz);
void timer_delay_ms(uint32_t ms);
uint32_t timer_get_tick(void);

#endif

