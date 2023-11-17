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

/**
 * print_x_string - prints exclusive strings
 * @args: list of optional arguments
 * Return: number of bytes written
 */
int print_x_string(va_list args)
{
	int i, len = 0, temp;
	char *str = va_arg(args, char *);

	if (str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 127 || str[i] < 32)
		{
			write(1, "\\x", 2);
			len += 2;
			temp = str[i];

			if (temp < 16)
			{
				write(1, "0", 1);
				len++;
			}
			len += HEX(temp);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
	}

	return (len);
}
