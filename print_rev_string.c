#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: string to be reversed
 * Return: pointer to reversed string
 */
char *rev_string(char *s)
{
	int i, len;
	char temp;

	len = strlen(s);

	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}

	return (s);
}

/**
 * print_rev_string - prints a string in reverse
 * @arg: list of arguments
 * Return: number of bytes written
 */
int print_rev_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i, len = 0;

	if (str == NULL)
		return (-1);

	len = strlen(str);

	for (i = len - 1; i >= 0; i--)
		write(1, &str[i], 1);

	return (len);
}
