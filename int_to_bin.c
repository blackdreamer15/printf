#include "main.h"

/**
 * _binary - converts integer to binary
 * @value: integer to be converted
 *
 * Return: pointer to dynamically allocated array
 */
char *_binary(int value)
{
	int i;
	char *arr = malloc(9);

	if (!arr)
		return (NULL);
	arr[8] = '\0';
	for (i = 7; i >= 0; i--)
	{
		int bit = value & 1;

		arr[i] = bit + '0';
		value >>= 1;
	}
	return (arr);
}
