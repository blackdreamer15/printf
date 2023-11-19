#include "main.h"

/**
 * print_str - writes the string to stdout
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: On success 1.
 */
int print_str(va_list args, char *buffer, unsigned int buffer_len)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			buffer_len = handle_buffer(buffer, nill[i], buffer_len);
		return (6);
	}
	for (i = 0; str[i]; i++)
		buffer_len = handle_buffer(buffer, str[i], buffer_len);
	return (i);
}

/**
 * print_x_string - prints a string and values of
 * non-printed chars
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed
 */
int print_x_string(va_list args, char *buffer, unsigned int buffer_len)
{
	unsigned char *str;
	char *hexadecimal, *binary;
	unsigned int i, sum, op;

	str = va_arg(args, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buffer_len = handle_buffer(buffer, '\\', buffer_len);
			buffer_len = handle_buffer(buffer, 'x', buffer_len);
			op = str[i];
			binary = binary_converter(binary, op, 0, 32);
			hexadecimal = hex_converter(binary, hexadecimal, 1, 8);
			buffer_len = handle_buffer(buffer, hexadecimal[6], buffer_len);
			buffer_len = handle_buffer(buffer, hexadecimal[7], buffer_len);
			sum += 3;
		}
		else
			buffer_len = handle_buffer(buffer, str[i], buffer_len);
	}
	free(binary);
	free(hexadecimal);
	return (i + sum);
}

/**
 * print_rev_string - writes the str in reverse
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed.
 */
int print_rev_string(va_list args, char *buffer, unsigned int buffer_len)
{
	char *str;
	unsigned int i;
	int j = 0;
	char nill[] = "(llun)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			buffer_len = handle_buffer(buffer, nill[i], buffer_len);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		buffer_len = handle_buffer(buffer, str[j], buffer_len);
	}
	return (i);
}

/**
 * print_rot13 - writes the str in ROT13
 * @args: input string
 * @buffer: buffer pointer
 * @buffer_len: index for buffer pointer
 * Return: number of chars printed.
 */

int print_rot13(va_list args, char *buffer, unsigned int buffer_len)
{
	char alf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nill[] = "(avyy)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			buffer_len = handle_buffer(buffer, nill[i], buffer_len);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alf[j]; j++)
		{
			if (str[i] == alf[j])
			{
				k = 1;
				buffer_len = handle_buffer(buffer, rot[j], buffer_len);
				break;
			}
		}
		if (k == 0)
			buffer_len = handle_buffer(buffer, str[i], buffer_len);
	}
	return (i);
}
