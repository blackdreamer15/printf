#include "main.h"

/**
 * print_num -prints the number passed as argument
 * @args: list of arguments
 * Return: number of arguments printed
 */
int print_num(va_list args)
{
	int n, divisor, len;
	unsigned int num;

	n = va_args(args, int);
	divisor = 1;
	len = 0;

	if (n > 0)
		num = n;
	else
	{
		len += write(1, '-', 1);
		num = n * -1;
	}

	while (num / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		len += write(1, '0' + num / divisor, 1);
		num %= divisor;
		divisor /= 10;
	}

	return (len);
}
