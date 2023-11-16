#include "main.h"

/**
 * print_rot13 - encodes a string using rot13
 * @args: list of arguments
 * Return: number of arguments printed
 */
int print_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	int i, j, len = 0;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
		return (-1);

	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alpha[j])
			{
				write(1, &rot13[j], 1);
				break;
			}
		}
		if (j == 52)
			write(1, &str[i], 1);
	}
	return (len);
}
