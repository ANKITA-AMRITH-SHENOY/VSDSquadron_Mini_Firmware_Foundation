# UART-Controlled Mode Machine (Multi-Driver LED Application)

## Project Summary
This project is a command-driven embedded firmware developed on the VSDSquadron Mini board. It demonstrates the integration of multiple low-level drivers—GPIO, UART, Timer, and PWM—within a single application. The system allows a user to control LED behavior through UART commands, showcasing modular driver design, clear separation between hardware abstraction and application logic, and reliable peripheral interaction.

## Target Hardware
- Board: VSDSquadron Mini

## Supported Drivers
- GPIO – LED output control  
- UART – serial command interface  
- Timer – delays and time measurement  
- PWM – LED brightness control  

## Folder Structure

![f1](https://github.com/user-attachments/assets/b96c356a-b7f1-42af-9a5c-e52e92ba5ed3) ![f2](https://github.com/user-attachments/assets/a2ff9ec1-2bc7-473d-a833-37deb3fabda9)

## Quick Start
1. Build the firmware (PlatformIO)
2. Upload the firmware to the VSDSquadron Mini
3. Open the serial monitor at 115200 baud
4. Reset the board if required
5. Send UART commands to control the LED


