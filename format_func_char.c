#include "main.h"

/**
 * print_char - prints characters
 * @args: list of optional arguments
 *
 * Return: Always 1 (Success)
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
 * Return: Always 1 (Success)
 */
int print_percent(va_list args __attribute__((unused)))
{
	_putchar(37);

	return (1);
}
