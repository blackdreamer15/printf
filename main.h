#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct fmt_func - struct that stores a format specifier and a
 *					 function pointer to the corresponding function
 * @fmt_char: format specifier
 * @func: function pointer to corresponding function
 */
typedef struct fmt_func
{
	char fmt_char;
	int (*func)(va_list);
} fmt_func_t;

/* MAIN FUNCTIONS */
int _printf(const char *format, ...);

int format_handler(const char *fmt, int *indx, va_list op_args);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(__attribute__((unused)) va_list args);
int print_int_or_dec(va_list args);

/*
 * int print_num(va_list args);
 * int print_unsigned(va_list args);
 */

int print_binary(va_list args);
/**
* int print_octal(va_list args);
* int print_hex(va_list args);
* int print_HEX(va_list args);
*/

/*
 * int rot13(va_list args);
 * int print_reversed(va_list args);
 */

/* HELPER FUNCTIONS */
/*
 * char *reverse_str(char *s);
 * void write_base(char *str);
 * unsigned int base_len(unsigned int num, unsigned int base);
 */
char *its(int num);
char *_binary(int value);

#endif /* MAIN_H */
