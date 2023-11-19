#include "main.h"
/**
 * func_finder - selects the correct function to perform the operation.
 * @fmt: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*func_finder(const char *fmt, int index))(va_list, char *, unsigned int)
{
	fmt_func_t arr[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_int},
		{"d", print_int},
		{"b", print_binary},
		{"u", print_unsigned_int},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_upper_hex},
		{"S", print_x_string},
		{"p", print_address},
		{"li", print_long_int},
		{"ld", print_long_int},
		{"lu", print_long_unsigned_int},
		{"lo", print_long_octal},
		{"lx", print_long_hex},
		{"lX", print_long_upper_hex},
		{"hi", print_short_int},
		{"hd", print_short_int},
		{"hu", print_short_unsigned_int},
		{"ho", print_short_octal},
		{"hx", print_short_hex},
		{"hX", print_short_upper_hex},
		{"#o", print_oct_with_leading_zero},
		{"#x", print_hex_with_leading_zero},
		{"#X", print_num_upper_hex},
		{"#i", print_int},
		{"#d", print_int},
		{"#u", print_unsigned_int},
		{"+i", print_int_with_symb},
		{"+d", print_int_with_symb},
		{"+u", print_unsigned_int},
		{"+o", print_octal},
		{"+x", print_hex},
		{"+X", print_upper_hex},
		{" i", print_int_with_space},
		{" d", print_int_with_space},
		{" u", print_unsigned_int},
		{" o", print_octal},
		{" x", print_hex},
		{" X", print_upper_hex},
		{"R", print_rot13},
		{"r", print_rev_string},
		{"%", print_percent},
		{"l", print_percent},
		{"h", print_percent},
		{" +i", print_int_with_symb},
		{" +d", print_int_with_symb},
		{"+ i", print_int_with_symb},
		{"+ d", print_int_with_symb},
		{" %", print_percent},
		{NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (arr[i].fmt_char)
	{
		if (fmt[index] == arr[i].fmt_char[j])
		{
			if (arr[i].fmt_char[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (arr[i].func);
}
