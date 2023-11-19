#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/**
 * struct fmt_func - struct fmt_func
 * @fmt_char: format_specifier
 * @func: pointer to function that handles a specific format specifier
 * Description: struct for format specifier and their functions
 */
typedef struct fmt_func
{
	char *fmt_char;
	int (*func)(va_list, char *, unsigned int);
} fmt_func_t;

/* MAIN FUNCTION */
int _printf(const char *format, ...);

/* BUFFER HANDLING FUNCTIONS */
unsigned int handle_buffer(char *buffer, char c, unsigned int buffer_len);
int print_buffer(char *buffer, unsigned int buffer_len);

/* BASE CONVERSIONS */
char *binary_converter(char *binary_val, long int num, int is_neg, int limit);
int print_binary(va_list args, char *buffer, unsigned int buffer_len);

char *octal_converter(char *bin_val, char *oct_val);
char *short_octal_converter(char *bin_val, char *oct_val);
char *long_octal_converter(char *bin_val, char *oct_val);
int print_octal(va_list args, char *buffer, unsigned int buffer_len);
int print_short_octal(va_list args, char *buffer, unsigned int buffer_len);
int print_long_octal(va_list args, char *buffer,
unsigned int buffer_len);
int print_oct_with_leading_zero(va_list args, char *buffer,
unsigned int buffer_len);

char *hex_converter(char *bin_val, char *hex_val, int is_upper, int limit);
int print_hex(va_list args, char *buffer, unsigned int buffer_len);
int print_short_hex(va_list args, char *buffer, unsigned int buffer_len);
int print_long_hex(va_list args, char *buffer, unsigned int buffer_len);
int print_upper_hex(va_list args, char *buffer, unsigned int buffer_len);
int print_num_upper_hex(va_list args, char *buffer, unsigned int buffer_len);
int print_short_upper_hex(va_list args, char *buffer, unsigned int buffer_len);
int print_long_upper_hex(va_list args, char *buffer,
unsigned int buffer_len);
int print_hex_with_leading_zero(va_list args, char *buffer,
unsigned int buffer_len);

/* FORMAT FUNCTION SELECTOR */
int (*func_finder(const char *fmt, int index))(va_list, char *, unsigned int);
int fmt_specifier_counter(const char *fmt, int index);

/* FORMAT FUNCTIONS */
int print_char(va_list args, char *buffer, unsigned int buffer_len);
int print_percent(__attribute__((unused)) va_list, char *, unsigned int);

int print_int(va_list args, char *buffer, unsigned int buffer_len);
int print_short_int(va_list args, char *buffer, unsigned int buffer_len);
int print_long_int(va_list args, char *buffer, unsigned int buffer_len);
int print_int_with_symb(va_list args, char *buffer, unsigned int buffer_len);
int print_int_with_space(va_list args, char *buffer, unsigned int buffer_len);

int print_unsigned_int(va_list args, char *buffer,
unsigned int buffer_len);
int print_long_unsigned_int(va_list args, char *buffer,
unsigned int buffer_len);
int print_short_unsigned_int(va_list args, char *buffer,
unsigned int buffer_len);

int print_str(va_list args, char *buffer, unsigned int buffer_len);
int print_rot13(va_list args, char *buffer, unsigned int buffer_len);
int print_rev_string(va_list args, char *buffer, unsigned int buffer_len);
int print_x_string(va_list args, char *buffer, unsigned int buffer_len);

int print_address(va_list args, char *buffer, unsigned int buffer_len);

#endif
