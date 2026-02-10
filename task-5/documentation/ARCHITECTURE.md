# System Design

The system implements a layered UART-controlled LED driver for CH32V00x microcontrollers, separating low-level hardware drivers from high-level application logic.

# High-Level Block Diagram
<img width="1536" height="1024" alt="1" src="https://github.com/user-attachments/assets/6c9611cc-738f-4858-90cc-6fc0309d7f19" />

---

# Layer Separation
1. Drivers (Modular HAL)
GPIO: Basic PC6 output control (init, set_high/low, toggle).
​
PWM: Software PWM via TIM2 interrupt (~10kHz, 100-step resolution).
​
Timer: TIM1-based 1ms tick generator for delays and timing.
​
UART: USART1 (PD5/PD6) for bidirectional commands/status.
​
Each driver exposes simple init() + functional APIs. No direct hardware access in application code.

2. Application (main.c)
Implements 7 UART-controlled modes (m0-m6): OFF, ON, blink variations, breathing PWM, pattern, and reaction game. UART parsing drives finite state machine.
​

3. Main Loop (Scheduler)
No RTOS. Single infinite while(1) loop acts as cooperative scheduler:

1. Non-blocking UART input parsing
2. Mode-specific timed execution using tick_count delta checks
3. Zero interrupt dependencies in main thread

---

# Data Flow
<img width="1536" height="1024" alt="data flow" src="https://github.com/user-attachments/assets/b71aaf4d-d5ca-4586-bb7e-9f5bdd487264" />

---

# Control Flow
<img width="1536" height="1024" alt="control flow" src="https://github.com/user-attachments/assets/51931492-5583-41ee-92b9-24369e44f902" />

# Why this Architecture?

1. Tiny Memory :
CH32V00x has only 2KB RAM - too small for operating systems. Simple main loop uses just 100 bytes stack. Fits complex LED game perfectly.

2. Perfect Timing :
TIM1 gives exact 1ms ticks for 500ms blinks, 20ms breathing. No guessing with for-loops that drift over time. Always precise.

3. Easy to Understand :
One main loop handles UART commands and all modes. No confusing task switching or interrupts in main code. UART shows exactly what's running.

4. Reusable Code :
GPIO driver works for any LED on any board. UART driver becomes debug console anywhere. Change MCU? Rewrite just 4 files.

5. Simple Debugging :
UART prints "Mode 4 active" so you see what's happening. No hunting registers during debug. Fix bugs in one file only.

6. Easy to Expand :
Add Mode 7? Just 2 lines in main.c switch statement. Drivers stay exactly same. Clean code grows cleanly.



