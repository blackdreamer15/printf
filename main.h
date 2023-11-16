#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct formatter - struct containing format specifiers and functions
 * @symb: formt specifier
 * @func: function handling the operator
 */
typedef struct formatter
{
	char *symb;
	int (*func)(va_list);
} formatter_t;

/* MAIN FUNCTIONS */
int _printf(const char *format, ...);

int get_matching_func(const char *format, formatter_t format_list[],
						va_list args);
int print_char(va_list args);
int print_str(va_list args);
int print_percent(va_list args);
int print_int(va_list args);

int print_num(va_list args);
int print_unsigned(va_list args);

int print_binary(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);

int rot13(va_list args);
int print_reversed(va_list args);

/* HELPER FUNCTIONS */
char *reverse_str(char *s);
void write_base(char *str);
unsigned int base_len(unsigned int num, unsigned int base);

/*FROM GITHUB*/
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
