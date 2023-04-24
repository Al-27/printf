#ifndef _PRINTF_H_
#define _PRINTF_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_str(char* string);
int str_len(char* string);

#endif
