#include "main.h"

/**
 * binary_converter - converts and prints decimal in binary
 * @binary_val: pointer to binary
 * @num: input number
 * @is_neg: if input number is negative
 * @limit: size of the binary
 * Return: number of chars printed.
 */
char *binary_converter(char *binary_val, long int num, int is_neg, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
		binary_val[i] = '0';
	binary_val[limit] = '\0';
	for (i = limit - 1; num > 1; i--)
	{
		if (num == 2)
			binary_val[i] = '0';
		else
			binary_val[i] = (num % 2) + '0';
		num /= 2;
	}
	if (num != 0)
		binary_val[i] = '1';
	if (is_neg)
	{
		for (i = 0; binary_val[i]; i++)
			if (binary_val[i] == '0')
				binary_val[i] = '1';
			else
				binary_val[i] = '0';
	}
	return (binary_val);
}

/**
 * print_binary - prints decimal in binary
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: length of chars printed.
 */
int print_binary(va_list args, char *buffer, unsigned int buffer_len)
{
	char *binary_val;
	int num = va_arg(args, int);
	int is_neg = 0;
	int len, i, digit;

	if (num == 0)
	{
		buffer_len = handle_buffer(buffer, '0', buffer_len);
		return (1);
	}
	if (num < 0)
	{
		num = (num * -1) - 1;
		is_neg = 1;
	}

	binary_val = malloc(sizeof(char) * (32 + 1));
	binary_val = binary_converter(binary_val, num, is_neg, 32);
	digit = 0;

	for (len = i = 0; binary_val[i]; i++)
	{
		if (digit == 0 && binary_val[i] == '1')
			digit = 1;
		if (digit == 1)
		{
			buffer_len = handle_buffer(buffer, binary_val[i], buffer_len);
			len++;
		}
	}

	free(binary_val);

	return (len);
}
