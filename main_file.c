#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: string to be formatted
 *
 * Return: number of characters printed(excluding '\0').
 */
int _printf(const char * const format,...)
{
	int i, d, buffer_index, bytes;
	char *buffer;
	char *ptr;
	va_list args;

	va_start(args, format);
	i = 0;
	buffer_index = 0;
	buffer = malloc(1024);
	if (!buffer)
	{
		perror("Memory allocation failure");
		exit(EXIT_FAILURE);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				buffer[buffer_index] = c;
				buffer_index++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				while (*str != '\0') 
				{
					buffer[buffer_index] = *str;
					str++;
					buffer_index++;
				}
			}
			else if (format[i] == '%')
			{
				buffer[buffer_index] = '%';
				buffer_index++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				d = va_arg(args, int);
				ptr = its(d);
				while (*ptr != '\0')
				{
					buffer[buffer_index] = *ptr;
					ptr++;
					buffer_index++;
				}
				free(its(d));
			}
		}
		else
		{
			buffer[buffer_index] = format[i];
			buffer_index++;
		}
		i++;
	}

	buffer[buffer_index] = '\0';
	bytes = write(1, buffer, buffer_index);
	free(buffer);
	va_end(args);
	return (bytes);

}
