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

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				chars_printed += 1;
				format++;

			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				write(1, str, strlen(str));
				chars_printed += strlen(str);
				format++;
			}
			else if (*format == '%')
			{
				char c = '%';

				write(1, &c, 1);
				chars_printed += 1;
				format++;
			}
		}
		else
		{
			write(1, format, 1);
			chars_printed += 1;
			format++;
		}
	}
	va_end(args);
	return (chars_printed);

}

