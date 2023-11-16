#include "main.h"

/**
 * its - converts integer to string
 * @num: number to be converted
 *
 * Return: pointer to array
 */
char *its(int num)
{
	int num_size;
	char *num_arr;

	num_size = snprintf(NULL, 0, "%d", num);
	num_arr = malloc(num_size + 1);
	if (!num_arr)
		return (NULL);
	snprintf(num_arr, num_size + 1, "%d", num);
	return (num_arr);
}

/**
 * _binary - converts number to binary
 * @value: value to be converted
 *
 * Return: pointer to dynamically
 * allocated array
 */
char *_binary(unsigned int value)
{
	int i;
	char *arr = malloc(8);

	if (!arr)
		return (NULL);
	arr[7] = '\0';
	for (i = 6; i >= 0; i--)
	{
		int bit = value & 1;

		arr[i] = bit + '0';
		value >>= 1;
	}
	return (arr);
}

/**
 * _hex - converts number to hexadecimal
 * @value: value to be converted
 * Return: pointer to dynamically allocated array
 */
char *_hex(unsigned int value)
{
	int i;
	char *arr = malloc(8);

	if (!arr)
		return (NULL);
	arr[7] = '\0';
	for (i = 6; i >= 0; i--)
	{
		int bit = value & 15;

		if (bit < 10)
			arr[i] = bit + '0';
		else
			arr[i] = bit + 'W';
		value >>= 4;
	}
	return (arr);
}
