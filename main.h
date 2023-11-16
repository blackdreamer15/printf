#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

/* MAIN FUNCTION */
int _printf(const char *format, ...);

/* FORMAT FUNCTIONS */
int format_func_finder(const char *fmt, int *indx, va_list op_args);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int_or_dec(va_list args);
int print_unsigned(va_list args);
int print_binary(va_list args);
int print_hex(va_list args);
int print_rev_string(va_list args);
int print_rot13(va_list args);

/* HELPER FUNCTIONS */
char *its(int num);
char *_binary(unsigned int num);
char *_hex(unsigned int num);
int _putchar(char c);

#endif /* MAIN_H */
