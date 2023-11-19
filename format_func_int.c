#include "main.h"

/**
 * print_int - prints an integer
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed.
 */
int print_int(va_list args, char *buffer, unsigned int buffer_len)
{
	int int_input;
	unsigned int int_in, int_temp, i, div, isneg;

	int_input = va_arg(args, int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffer_len = handle_buffer(buffer, '-', buffer_len);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		buffer_len = handle_buffer(buffer, ((int_in / div) % 10) + '0', buffer_len);
	}
	return (i + isneg);
}

/**
 * print_short_int - prints a short integer
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed.
 */
int print_short_int(va_list args, char *buffer, unsigned int buffer_len)
{
	short int int_input;
	unsigned short int int_in, int_temp, i, div, isneg;

	int_input = va_arg(args, int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffer_len = handle_buffer(buffer, '-', buffer_len);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		buffer_len = handle_buffer(buffer, ((int_in / div) % 10) + '0', buffer_len);
	}
	return (i + isneg);
}

/**
 * print_long_int - prints a long integer
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed.
 */
int print_long_int(va_list args, char *buffer, unsigned int buffer_len)
{
	long int int_input;
	unsigned long int int_in, int_temp, i, div, isneg;

	int_input = va_arg(args, long int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffer_len = handle_buffer(buffer, '-', buffer_len);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		buffer_len = handle_buffer(buffer, ((int_in / div) % 10) + '0', buffer_len);
	}
	return (i + isneg);
}

/**
 * print_int_with_symb - print integer with plus symbol
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed
 */
int print_int_with_symb(va_list args, char *buffer, unsigned int buffer_len)
{
	int int_input;
	unsigned int int_in, int_temp, i, div;

	int_input = va_arg(args, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		buffer_len = handle_buffer(buffer, '-', buffer_len);
	}
	else
	{
		int_in = int_input;
		buffer_len = handle_buffer(buffer, '+', buffer_len);
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		buffer_len = handle_buffer(buffer, ((int_in / div) % 10) + '0', buffer_len);
	}
	return (i + 1);
}
