#include "main.h"

/**
 * print_rev_string - prints a string in reverse
 * @args: list of arguments
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
	char *str = va_arg(args, char *);
	int i, len = 0;

	if (str == NULL)
	{
		str = "(null)";
		len = strlen(str);

		for (i = 0; i < len; i++)
			_putchar(str[i]);

		return (len);
	}

	len = strlen(str);

	for (i = 0; i < len; i++)
		_putchar(str[i]);

	return (len);
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
			len += HEX(temp, 'x');
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
	}

	return (len);
}

/**
 * print_rot13 - encodes a string using rot13
 * @args: list of arguments
 * Return: number of arguments printed
 */
int print_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	int i, j, len = 0;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		return (-1);

	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alpha[j])
			{
				write(1, &rot13[j], 1);
				break;
			}
		}
		if (j == 52)
			write(1, &str[i], 1);
	}
	return (len);
}
