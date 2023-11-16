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

	while (num / div > 9)
		div *= 10;

	while (div != 0)
	{
		len += write(1, '0' + num / div , 1);
		num %= div;
		div /= 10;
	}

	return (len);
}

