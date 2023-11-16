#include "main.h"

/**
 * print_binary - prints int values
 * in their binary format
 * @arg: int to be printed
 *
 * Return: number of bytes written
 */
int print_binary(va_list arg)
{
	int len;
	char *bit = _binary(va_arg(arg, int));

	if (bit != NULL)
	{
		len = write(1, bit, strlen(bit));
		free(bit);
	}
	else
		return (-1);
	return (len);
}
