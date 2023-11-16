#include "main.h"

/**
 * _printf - produces output according to format
 * @format: format string
 *
 * Return: number of bytes written
 */
int _printf(const char *format, ...)
{
	int i, _printed, characters_printed = 0;

	va_list list;

	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			characters_printed++;
		}
		else
		{
			i++;
			_printed = format_handler(format, &i, list);
			if (_printed == -1)
				return (-1);
			characters_printed += _printed;
		}
	}
	va_end(list);
	return (characters_printed);
}
