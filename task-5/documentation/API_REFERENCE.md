# API_REFERENCE.md — Driver API Documentation
The driver provides modular APIs for GPIO, PWM, Timer, and UART peripherals on CH32V00x microcontrollers. All functions follow a consistent initialization pattern and use hardware abstraction from ch32v00x.h.
​

# GPIO API
``` void gpio_init(void) ```
```c
/**
 * @brief Initialize GPIO for LED control on PC6
 * @param None
 * @return None
 * 
 * Initializes GPIOC clock and configures PC6 (LED_PIN) as push-pull output at 50MHz.
 * Must be called before any GPIO operations.
 * 
 * @note LED_PORT is GPIOC, LED_PIN is GPIO_Pin_6 (defined in gpio.h)
 * @note Call once during system startup
 * 
 * @example
 *   gpio_init();  // Ready for LED control
 */
```
```
void gpio_set_high(uint16_t pin)
```
```c
/**
 * @brief Set specified GPIO pin high
 * @param pin Pin mask (e.g., LED_PIN = GPIO_Pin_6)
 * @return None
 * 
 * Sets the specified pin on LED_PORT (GPIOC) to logic high.
 * 
 * @note Only works for pins configured by gpio_init()
 * @note Thread-safe, can be called from interrupts
 * 
 * @example
 *   gpio_set_high(LED_PIN);  // Turn LED on
 */
```
```
void gpio_set_low(uint16_t pin)
```
```c
/**
 * @brief Set specified GPIO pin low
 * @param pin Pin mask (e.g., LED_PIN = GPIO_Pin_6)
 * @return None
 * 
 * Sets the specified pin on LED_PORT (GPIOC) to logic low.
 * 
 * @note Only works for pins configured by gpio_init()
 * 
 * @example
 *   gpio_set_low(LED_PIN);  // Turn LED off
 */
```
```
void gpio_toggle(uint16_t pin)
```
```c
/**
 * @brief Toggle specified GPIO pin state
 * @param pin Pin mask (e.g., LED_PIN = GPIO_Pin_6)
 * @return None
 * 
 * Toggles the current state of the specified pin (high->low or low->high).
 * Reads current output state before toggling.
 * 
 * @note Only works for pins configured by gpio_init()
 * 
 * @example
 *   gpio_toggle(LED_PIN);  // Blink LED
 */
```

# PWM API
```
void pwm_init(void)
```
```c
/**
 * @brief Initialize software PWM on PC6 (~10kHz)
 * @param None
 * @return None
 * 
 * Configures TIM2 interrupt for 10kHz software PWM generation on LED_PIN.
 * Automatically calls gpio_init() internally. Resolution: 100 steps (0-100%).
 * 
 * @note Uses TIM2 (APB1), NVIC priority 2. Cannot use TIM2 for other purposes.
 * @note PWM frequency fixed at ~10kHz regardless of SystemCoreClock.
 * @note Call once during system startup before pwm_set_duty()
 * 
 * @example
 *   pwm_init();           // Start PWM engine
 *   pwm_set_duty(50);     // 50% duty cycle
 */
```
```
void pwm_set_duty(uint8_t duty_percent)
```
```c
/**
 * @brief Set PWM duty cycle
 * @param duty_percent Duty cycle 0-100 (0%=off, 100%=full on)
 * @return None
 * 
 * Updates PWM duty cycle percentage. Change takes effect immediately
 * in next TIM2 interrupt. Thread-safe.
 * 
 * @note Range: 0-100 only. Values outside range are clamped.
 * @note Requires pwm_init() first
 * 
 * @example
 *   pwm_set_duty(25);     // 25% brightness
 *   pwm_set_duty(0);      // LED off
 *   pwm_set_duty(100);    // LED full on
 */
```

# Timer API
```
void timer_init(uint32_t tick_hz)
```
```c
/**
 * @brief Initialize millisecond timer tick
 * @param tick_hz Desired tick frequency (e.g., 1000 = 1ms ticks)
 * @return None
 * 
 * Configures TIM1 for periodic interrupts at specified rate.
 * Provides tick_count, delay, and get_tick() functionality.
 * 
 * @note Uses TIM1 (APB2), NVIC priority 1. Period fixed at 1ms internally.
 * @note Prescaler auto-calculated: (SystemCoreClock/tick_hz/1000)-1
 * @note Call once during startup before any timer functions
 * 
 * @example
 *   timer_init(1000);     // 1ms resolution ticks
 */
```
```
void timer_delay_ms(uint32_t ms)
```
```c
/**
 * @brief Blocking delay in milliseconds
 * @param ms Milliseconds to delay
 * @return None
 * 
 * Busy-wait delay using tick_count. Non-interruptible.
 * 
 * @note Requires timer_init() first
 * @note Maximum delay ~4 seconds (32-bit overflow)
 * 
 * @example
 *   timer_delay_ms(500);  // Wait half second
 */
```
```
uint32_t timer_get_tick(void)
```
```c
/**
 * @brief Get current millisecond tick count
 * @param None
 * @return Current tick count (ms since timer_init)
 * 
 * Returns monotonically increasing tick counter.
 * 
 * @note Requires timer_init() first
 * @note 32-bit wraps around after ~49 days
 * 
 * @example
 *   uint32_t start = timer_get_tick();
 *   // do work
 *   uint32_t elapsed = timer_get_tick() - start;
 */
```

# UART API
```
void uart_init(uint32_t baud)
```
```c
/**
 * @brief Initialize UART1 (PD5-TX, PD6-RX)
 * @param baud Baud rate (e.g., 115200)
 * @return None
 * 
 * Configures USART1 at specified baud rate, 8N1. Enables TX (PD5 AF_PP),
 * RX (PD6 floating input).
 * 
 * @note Uses USART1, GPIOD. Standard pins: PD5=TX, PD6=RX
 * @note Common rates: 9600, 38400, 115200
 * @note Call once during startup
 * 
 * @example
 *   uart_init(115200);
 *   uart_send_string("Hello\r\n");
 */
```
```
void uart_send_char(char c)
```
```c
/**
 * @brief Send single character (blocking)
 * @param c Character to send
 * @return None
 * 
 * Blocks until TX register empty, then sends character.
 * 
 * @note Requires uart_init()
 * 
 * @example
 *   uart_send_char('A');
 */
```
```
void uart_send_string(const char *s)
```
```c
/**
 * @brief Send null-terminated string (blocking)
 * @param s String pointer
 * @return None
 * 
 * Sends characters until null terminator.
 * 
 * @note Requires uart_init()
 * 
 * @example
 *   uart_send_string("Status OK\r\n");
 */
```
```
char uart_receive_char(void)
```
```c
/**
 * @brief Blocking receive single character
 * @param None
 * @return Received character
 * 
 * Waits indefinitely for RX data.
 * 
 * @note Requires uart_init()
 * @warning Avoid in main loop - can hang forever
 * 
 * @example
 *   char c = uart_receive_char();
 */
```
```
uint8_t uart_char_available(void)
```
```
/**
 * @brief Check if receive data available (non-blocking)
 * @param None
 * @return 1 if data ready, 0 if empty
 * 
 * Tests RXNE flag without blocking.
 * 
 * @note Requires uart_init()
 * 
 * @example
 *   if (uart_char_available()) {
 *       char c = uart_receive_char();
 *   }
 */
```
