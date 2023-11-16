#include "main.h"

/**
 * print_binary - converts from decimal to binary
 * @args: list of arguments
 * Return: length of number printed.
 */
int print_binary(va_list args)
{
	unsigned int num;
	int i, len;
	char *str, *rev_str;

	num = var(args, unsigned int);

	if (num == 0)
		return (write(1, '0', 1));
	if (num < 1)
		return (-1);

	len = base_len(num, 2);
	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num /= 2;
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
