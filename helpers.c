#include "main.h"

/**
 * reverse_str - reverses a string in place
 * @args: list of arguments
 * Return: pointer to char
 */
char reverse_str(char *s)
{
	int i, len;
	char *tmp, *dest;

	len = strlen(s);

	dest = malloc(sizeof(char ) * (len + 1));

	if (dest == NULL)
		return (NULL);

	memcpy(dest, s, len);

	for (i = 0; i < len; i++)
	{
		tmp = dest[len - 1];
		dest[len - 1] = dest[i];
		dest[i] = tmp;
	}

	return dest;
}
