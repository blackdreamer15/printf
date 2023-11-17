#include "main.h"

/**
 * print_address - prints address of a pointer
 * @args: list of arguments
 * Return: number of bytes written
 */
int print_address(va_list args)
{
	void *ptr;
	long int temp;
	int hex_len;

	ptr = va_arg(args, void *);

	if (ptr == NULL)
		return (-1);

	temp = (long int)ptr;

	_putchar('0');
	_putchar('x');

	hex_len = HEX(temp, 'x');

	return (hex_len + 2);
}
