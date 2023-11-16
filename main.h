#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_int_or_dec(va_list arg);
int print_binary(va_list arg);
int format_handler(const char *fmt, int *indx, va_list op_args);
char *its(int num);
char *_binary(int value);

/**
 * struct fmt_func - Struct fmt_funct
 *
 * @fmt_char: format specifier
 * @func: pointer to function that handles a particular
 * specifier
 */
typedef struct fmt_func
{
	char fmt_char;
	int (*func)(va_list);
} fmt_func_t;

#endif
