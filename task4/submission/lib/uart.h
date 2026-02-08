#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init(uint32_t baud);
void uart_send_char(char c);
void uart_send_string(const char *s);

/* Blocking receive */
char uart_receive_char(void);

/* Non-blocking check */
uint8_t uart_char_available(void);

#endif

