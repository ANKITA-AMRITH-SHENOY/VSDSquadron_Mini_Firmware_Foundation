# VSDSquadron Mini Firmware Foundation (Task 1)

## **What is a Firmware Library?**

A firmware library is a collection of code (functions + source files) that runs on or simulates embedded hardware such as `gpio.c` ,` gpio.h`.

This is a firmware library because:
1. It contains implementations ```gpio.c```
2. It interacts with (or simulates) hardware
3. It is used by application code ```main.c```

Example:
```
void gpio_init(int pin, int direction);
void gpio_write(int pin, int value);
int gpio_read(int pin);
```

---

## **What is an API?**

An API (Application Programming Interface) is the interface — the functions that are exposed for others to use. Such as:
```
gpio_init()
gpio_write()
gpio_read()
```

These function declarations in `gpio.h` form the API.

The API tells:
-What functions are available

-What parameters they take

-What they return

**Note:API is part of the firmware library, but not the whole thing.**

---

## GPIO Function Overview

| Function        | Meaning                          |
|-----------------|----------------------------------|
| `gpio_init()`   | Decide switch type (input/output)|
| `gpio_write()`  | Turn switch ON or OFF            |
| `gpio_read()`   | Check if switch is ON or OFF     |

---

## Why APIs are important in Embedded Systems?

1. **Hardware abstraction** – APIs hide low-level register details and simplify hardware access.
2. **Code reusability** – Same API can be reused across multiple projects and platforms.
3. **Faster development** – Developers can use ready-made functions instead of writing low-level code.
4. **Improved portability** – Application code can run on different hardware with minimal changes.
5. **Easier maintenance** – Changes in hardware affect only the API, not the entire application code.

---

## GPIO behaviour code:

`gpio.c`

![GPIO-C](https://github.com/user-attachments/assets/ba88f1ed-fddc-4aa8-9c29-22891e598392)

`gpio.h`

![GPIO-H](https://github.com/user-attachments/assets/f66083b5-4f27-4370-b774-59348e74832f)

`main.c`

![GPIO- MAIN](https://github.com/user-attachments/assets/395728cf-8482-44f0-be44-ea943d5131b0)

---

## Conclusion from the Lab Code

- The lab code is a **simulation of GPIO firmware**, not real hardware control.
- `gpio.h` acts as an **interface file**, containing function declarations and GPIO direction macros.
- `gpio.c` contains the **implementation of GPIO functions**, simulating hardware behavior using `printf()`.
- `gpio_init()` is used to **configure a GPIO pin** as either INPUT or OUTPUT.
- `gpio_write()` simulates **writing a value (HIGH/LOW)** to an output GPIO pin.
- `gpio_read()` simulates **reading the value** from an input GPIO pin.
- `main.c` represents the **application layer**, which uses GPIO APIs without knowing internal details.
- The code demonstrates **API abstraction**, where application code is separated from hardware logic.
- This structure reflects how **real embedded systems organize firmware** using drivers and APIs.
- The lab helps understand the **basic working of GPIO and firmware design flow**.

## Program Output

![GPIO BEHAVIOUR -1st run and build](https://github.com/user-attachments/assets/60cb740d-ea43-4a46-bd1e-e4ab7331c743)



