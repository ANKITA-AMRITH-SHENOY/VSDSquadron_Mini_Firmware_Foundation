#ifndef UART_H
#define UART_H

#include "ch32v00x.h"

void uart_init(uint32_t baudrate);
void uart_send_char(char ch);
void uart_send_string(const char* str);

#endif

