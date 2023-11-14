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

	num_size =  snprintf(NULL, 0, "%d", num);
	num_arr = malloc(num_size + 1);
	if (!num_arr)
		return (NULL);
	snprintf(num_arr, num_size + 1, "%d", num);
	return (num_arr);
}
