# VSDSquadron Mini – Task 2  
## Board Bring-Up, GPIO and UART Validation

### Overview
This task focuses on bringing up the VSDSquadron Mini RISC-V development board and validating basic hardware–software interaction. The firmware demonstrates successful board boot, UART communication, and GPIO control using a structured and beginner-friendly firmware design.

The implementation follows a layered approach, where GPIO functionality is abstracted into separate source files, similar to real-world embedded firmware practices.

---

### Board Bring-Up
- The firmware was successfully compiled and flashed onto the VSDSquadron Mini board.
- After flashing, the board boots correctly without errors.
- UART output is observed immediately after reset, confirming correct execution.

---

### UART Validation
UART is used as the primary debugging interface.

**UART configuration:**
- Peripheral: USART1
- Baud rate: 115200
- TX Pin: PD5
- RX Pin: PD6

**UART output includes:**
- Board identification message
- Periodic status messages printed continuously

More than 10 consecutive UART messages were observed on the serial terminal, confirming stable UART communication.

---

### GPIO Pin Mapping and Validation
A GPIO pin was selected from Port D and configured as an output to validate hardware-level GPIO control on the VSDSquadron Mini board.

**GPIO Pin Details:**
- Physical pin (board silkscreen): **PD6**
- MCU port: **GPIOD**
- MCU pin number: **6**
- MCU pin name: **PD6** (as per CH32V003 datasheet)
- Firmware GPIO definition: **LED_PIN = 6**
- Pin direction: **Output (Push-Pull)**

The pin was toggled periodically in firmware to demonstrate correct GPIO initialization and control. The GPIO number used in firmware matches the datasheet-defined pin mapping for the VSDSquadron Mini board.

The GPIO pin was configured as an output and toggled periodically in the firmware. The GPIO number used in the code directly matches the datasheet-defined pin mapping of the VSDSquadron Mini board.

The pin activity was verified using a visible LED indication on the physical board.

---

- `main.c` contains the main application logic.
- `gpio.c` and `gpio.h` implement GPIO abstraction functions.
- `uart.c` and `uart.h` handle UART initialization and transmission.

This structure improves readability and reflects standard embedded firmware design practices.

---


