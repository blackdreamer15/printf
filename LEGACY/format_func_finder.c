#include "main.h"

/**
 * format_func_finder - finds the right function to
 *						print a given format specifier
 * @fmt: format string from _printf
 * @indx: index of current character in format string
 * @op_args: list of optional arguments passed from
 * variadic function
 *
 * Return: a pointer to function
 */
int format_func_finder(const char *fmt, int *indx, va_list op_args)
{
	int i;

	fmt_func_t arr[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int_or_dec},
		{'i', print_int_or_dec},
		{'u', print_unsigned},
		{'b', print_binary},
		{'x', print_hex},
		{'X', print_HEX},
		{'p', print_address},
		{'o', print_octal},
		{'S', print_x_string},
		{'r', print_rev_string},
		{'R', print_rot13},
		{'\0', NULL}};

	for (i = 0; arr[i].fmt_char != '\0'; i++)
	{
		if (arr[i].fmt_char == fmt[*indx])
			return (arr[i].func(op_args));
	}
	/*
	 *if (arr[i].fmt_char == '\0')
	 *	if (fmt[*indx] == '\0')
	 *		return (-1);
	 *return (-1);
	 */
	return (NULL);
}
