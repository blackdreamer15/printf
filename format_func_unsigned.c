#include "main.h"
/**
 * print_unsigned_int - prints an unsigned int
 * @args: number to print
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed.
 */
int print_unsigned_int(va_list args, char *buffer, unsigned int buffer_len)
{
	unsigned int int_in, int_temp, i, div;

	int_in = va_arg(args, unsigned int);
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
	return (i);
}

/**
 * print_short_unsigned_int - prints a short unsigned integer
 * @args: number to print
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed.
 */
int print_short_unsigned_int(va_list args, char *buffer,
							 unsigned int buffer_len)
{
	unsigned short int int_in, int_temp, i, div;

	int_in = va_arg(args, unsigned int);

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
	return (i);
}

/**
 * print_long_unsigned_int - prints a long unsigned integer
 * @args: number to print
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed.
 */
int print_long_unsigned_int(va_list args, char *buffer,
							unsigned int buffer_len)
{
	unsigned long int int_in, int_temp, i, div;

	int_in = va_arg(args, unsigned long int);
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
	return (i);
}

/**
 * print_int_with_space - prints int begining with space
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed
 */
int print_int_with_space(va_list args, char *buffer, unsigned int buffer_len)
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
		buffer_len = handle_buffer(buffer, ' ', buffer_len);
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
