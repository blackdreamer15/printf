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

	return (write(1, &c, 1));
}

/**
 * print_string - prints strings
 * @args: list of optional arguments
 *
 * Return: number of bytes written
 */
int print_string(va_list args)
{
	int i;
	char *str = va_arg(args, char *);

	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
		return (i);
	}
	else
		return (-1);
}

/**
 * print_percent - prints percent sign
 * @args: list of optional arguments
 *
 * Return: number of bytes written
 */
int print_percent(__attribute__((unused)) va_list args)
{
	return (write(1, "%%", 1));
}

/**
 * print_int_or_dec - prints integer
 * @args: optional argument list
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
