# UART-Controlled Mode Machine (Multi-Driver LED Application)

## Project Summary
This project implements a UART-controlled LED mode machine using the CH32V003 microcontroller.It is a command-driven embedded firmware developed on the VSDSquadron Mini board. It demonstrates the integration of multiple low-level drivers—GPIO, UART, Timer, and PWM—within a single application. The system allows a user to control LED behavior through UART commands, showcasing modular driver design, clear separation between hardware abstraction and application logic, and reliable peripheral interaction.The LED connected to GPIOC pin PC6 operates in multiple modes including ON, OFF, Blink, Fast Blink, Breathing (PWM), Pattern, and Reaction Game mode.

The system uses a timer-based architecture for non-blocking execution and interrupt-driven behavior.

## Target Hardware
- Board: VSDSquadron Mini

## Supported Drivers
- GPIO – LED output control  
- UART – serial command interface  
- Timer – delays and time measurement  
- PWM – LED brightness control  

## Folder Structure
![f1](https://github.com/user-attachments/assets/b96c356a-b7f1-42af-9a5c-e52e92ba5ed3)   ![f2](https://github.com/user-attachments/assets/a2ff9ec1-2bc7-473d-a833-37deb3fabda9)

---

# PWM Implementation

PWM is implemented using a software-based approach driven by the TIM2 update interrupt.

- Timer Used: TIM2
- PWM Type: Software PWM
- Output Port: GPIOC
- Output Pin: PC6
- Pin Mode: Output Push-Pull
- Duty Range: 0–100%

TIM2 generates periodic interrupts. Inside the interrupt service routine, a software counter (0–99) is compared with the duty cycle value. If the counter is less than the duty value, PC6 is set HIGH; otherwise, it is set LOW. This generates a PWM waveform with adjustable duty cycle.

The function pwm_set_duty(uint8_t duty) updates the duty cycle dynamically.

---

# Effect of Duty Cycle on LED Brightness

The duty cycle controls the percentage of time the LED remains ON within one PWM period.

- 0% duty → LED OFF
- 50% duty → Medium brightness
- 100% duty → Fully ON

Increasing the duty cycle increases LED brightness, while decreasing it reduces brightness.

---

# UART Configuration

- Peripheral: USART1
- Baud Rate: 115200
- Communication: Interrupt-driven receive
- Commands: m0–m6, h, s

---


## Quick Start
1. Build the firmware (PlatformIO)
2. Upload the firmware to the VSDSquadron Mini
3. Open the serial monitor at 115200 baud
4. Reset the board if required
5. Send UART commands to control the LED


