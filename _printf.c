#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, chars_printed = 0;
	int flags;
	int width;
	int precision;
	int size;
	int buffer_len = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_len++] = format[i];
			if (buffer_len == BUFF_SIZE)
				print_buffer(buffer, &buffer_len);
			/* write(1, &format[i], 1);*/
			chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buffer_len);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
								   flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_printed += printed;
		}
	}

	print_buffer(buffer, &buffer_len);

	va_end(list);

	return (chars_printed);
}
