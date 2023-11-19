#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
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
	int (*f)(va_list, char *, unsigned int);
} fmt_func_t;

/* MAIN FUNCTION */
int _printf(const char *format, ...);

/* FORMAT FUNCTIONS */
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);

int print_chr(va_list args, char *buffer, unsigned int buffer_len);
int print_str(va_list args, char *buffer, unsigned int buffer_len);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_int(va_list args, char *buffer, unsigned int buffer_len);

int print_bnr(va_list args, char *buffer, unsigned int buffer_len);
int print_unt(va_list args, char *buffer, unsigned int buffer_len);
int print_hex(va_list args, char *buffer, unsigned int buffer_len);
int print_upx(va_list args, char *buffer, unsigned int buffer_len);
int print_oct(va_list args, char *buffer, unsigned int buffer_len);

int print_rot(va_list args, char *buffer, unsigned int buffer_len);
int print_rev(va_list args, char *buffer, unsigned int buffer_len);

int print_usr(va_list args, char *buffer, unsigned int buffer_len);
int print_add(va_list args, char *buffer, unsigned int buffer_len);
int prinlint(va_list args, char *buffer, unsigned int buffer_len);
int prinlunt(va_list args, char *buffer, unsigned int buffer_len);
int prinloct(va_list args, char *buffer, unsigned int buffer_len);
int prinlhex(va_list args, char *buffer, unsigned int buffer_len);
int prinlupx(va_list args, char *buffer, unsigned int buffer_len);
int prinhint(va_list args, char *buffer, unsigned int buffer_len);
int prinhunt(va_list args, char *buffer, unsigned int buffer_len);
int prinhoct(va_list args, char *buffer, unsigned int buffer_len);
int prinhhex(va_list args, char *buffer, unsigned int buffer_len);
int prinhupx(va_list args, char *buffer, unsigned int buffer_len);
int prinpint(va_list args, char *buffer, unsigned int buffer_len);
int prinnoct(va_list args, char *buffer, unsigned int buffer_len);
int prinnhex(va_list args, char *buffer, unsigned int buffer_len);
int prinnupx(va_list args, char *buffer, unsigned int buffer_len);
int prinsint(va_list args, char *buffer, unsigned int buffer_len);
unsigned int handl_buffer(char *buffer, char c, unsigned int buffer_len);
int print_buffer(char *buffer, unsigned int nbuffer);
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit);
char *fill_oct_array(char *bnr, char *oct);
char *fill_long_oct_array(char *bnr, char *oct);
char *fill_short_oct_array(char *bnr, char *oct);
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit);

#endif
