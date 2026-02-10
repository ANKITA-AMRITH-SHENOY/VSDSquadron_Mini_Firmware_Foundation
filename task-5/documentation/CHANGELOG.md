# CHANGELOG.md — Engineering Discipline

## v1.0.0 – Initial Release (2026-02-11)
- Implemented GPIO driver (`gpio.h/c`) - PC6 LED control
- Added UART command interface (`uart.h/c`) - 115200 baud PD5/PD6  
- Integrated timer-based scheduling (`timer.h/c`) - 1ms TIM1 ticks
- Created software PWM engine (`pwm.h/c`) - 10kHz TIM2 ISR
- Added 7 UART-controlled LED modes (m0-m6) including breathing + game
- Established modular HAL architecture - drivers fully independent

