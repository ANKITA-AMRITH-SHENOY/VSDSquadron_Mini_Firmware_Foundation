# Project Name : **UART Controlled Mode Machine**

## Project Description

This project implements a UART-controlled mode machine on a CH32 microcontroller, where different LED behaviors are selected dynamically through serial commands without resetting the system. The firmware integrates multiple peripheral drivers—GPIO, UART, Timer, and PWM—to demonstrate multi-driver interaction in a single application. Users can control LED modes such as ON, OFF, blinking, breathing (PWM), pattern sequencing, and a reaction-time game via a UART terminal, making it suitable for demonstrating embedded system concepts and real hardware validation.

---

## Drivers Used

- **GPIO** – Controls an external LED connected to the microcontroller  
- **UART** – Receives user commands and prints status/debug messages  
- **Timer** – Provides a 1 ms system tick for delays, blinking, and timing  
- **PWM** – Controls LED brightness for breathing effect  

---

## API Summary (Key Functions)

### GPIO
- `gpio_init()` – Initializes GPIO pin for external LED output  

### UART
- `uart_init(uint32_t baud)` – Initializes UART with given baud rate  
- `uart_send_string(char *str)` – Sends string over UART  
- `uart_receive_char()` – Receives a character from UART  
- `uart_char_available()` – Checks if UART data is available  

### Timer
- `timer_init(uint32_t tick_ms)` – Initializes timer for periodic ticks  
- `timer_get_tick()` – Returns system tick count in milliseconds  
- `timer_delay_ms(uint32_t ms)` – Blocking delay using timer  

### PWM
- `pwm_init()` – Initializes PWM peripheral  
- `pwm_set_duty(uint8_t duty)` – Sets PWM duty cycle (0–100%)  

---

## Build + Flash Steps (PlatformIO)

1. Open the project folder in **VS Code**
2. Ensure **PlatformIO** extension is installed
3. Connect the VSDSquadron mini board via USB
4. Select the correct environment (e.g., `vsdsquadronMini`)
5. Build the project:
PlatformIO: Build

6. Flash the firmware:
PlatformIO: Upload

7. Open the serial monitor:
PlatformIO: Monitor


---

## UART Settings

- **Baud rate:** 115200  
- **Data bits:** 8  
- **Parity:** None  
- **Stop bits:** 1  
- **Port:** CH32 USB-UART

---

## PWM Implementation Approach

PWM was implemented using a software-based technique driven by the TIM2 update interrupt.

<ins>Configuration Details:</ins>

Timer Used: TIM2

Mode: Update interrupt mode

PWM Type: Software PWM

Output Pin: PC6

Port: GPIOC

Pin Mode: Output Push-Pull

Instead of using hardware timer output channels, PWM duty control was achieved by:

Generating periodic interrupts using TIM2.

Maintaining a software counter (0–99).

Comparing the counter with duty value.

Manually setting/resetting PC6 inside the interrupt handler.

This creates a 0–100% duty cycle PWM signal fully controlled in firmware.

---

## Mode Commands (How to Demonstrate)

| Command | Description |
|------|------------|
| `h`  | Show help menu |
| `m0` | LED OFF |
| `m1` | LED ON |
| `m2` | LED blink (500 ms) |
| `m3` | LED fast blink (100 ms) |
| `m4` | LED breathing (PWM) |
| `m5` | LED pattern sequence |
| `m6` | Reaction-time game |
| `s`  | Show current mode |

---

## Game Demo

1. Type:
m6

2. Wait for the LED to turn ON  
3. Press any key on the terminal  
4. Reaction time is printed on UART  
5. System automatically returns to OFF mode  

---
