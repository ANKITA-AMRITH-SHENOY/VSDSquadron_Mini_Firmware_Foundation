# Task-3 - Peripheral Driver Library Development (Timer) + Application Demo

## Overview

This task focuses on developing a **Timer peripheral driver library** and demonstrating its usage through a simple application. The timer is implemented as a **software-based millisecond timer**, designed to be simple and portable.The application periodically generates timestamps using the timer and displays them over UART.

The main objective is to show **clean driver–application separation**, correct API design, and successful integration on the target MCU.

---

## What is Implemented

### Timer Driver (`timer.c` / `timer.h`)

* A software-based timer that provides millisecond resolution
* Public APIs:

  * `timer_init()` – initializes the timer module
  * `timer_delay_ms(uint32_t ms)` – creates a blocking delay in milliseconds
  * `timer_get_ms()` – returns elapsed time in milliseconds
* The timer logic is independent of UART and GPIO, following good driver design practices

### Application (`main.c`)

* Initializes the timer and UART
* Periodically waits for 1000 ms using the timer driver
* Prints the current timestamp in milliseconds
* Demonstrates correct usage of the timer library without accessing timer internals

---

## GPIO Pins Used (Demo Purpose Only)

| Pin | Function   | Reason                                                           |
| --- | ---------- | ---------------------------------------------------------------- |
| PD6 | LED Output | Used as a simple visual indicator during development and testing |

> **Note:** GPIO is used only as a supporting peripheral for demonstration and is not part of the core Task-3.

---

## UART Configuration

* **UART Peripheral:** USART1
* **Baud Rate:** 9600 bps
* **TX Pin:** PD5
* **RX Pin:** Not used (printing only)

### UART Message Format

The application prints periodic timestamp messages in the following format:

```
Task-3 Timer Demo Started
Timestamp(ms): 0
Timestamp(ms): 1000
Timestamp(ms): 2000
Timestamp(ms): 3000
...
```

Each message represents the elapsed time in milliseconds, obtained from the timer driver.

---

## How to Build and Flash

1. Open the project in **VS Code with PlatformIO installed**
2. Ensure the correct environment is selected (same as Task-2 framework)
3. Connect the CH32V003 board via WCH-Link
4. Build the project:

   ```
   PlatformIO: Build
   ```
5. Upload the firmware:

   ```
   PlatformIO: Upload
   ```
6. Open the serial monitor:

   ```
   PlatformIO: Monitor (9600 baud)
   ```

---

## How Correct Behavior Was Verified

* The timer functionality was verified by observing **incrementing timestamps** printed at regular 1-second intervals over UART
* The millisecond counter increases consistently, confirming correct delay and time tracking
* The application uses only the public timer APIs, validating proper driver abstraction
* Additional verification was done using the debugger by observing the timer tick variable during execution

---

## Conclusion

This task successfully demonstrates the development of a Timer peripheral driver and its integration into an application. The design follows good embedded software practices, including modularity, clean APIs, and separation between driver and application logic. UART output provides clear evidence of correct timer operation.

