#include "main.h"

/**
 * print_unsigned - prints unsigned integer
 * @args: optional argument list
 * Return: number of bytes written
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, digit;
	int last_digit = n % 10;
	int expo = 1;
	int len = 0;

	n = n / 10;
	num = n;

	if (last_digit < 0)
	{
		last_digit = -last_digit;
		num = -num;
		n = -n;
		_putchar('-');
		len++;
	}

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			num = num / 10;
			expo = expo * 10;
		}
		num = n;
		while (expo > 0)
		{
			digit = num / expo;
			_putchar(digit + '0');
			len++;
			num = num - (digit * expo);
			expo = expo / 10;
		}
	}
	_putchar(last_digit + '0');

	return (len + 1);
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