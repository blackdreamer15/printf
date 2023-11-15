#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
char *its(int num);
char *_binary(int value);

/**
 * struct converter - defines a struct data type for symbols and functions
 * @op: operator
 * @func: function handling the operator*/
typedef struct converter converter_t;

#endif /*MAIN_H*/

