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

int get_matching_func(const char *format, formatter_t format_list[], va_list args);
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

#endif /*MAIN_H*/
