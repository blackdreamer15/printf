#include "main.h"

/**
 * print_rev_string - prints a string in reverse
 * @arg: list of arguments
 * Return: number of bytes written
 */
int print_rev_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i, len = 0;

	if (str == NULL)
		return (-1);

	len = strlen(str);

	for (i = len - 1; i >= 0; i--)
		write(1, &str[i], 1);

	return (len);
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
