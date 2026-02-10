# The application runs a UART-controlled LED mode machine with 7 distinct operating modes, driven by a single main loop.

# 7 Application Modes
Mode 0: LED completely OFF (pwm_set_duty(0))

Mode 1: LED always ON (pwm_set_duty(100))

Mode 2: Slow blink every 500ms

Mode 3: Fast blink every 100ms

Mode 4: Breathing effect (2% to 98% PWM ramp)

Mode 5: Custom 8-step pattern sequence

Mode 6: Reaction time game (press any key when LED lights)

# Main Loop State Machine
<img width="1536" height="1024" alt="main flowchart" src="https://github.com/user-attachments/assets/73dd7168-2c42-4cfe-9239-e9feb6487eed" />

# Command parsing: 
'm0'→mode=0, 'm1'→mode=1, etc. Help via 'h', status via 's'.

# Timing Behavior
Mode 2: if(now - last > 500ms) { duty = !duty; last = now; }

Mode 3: if(now - last > 100ms) { duty = !duty; last = now; }

Mode 4: if(now - last > 20ms)  { duty += dir*2; check bounds; }

Mode 5: if(now - last > 200ms) { pattern[pattern_idx++]; }

All timing uses timer_get_tick() for exact millisecond precision.

# Driver Orchestration
<img width="1536" height="1024" alt="driver" src="https://github.com/user-attachments/assets/03b745da-11f2-4b39-ad56-a260bd39c081" />

**Key pattern: Application only calls *_init() once + functional APIs. Never touches registers.**

# Edge Cases Handled
Invalid commands: "Unknown command\r\n" + continue current mode

Buffer overflow: cmd_pos < sizeof(cmd_buf)-1 prevents overrun

Mode bounds: if(m>='0' && m<='6') rejects m7+

PWM clamping: ISR naturally clamps pwm_counter >= 100

Game cheating: Clears UART buffer before reaction timing starts

Timer wrap: 32-bit tick_count safe for ~49 days continuous run

