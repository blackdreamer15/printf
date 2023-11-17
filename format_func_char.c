#include "main.h"

/**
 * print_char - prints characters
 * @args: list of optional arguments
 *
 * Return: number of bytes written
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);

	return (1);
}

/**
 * print_percent - prints percent sign
 * @args: list of optional arguments
 *
 * Return:
 */
int print_percent()
{
	_putchar(37);

	return (1);
}
