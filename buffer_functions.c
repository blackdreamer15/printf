#include "main.h"

/**
 * print_buffer - prints buffer to stdout
 * @buffer: buffer pointer
 * @buffer_len: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buffer(char *buffer, unsigned int buffer_len)
{
	return (write(1, buffer, buffer_len));
}

/**
 * handle_buffer - concatenates the buffer characters
 * @buffer: buffer pointer
 * @c: character to concatenate
 * @buffer_len: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int handle_buffer(char *buffer, char c, unsigned int buffer_len)
{
	if (buffer_len == 1024)
	{
		print_buffer(buffer, buffer_len);
		buffer_len = 0;
	}
	buffer[buffer_len] = c;
	buffer_len++;
	return (buffer_len);
}
