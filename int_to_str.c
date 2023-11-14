#include "main.h"

/**
 * its - converts integer to string
 * @: value to be converted
 *
 * Return: pointer to array storing
 * intgers that have been converted
 * to characters
 */
char *its(int num)
{
	int num_size;
	char *num_arr;

	num_size = (int)((ceil(log10(num))+1)*sizeof(char));
	num_arr = malloc(num_size);
	if (!num_arr)
		return (NULL);
	sprintf(num_arr, "%d", num);
	return (num_arr);
}
