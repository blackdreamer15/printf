#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @args: list of arguments
 * Return: number of arguments printed
 */
int rot13(va_list args)
{
	int i, j, len;
	char *str;
	char *rot13;

	str = va_arg(args, char *);

	if (str == NULL)
		return (-1);

	len = strlen(str);

	rot13 = malloc(sizeof(char) * (len + 1));

	if (rot13 == NULL)
		return (-1);

	for (i = 0; i < len; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'm') ||
			(str[i] >= 'A' && str[i] <= 'M'))
			rot13[i] = str[i] + 13;
		else if ((str[i] >= 'n' && str[i] <= 'z') ||
				 (str[i] >= 'N' && str[i] <= 'Z'))
			rot13[i] = str[i] - 13;
		else
			rot13[i] = str[i];
	}

	rot13[i] = '\0';

	j = write(1, rot13, len);

	free(rot13);

	return (j);
}
