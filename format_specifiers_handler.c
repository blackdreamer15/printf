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

/**
 * print_str - prints a string
 * @args: list of arguments
 * Return: number of characters printed.
 */
int print_str(va_list args)
{
	int len;
	char *str = va_arg(args, char *);

        if (str != NULL)
	{
		for (len = 0; str[i] != '\0'; len++)
			write(1, &str[len], 1);
		return (len);
	}
	return (-1);
}
