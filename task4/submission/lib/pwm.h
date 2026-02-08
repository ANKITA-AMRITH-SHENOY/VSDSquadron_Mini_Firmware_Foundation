#ifndef PWM_H
#define PWM_H
#include "ch32v00x.h"

void pwm_init(void);
void pwm_set_duty(uint8_t duty_percent);  // 0-100%

#endif

