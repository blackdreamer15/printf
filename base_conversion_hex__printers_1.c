#include "main.h"
/**
 * print_short_upper_hex - prints a short decimal in uppercase hexadecimal
 * @args: The character to print
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: length of chars printed
 */
int print_short_upper_hex(va_list args, char *buffer, unsigned int buffer_len)
{
	char *hex_val, *bin_val;
	short int num = va_arg(args, int);
	short int is_neg = 0;
	short int i, len, first_digit;

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

	bin_val = malloc(sizeof(char) * (16 + 1));
	bin_val = binary_converter(bin_val, num, is_neg, 16);

	hex_val = malloc(sizeof(char) * (4 + 1));
	hex_val = hex_converter(bin_val, hex_val, 1, 4);

	for (first_digit = i = len = 0; hex_val[i]; i++)
	{
		if (hex_val[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			buffer_len = handle_buffer(buffer, hex_val[i], buffer_len);
			len++;
		}
	}

	free(bin_val);
	free(hex_val);

	return (len);
}

/**
 * print_long_upper_hex - prints a long decimal in uppercase hexadecimal
 * @args: The character to print
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: length of chars printed
 */
int print_long_upper_hex(va_list args, char *buffer, unsigned int buffer_len)
{
	char *hex_val, *bin_val;
	long int num = va_arg(args, long int);
	long int is_neg = 0;
	long int i, len, first_digit;

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

	bin_val = malloc(sizeof(char) * (64 + 1));
	bin_val = binary_converter(bin_val, num, is_neg, 64);

	hex_val = malloc(sizeof(char) * (16 + 1));
	hex_val = hex_converter(bin_val, hex_val, 1, 16);

	for (first_digit = i = len = 0; hex_val[i]; i++)
	{
		if (hex_val[i] != '0' && first_digit == 0)
			first_digit = 1;

		if (first_digit)
		{
			buffer_len = handle_buffer(buffer, hex_val[i], buffer_len);
			len++;
		}
	}
	free(bin_val);
	free(hex_val);

	return (len);
}

/**
 * print_num_upper_hex - prints number in uppercase hexadecimal
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: length of chars printed
 */
int print_num_upper_hex(va_list args, char *buffer, unsigned int buffer_len)
{
	char *hex_val, *bin_val;
	int num = va_arg(args, int);
	int is_neg = 0;
	int i, len, first_digit;

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

	buffer_len = handle_buffer(buffer, '0', buffer_len);
	buffer_len = handle_buffer(buffer, 'X', buffer_len);

	bin_val = malloc(sizeof(char) * (32 + 1));
	bin_val = binary_converter(bin_val, num, is_neg, 32);

	hex_val = malloc(sizeof(char) * (8 + 1));
	hex_val = hex_converter(bin_val, hex_val, 1, 8);

	for (first_digit = i = len = 0; hex_val[i]; i++)
	{
		if (hex_val[i] != '0' && first_digit == 0)
			first_digit = 1;

		if (first_digit)
		{
			buffer_len = handle_buffer(buffer, hex_val[i], buffer_len);
			len++;
		}
	}
	free(bin_val);
	free(hex_val);
	return (len + 2);
}

/**
 * print_upper_hex - prints a decimal in uppercase hexadecimal
 * @args: The character to print
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: length of chars printed
 */
int print_upper_hex(va_list args, char *buffer, unsigned int buffer_len)
{
	char *hex_val, *bin_val;
	int num = va_arg(args, int);
	int is_neg = 0;
	int i, len, first_digit;

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

	bin_val = malloc(sizeof(char) * (32 + 1));
	bin_val = binary_converter(bin_val, num, is_neg, 32);

	hex_val = malloc(sizeof(char) * (8 + 1));
	hex_val = hex_converter(bin_val, hex_val, 1, 8);

	for (first_digit = i = len = 0; hex_val[i]; i++)
	{
		if (hex_val[i] != '0' && first_digit == 0)
			first_digit = 1;

		if (first_digit)
		{
			buffer_len = handle_buffer(buffer, hex_val[i], buffer_len);
			len++;
		}
	}
	free(bin_val);
	free(hex_val);

	return (len);
}
