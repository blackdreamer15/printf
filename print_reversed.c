#include "main.h"

/**
 * print_reversed - prints a string in reverse
 * @args: list of arguments
 * Return: number of arguments printed
 */
int print_reversed(va_list args)
{
	int len;
	char *str;
	char *rev;

	str = va_arg(args, char *);

	if (str == NULL)
		return (-1);

	rev = reverse_str(str);
	len = write(1, rev, strlen(rev));

	free(rev);

	return (len);
}
