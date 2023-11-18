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
int print_percent(__attribute__((unused)) va_list args);
int print_int_or_dec(va_list args);

int print_binary(va_list args);
int print_unsigned(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_octal(va_list args);

int print_rot13(va_list args);
int print_rev_string(va_list args);
int print_x_string(va_list args);
int HEX(unsigned int, char);

int print_address(va_list args);
/**
 * int print_unsigned(va_list args);
 * int print_binary(va_list args);
 * int print_hex(va_list args);
 * int print_HEX(va_list args);
 * int HEX(unsigned int, char);
 * int print_octal(va_list args);
 *
 * int print_x_string(va_list args);
 * int print_rev_string(va_list args);
 * int print_rot13(va_list args);
 *
 * int print_address(va_list args);
 */

/* HELPER FUNCTIONS */
int _putchar(char c);
char *its(int num);
char *_binary(unsigned int num);
/**
 * char *rev_string(char *s);
 */

#endif /* MAIN_H */
