#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments
 * Return: number of characters printed.
 */
int print_char(va_list args)
{
	write(1, va_arg(args, int), 1);
	return (1);
}

