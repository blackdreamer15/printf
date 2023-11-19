#include "main.h"

/**
 * print_address - prints the address of an input variable
 * @args: input address.
 * @buffer: buffer pointer.
 * @buffer_len: index for buffer pointer
 * Return: length of chars printed.
 */
int print_address(va_list args, char *buffer, unsigned int buffer_len)
{
	char *hex_val, *bin_val, null_arr[] = "(nil)";
	void *add = (va_arg(args, void *));
	int i, len, first_digit, is_neg = 0;
	long int num;

	if (add == NULL)
	{
		for (i = 0; null_arr[i]; i++)
			buffer_len = handle_buffer(buffer, null_arr[i], buffer_len);
		return (5);
	}

	num = (intptr_t)add;

	if (num < 0)
	{
		num = (num * -1) - 1;
		is_neg = 1;
	}
	bin_val = malloc(sizeof(char) * (64 + 1));
	bin_val = binary_converter(bin_val, num, is_neg, 64);
	hex_val = malloc(sizeof(char) * (16 + 1));
	hex_val = hex_converter(bin_val, hex_val, 0, 16);

	buffer_len = handle_buffer(buffer, '0', buffer_len);
	buffer_len = handle_buffer(buffer, 'x', buffer_len);

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
