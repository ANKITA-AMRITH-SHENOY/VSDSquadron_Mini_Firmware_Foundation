# UART logs

![o1](https://github.com/user-attachments/assets/f437588f-754a-4c09-93b0-314b80f04894)
![o2](https://github.com/user-attachments/assets/e9c68104-c507-428c-8bd9-02ca5db18a28)
![o3](https://github.com/user-attachments/assets/6510c686-65f0-4fc4-8c7c-d59a76ec37e9)

---

# Hardware Proof
![pic](https://github.com/user-attachments/assets/bb2c1703-947c-41ea-9405-af3baa36925b)

https://github.com/user-attachments/assets/a4c2c00c-8fd0-49ab-8aa6-bd89410bc3f1

---

## Verification Notes

### What Was Tested
- UART command parsing and mode switching  
- GPIO output functionality using an external LED  
- Timer-based delays and blinking accuracy  
- PWM brightness control for breathing mode  
- Reaction-time measurement using UART input  

### What Worked
- All modes selectable without system reset  
- UART communication stable at 115200 baud  
- LED behavior matched the selected modes  
- Game mode correctly measured reaction time  

### Limitations
- Game mode uses UART key press instead of a physical button  
- Pattern sequence is fixed and not user-configurable  
- Single LED output used for simplicity  

---
