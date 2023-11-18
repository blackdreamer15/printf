#include "main.h"

/**
 * print_buffer - prints the buffer's content
 * @buffer: array of characters
 * @buffer_len: length of buffer or index for next char
 * Return: void
 */
void print_buffer(char buffer[], int *buffer_len)
{
	if (*buffer_len > 0)
		write(1, &buffer[0], *buffer_len);
	*buffer_len = 0;
}
