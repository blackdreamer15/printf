#include "main.h"

/**
 * print_binary - prints int values in their binary format
 * @args: list of arguments
 *
 * Return: number of bytes written
 */
int print_binary(va_list args)
{
	unsigned int bin = va_arg(args, unsigned int);
	unsigned int shifter[31];
	int len = 0;
	int i;

	if (!bin)
	{
		_putchar('0');
		len++;
	}
	else
	{
		while (bin)
		{
			shifter[i] = (bin % 2);
			bin /= 2;
			i++;
		}
		i--;

		while (i >= 0)
		{
			_putchar(shifter[i] + '0');
			len++;
			i--;
		}
	}

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
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
	return (len);
}

/**
 * print_HEX - prints hex values in uppercase
 * @args: list of arguments
 * Return: length of number printed.
 */
int print_HEX(va_list args)
{
	int i, len = 0;
	int *arr;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		len++;
	}
	len++;
	arr = malloc(sizeof(int) * len);

	for (i = 0; i < len; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 7;

		_putchar(arr[i] + '0');
	}
	free(arr);

	return (len);
}

/**
 * HEX - prints hex values in uppercase
 * @num: number to be printed
 * @casing: uppercase or lowercase
 * Return: length of number printed.
 */
int HEX(unsigned int num, char casing)
{
	int i, len = 0;
	int *arr;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		len++;
	}
	len++;
	arr = malloc(sizeof(int) * len);

	for (i = 0; i < len; i++)
	{
		arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
		{
			if (casing == 'X')
				arr[i] = arr[i] + 7;
			else
				arr[i] = arr[i] + 39;
		}

		_putchar(arr[i] + '0');
	}
	free(arr);

	return (len);
}

/**
 * print_octal - prints octal values
 * @args: list of arguments
 * Return: length of number printed.
 */
int print_octal(va_list args)
{
	int i, len = 0;
	int *arr;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		len++;
	}
	len++;
	arr = malloc(sizeof(int) * len);

	for (i = 0; i < len; i++)
	{
		arr[i] = temp % 8;
		temp /= 8;
	}
	for (i = len - 1; i >= 0; i--)
		_putchar(arr[i] + '0');

	free(arr);

	return (len);
}
