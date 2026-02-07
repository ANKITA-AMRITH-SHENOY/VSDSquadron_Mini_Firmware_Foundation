# UART Evidence

![output](https://github.com/user-attachments/assets/927f4ab5-9d1d-4a09-b83b-0283523dfc46)

---

# Hardware Evidence

https://github.com/user-attachments/assets/89e7aea5-8198-4b84-a3d5-03b5cb6a374e

---

# Explanation

## How the application uses the library?

In the Application / main.c description, we clearly state:

1. timer_init() is called once
2. timer_delay_ms(1000) is used for periodic timing
3. timer_get_ms() is used to fetch timestamps

This is exactly “how the application uses the library”.

---

## What was verified on hardware?

1. UART messages observed on serial monitor
2. Messages appear at regular 1-second (1000ms) intervals
3. Timestamp increments correctly
---
