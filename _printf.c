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
	converter_t format_list[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'b', print_bin},
                {'u', unsigned_int},
                {'x', print_hex},
                {'X', print_hex},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(args, format);


	chars_printed = handle_parsing(format, format_list, args);
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				chars_printed += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str != NULL)
					chars_printed +=  write(1, str, strlen(str));
				else
					return (-1);
			}
			else if (*format == '%')
				chars_printed += write(1, format, 1);
			else if (*format == 'd' || *format == 'i')
			{
				char *c = its(va_arg(args, int));

				if (c != NULL)
				{
					chars_printed += write(1, c, strlen(c));
					free(c);
				}
			}
			else if (*format == 'b')
			{
				char *bit = _binary(va_arg(args, int));
				if (bit != NULL)
				{
					chars_printed += write(1, bit, strlen(bit));
					free(bit);
				}

	va_end(args);

	return (chars_printed);
}

