#include "main.h"

/**
 * print_binary - converts from decimal to binary
 * @args: list of arguments
 * Return: length of number printed.
 */
int print_binary(va_list args)
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
 * print_octal - converts from decimal to octal
 * @args: list of arguments
 * Return: length of number printed.
 */
int print_octal(va_list args)
{
	unsigned int num;
	int i, len;
	char *str, *rev_str;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (write(1, '0', 1));
	if (num < 1)
		return (-1);

	len = base_len(num, 8);
	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		str[i] = (num % 8) + '0';
		num /= 8;
	}

	rev_str = reverse_str(str);

	if (rev_str == NULL)
	{
		free(str);
		return (-1);
	}

	write_base(rev_str);

	free(str);
	free(rev_str);

	return (len);
}

/**
 * print_hex - converts from decimal to hexadecimal
 * @args: list of arguments
 * Return: length of number printed.
 */
int print_hex(va_list args)
{
	unsigned int num;
	int i, len;
	char *str, *rev_str;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (write(1, '0', 1));
	if (num < 1)
		return (-1);

	len = base_len(num, 16);
	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if ((num % 16) < 10)
			str[i] = (num % 16) + '0';
		else
			str[i] = (num % 16) + 'W';
		num /= 16;
	}

	rev_str = reverse_str(str);

	if (rev_str == NULL)
	{
		free(str);
		return (-1);
	}

	write_base(rev_str);

	free(str);
	free(rev_str);

	return (len);
}

/**
 * print_HEX - converts from decimal to hexadecimal
 * @args: list of arguments
 * Return: length of number printed.
 */
int print_HEX(va_list args)
{
	unsigned int num;
	int i, len;
	char *str, *rev_str;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (write(1, '0', 1));
	if (num < 1)
		return (-1);

	len = base_len(num, 16);
	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if ((num % 16) < 10)
			str[i] = (num % 16) + '0';
		else
			str[i] = (num % 16) + '7';
		num /= 16;
	}

	rev_str = reverse_str(str);

	if (rev_str == NULL)
	{
		free(str);
		return (-1);
	}

	write_base(rev_str);

	free(str);
	free(rev_str);

	return (len);
}
