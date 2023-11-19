#include "main.h"
/**
 * octal_converter - writes the octal value to stdout
 * @bin_val: array storing the binary's value.
 * @oct_val: array storing the octal's value.
 * Return: array containing the binary value.
 */
char *octal_converter(char *bin_val, char *oct_val)
{
	int i;
	int j;
	int op;
	int limit;
	int oct_index;

	oct_val[11] = '\0';

	for (i = 31, oct_index = 10; i >= 0; i--, oct_index--)
	{
		if (i > 1)
			limit = 4;
		else
			limit = 2;

		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bin_val[i] - '0') * j) + op;

		i++;

		oct_val[oct_index] = op + '0';
	}

	return (oct_val);
}

/**
 * short_octal_converter - calculates a short octal number
 * @bin_val: array storing the binary's value.
 * @oct_val: array storing the octal's value.
 * Return: array containing the binary value.
 */
char *short_octal_converter(char *bin_val, char *oct_val)
{
	int i;
	int j;
	int op;
	int limit;
	int oct_index;

	oct_val[6] = '\0';

	for (i = 15, oct_index = 5; i >= 0; i--, oct_index--)
	{
		if (i > 0)
			limit = 4;
		else
			limit = 1;

		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bin_val[i] - '0') * j) + op;

		i++;

		oct_val[oct_index] = op + '0';
	}

	return (oct_val);
}

/**
 * long_octal_converter - calculates a long octal number
 * @bin_val: array storing the binary's value.
 * @oct_val: array storing the octal's value.
 * Return: array containing the binary value.
 */
char *long_octal_converter(char *bin_val, char *oct_val)
{
	int i;
	int j;
	int op;
	int limit;
	int oct_index;

	oct_val[22] = '\0';

	for (i = 63, oct_index = 21; i >= 0; i--, oct_index--)
	{
		if (i > 0)
			limit = 4;
		else
			limit = 1;

		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bin_val[i] - '0') * j) + op;

		i++;

		oct_val[oct_index] = op + '0';
	}

	return (oct_val);
}
