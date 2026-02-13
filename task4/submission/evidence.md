# UART logs
![1](https://github.com/user-attachments/assets/50b53382-6ba1-4564-832e-d8fd794dc15b)

![2](https://github.com/user-attachments/assets/219220fe-741d-4366-8d97-e05f3ffea105)
![3](https://github.com/user-attachments/assets/d255b1c4-c15f-4b27-a3ff-d40544567468)

![4](https://github.com/user-attachments/assets/449236c9-4069-4f65-a7e4-2d78f4b1d163)
![5](https://github.com/user-attachments/assets/082fd03f-3b69-459f-8364-5dbc3040cd37)


---

# Hardware Proof
![pic](https://github.com/user-attachments/assets/bb2c1703-947c-41ea-9405-af3baa36925b)


https://github.com/user-attachments/assets/65cfc312-03a4-4d0c-8ab6-221bf24be283

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
