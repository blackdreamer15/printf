#include "main.h"

/**
 * format_handler - handles a particular format specifier
 * @fmt: format string from _printf
 * @indx: index of current character in format string
 * @op_args: list of optional arguments passed from
 * variadic function
 *
 * Return: a pointer to function
 */
int format_handler(const char *fmt, int *indx, va_list op_args)
{
	int i;

	fmt_func_t arr[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int_or_dec},
		{'i', print_int_or_dec},
		{'b', print_binary},
		{'\0', NULL}};

	for (i = 0; arr[i].fmt_char != '\0'; i++)
	{
		if (arr[i].fmt_char == fmt[*indx])
			return (arr[i].func(op_args));
	}
	if (arr[i].fmt_char == '\0')
		if (fmt[*indx] == '\0')
			return (-1);
	return (-1);
}
