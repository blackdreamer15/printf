#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char *its(int num);
char *_binary(int value);

/**
 * struct converter - defines a struct data type for symbols and functions
 * @symb: operator
 * @func: function handling the operator*/
struct converter {
	char *symb;
	int (*func)(va_list);
}
typedef struct converter converter_t;

/* --- FUNCTIONS --- */
int handle_parsing(char *format, converter_t format_list[], va_list args);

int _printf(const char *format, ...);

#endif /*MAIN_H*/

