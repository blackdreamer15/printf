#include "main.h"

/**
 * reverse_str - reverses a string in place
 * @s: string to be reversed
 * Return: pointer to reversed string
 */
char *reverse_str(char *s)
{
	int i, len;
	char *tmp, *dest;

	len = strlen(s);

	dest = malloc(sizeof(char) * (len + 1));

	if (dest == NULL)
		return (NULL);

	memcpy(dest, s, len);

	for (i = 0; i < len; i++)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[i];
		dest[i] = tmp;
	}

	return (dest);
}

/**
 * write_base - print characters to stdout
 * @str: string to be parsed
 * Return: void
 */
void write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(1, str[i], 1);
}

/**
 * base_len - finds length of a number in a given base
 * @num: number to be converted
 * @base: base to convert to
 * Return: length of number
 */
unsigned int base_len(unsigned int num, unsigned int base)
{
	unsigned int len;

	for (len = 0; num > 0; len++)
		num /= base;

	return (len);
}
