#include "timer.h"

/* Software millisecond timer */
static volatile uint32_t ms_ticks = 0;

void timer_init(void)
{
    ms_ticks = 0;
}

void timer_delay_ms(uint32_t ms)
{
    volatile uint32_t i;

    while (ms--)
    {
        for (i = 0; i < 8000; i++)
        {
            __asm__("nop");
        }
        ms_ticks++;
    }
}

uint32_t timer_get_ms(void)
{
    return ms_ticks;
}

