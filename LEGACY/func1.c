#include "main.h"

/**
 * print_char - prints characters
 * @arg: list of optional arguments
 *
 * Return: number of bytes written
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	return (write(1, &c, 1));
}

/**
 * print_string - prints strings
 * @arg: list of optional arguments
 *
 * Return: number of bytes written
 */
int print_string(va_list arg)
{
	int i;
	char *str = va_arg(arg, char *);

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
 * @arg: list of optional arguments
 *
 * Return: number of bytes written
 */
int print_percent(va_list arg __attribute__((unused)))
{
	return (write(1, "%%", 1));
}

/**
 * print_int_or_dec - prints integer
 * @arg: optional argument list
 *
 * Return: number of bytes written
 */
int print_int_or_dec(va_list arg)
{
	int len;
	char *d = its(va_arg(arg, int));

	if (d != NULL)
	{
		len = write(1, d, strlen(d));
		free(d);
	}
	else
		return (-1);
	return (len);
}