#include "main.h"
/**
 * print_octal - prints decimal number in octal
 * @args: input number
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: length of chars printed.
 */
int print_octal(va_list args, char *buffer, unsigned int buffer_len)
{
	int is_neg = 0;
	int i, len, first_digit;
	int num = va_arg(args, int);
	char *octal_val, *binary_val;

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

	octal_val = malloc(sizeof(char) * (11 + 1));
	octal_val = fill_oct_array(binary_val, octal_val);

	for (first_digit = i = len = 0; octal_val[i]; i++)
	{
		if (octal_val[i] != '0' && first_digit == 0)
			first_digit = 1;

		if (first_digit)
		{
			buffer_len = handle_buffer(buffer, octal_val[i], buffer_len);
			len++;
		}
	}

	free(binary_val);
	free(octal_val);

	return (len);
}

/**
 * print_oct_with_leading_zero - print the number in octal begining with zero
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: length of chars printed
 */
int print_oct_with_leading_zero(va_list args, char *buffer,
								unsigned int buffer_len)
{
	char *octal_val, *binary_val;
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

	binary_val = malloc(sizeof(char) * (32 + 1));
	binary_val = binary_converter(binary_val, num, is_neg, 32);

	octal_val = malloc(sizeof(char) * (11 + 1));
	octal_val = fill_oct_array(binary_val, octal_val);

	for (first_digit = i = len = 0; octal_val[i]; i++)
	{
		if (octal_val[i] != '0' && first_digit == 0)
			first_digit = 1;

		if (first_digit)
		{
			buffer_len = handle_buffer(buffer, octal_val[i], buffer_len);
			len++;
		}
	}
	free(binary_val);
	free(octal_val);

	return (len + 1);
}

/**
 * print_short_octal - prints short decimal number in octal
 * @args: input number
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: length of chars printed.
 */
int print_short_octal(va_list args, char *buffer, unsigned int buffer_len)
{
	char *octal_val, *binary_val;
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

	binary_val = malloc(sizeof(char) * (16 + 1));
	binary_val = binary_converter(binary_val, num, is_neg, 16);

	octal_val = malloc(sizeof(char) * (6 + 1));
	octal_val = fill_short_oct_array(binary_val, octal_val);

	for (first_digit = i = len = 0; octal_val[i]; i++)
	{
		if (octal_val[i] != '0' && first_digit == 0)
			first_digit = 1;

		if (first_digit)
		{
			buffer_len = handle_buffer(buffer, octal_val[i], buffer_len);
			len++;
		}
	}
	free(binary_val);
	free(octal_val);

	return (len);
}

/**
 * print_long_octal - prints long decimal number in octal
 * @args: input number
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed.
 */
int print_long_octal(va_list args, char *buffer, unsigned int buffer_len)
{
	char *octal_val, *binary_val;
	short int num = va_arg(args, long int);
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

	binary_val = malloc(sizeof(char) * (64 + 1));
	binary_val = binary_converter(binary_val, num, is_neg, 64);

	octal_val = malloc(sizeof(char) * (22 + 1));
	octal_val = fill_long_oct_array(binary_val, octal_val);
	for (first_digit = i = len = 0; octal_val[i]; i++)
	{
		if (octal_val[i] != '0' && first_digit == 0)
			first_digit = 1;

		if (first_digit)
		{
			buffer_len = handle_buffer(buffer, octal_val[i], buffer_len);
			len++;
		}
	}
	free(binary_val);
	free(octal_val);

	return (len);
}
