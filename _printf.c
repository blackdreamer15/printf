#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: string to be formatted
 *
 * Return: number of characters printed(excluding '\0').
 */
int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed = 0;
	formatter_t format_list[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_num},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_HEX},
		{'\0', NULL}};

	if (format == NULL)
		return (-1);

	va_start(args, format);

	chars_printed = handle_parsing(format, format_list, args);

	va_end(args);

	return (chars_printed);
}
