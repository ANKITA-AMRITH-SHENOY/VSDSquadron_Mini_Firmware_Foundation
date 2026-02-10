# How to Run and Verify (5 Minutes)
Connect CH32V00x dev board via USB. PC6 = onboard LED, PD5/PD6 = UART.

## Steps:

# 1. Flash Firmware (2 min)
PlatformIO (Recommended):

# Platformio.ini:
```
[env:vsdsquadronMini]
platform = ch32v
board = vsdsquadronMini
framework = noneos-sdk
monitor_speed = 115200
monitor_echo = yes
monitor_eol = CRLF
monitor_filters = send_on_enter
```

## Build & Upload :
<ins> Using Commands: </ins>
```
pio run --target upload
pio device monitor
```
or just click Build and Upload.

# 2. UART Terminal Setup
Tool: PuTTY / PlatformIO Monitor / Arduino Serial

Port: COMx / /dev/ttyUSBx (115200 baud auto-detected)

Settings: 115200 baud, 8N1, No flow control

# 3. Exact Demo Sequence
```
> h                    # Show help
Modes:
0 OFF
1 ON  
2 BLINK (500ms)
3 FAST BLINK (100ms)
4 BREATHE
5 PATTERN
6 GAME
> 

> m1                   # LED FULL ON
Mode 1
> 

> m2                   # SLOW BLINK 500ms ON/OFF
Mode 2  
>                      # Observe LED blink every 500ms

> m4                   # BREATHING EFFECT
Mode 4
>                      # LED smoothly fades in/out

> m6                   # REACTION GAME
Get ready...
[wait 1-3s] LED LIGHTS → **PRESS ANY KEY FAST**
Reaction time: 234 ms    # Your time shown!

> s                    # Status check
Current mode: 6
>
```

4. Expected Hardware Behavior
```
m1: LED solid bright ────────
m2: LED blink ╔═══════╗═══════ (500ms ON, 500ms OFF)
m3: LED blink ╔═══╗═══╗═══╗═══ (100ms ON/OFF)  
m4: LED breathe ║ smooth ramp 2-98% PWM ║
m5: LED pattern ╔═╗═╗═╗═╗═╗═╗═╗ (200ms pattern)
m6: Game → random delay → LED ON → press key → measure ms
```

6. Troubleshooting

No response? → Check 115200 baud

LED not blinking? → PC6 connected? Flash success?

Upload fail? → Hold BOOT button during reset (WCH-Link)

Garbled UART? → Wrong baud rate or line endings

*Reviewer Observation: Type m4, see smooth breathing on LED + UART feedback. Takes 90 seconds to verify all modes.*
*(m0=LED OFF, m1=LED ON, m2=BLINK(500ms) , m3=FAST BLINK(100ms) , m4= BREATHE ,m5= PATTERN , m6= GAME)*
