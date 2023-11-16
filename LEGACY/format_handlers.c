#include "main.h"

/**
 * print_char - prints a character
 * @args: list of arguments
 * Return: number of characters printed.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_str - prints a string
 * @args: list of arguments
 * Return: number of characters printed.
 */
int print_string(va_list args)
{
	int len;
	char *str = va_arg(args, char *);

	if (str != NULL)
	{
		for (len = 0; str[len] != '\0'; len++)
			write(1, &str[len], 1);
		return (len);
	}
	return (-1);
}

/**
 * print_percent - prints the percentage symbol
 * @args: list of arguments
 * Return: number of characters printed.
 */
int print_percent(__attribute__((unused)) va_list args)
{
	return (write(1, "%%", 1));
}

/**
 * print_int - prints an integer
 * @args: list of arguments
 * Return: number of characters printed.
 */
int print_int(va_list args)
{
	int len;

	len = print_num(args);
	return (len);
}

/**
 * print_int_or_dec - prints integer
 * @arg: optional argument list
 *
 * Return: number of bytes written
 */
int print_int_or_dec(va_list args)
{
	int len;
	char *d = its(va_arg(args, int));

	if (d != NULL)
	{
		len = write(1, d, strlen(d));
		free(d);
	}
	else
		return (-1);
	return (len);
}
