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

/**
 * print_hex - prints hex values in lowercase
 * @args: list of arguments
 * Return: length of number printed.
 */
int print_hex(va_list args)
{
	int i, len = 0;
	int *array;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		len++;
	}
	len++;
	array = malloc(sizeof(int) * len);

	for (i = 0; i < len; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	return (len);
}
