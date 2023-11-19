#include "main.h"

/**
 * print_char - writes characters to stdout
 * @args: input char
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: On success 1.
 */
int print_char(va_list args, char *buffer, unsigned int buffer_len)
{
	char c;

	c = va_arg(args, int);
	handle_buffer(buffer, c, buffer_len);

	return (1);
}

/**
 * print_percent - writes the percentage character to stdout
 * @args: input char
 * @buffer: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */
int print_percent(__attribute__((unused)) va_list args, char *buffer, unsigned int i)
{
	handle_buffer(buffer, '%', i);

	return (1);
}
