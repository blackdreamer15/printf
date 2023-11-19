#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, buffer_len = 0;
	va_list args;
	int (*funct)(va_list, char *, unsigned int);
	char *buffer = malloc(sizeof(char) * 1024);

	va_start(args, format);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				print_buffer(buffer, buffer_len), free(buffer), va_end(args);
				return (-1);
			}
			else
			{
				funct = fmt_func_finder(format, i + 1);
				if (funct == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handle_buffer(buffer, format[i], buffer_len), len++, i--;
				}
				else
				{
					len += funct(args, buffer, buffer_len);
					i += ev_print_func(format, i + 1);
				}
			}
			i++;
		}
		else
			handle_buffer(buffer, format[i], buffer_len), len++;
		for (buffer_len = len; buffer_len > 1024; buffer_len -= 1024)
			;
	}
	print_buffer(buffer, buffer_len), free(buffer), va_end(args);
	return (len);
}
