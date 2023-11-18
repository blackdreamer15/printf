#include "main.h"

/**
 * print_buffer - prints buffer
 * @buffer: pointer to buffer to print
 * @buffer_len: length of buffer
 * Return: number of bytes printed
 */
int print_buffer(char *buffer, unsigned int buffer_len)
{
	return (write(1, buffer, buffer_len));
}

/**
 * handle_buffer - handles buffer for _printf
 * @buffer: buffer to store string
 * @c: character to add to buffer
 * @buffer_len: length of buffer
 * Return: new length of buffer
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
