#include "main.h"
/**
 * hex_converter - writes the hexadecimal value to stdout
 *
 * @bin_val: array storing the binary's value.
 * @hex_val: array storing the hexadecimal's value.
 * @is_upper: integer that determines if the hexadecimal
 *		   array is in uppercase or lowercase letter.
 * @limit: size of hex
 * Return: binary array.
 */
char *hex_converter(char *bin_val, char *hex_val, int is_upper, int limit)
{
	int op, i, j, to_char;

	hex_val[limit] = '\0';

	if (is_upper)
		to_char = 55;

	else
		to_char = 87;
	for (i = (limit * 4) - 1; i >= 0; i--)
	{
		for (op = 0, j = 1; j <= 8; j *= 2, i--)
			op = ((bin_val[i] - '0') * j) + op;

		i++;

		if (op < 10)
			hex_val[i / 4] = op + 48;

		else
			hex_val[i / 4] = op + to_char;
	}

	return (hex_val);
}
