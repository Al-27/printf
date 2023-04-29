#ifndef _PRINTF_H_
#define _PRINTF_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#include "std_funcs.h"
#include "output_funcs.h"
int _printf(const char *format, ...);
int print_str(char* string);
int printable_str(char* string);
int str_len(char* string);

#endif
