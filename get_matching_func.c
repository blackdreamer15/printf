#include "main.h"

/**
 * get_matching_func - gets the matching function for the format specifier
 * @format: format specifier
 * @format_list: list of format specifiers and their corresponding functions
 * @args: list of arguments
 * Return: number of characters printed(excluding '\0').
 */
int get_matching_func(const char *format, formatter_t format_list[], va_list args)
{
	int i, j, val_return, chars_printed = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; format_list[j].symb != NULL; j++)
			{
				if (format[i + 1] == format_list[j].symb[0])
				{
					val_return = format_list[j].func(args);

					if (val_return == -1)
						return (-1);

					chars_printed += val_return;
					break;
				}
			}

			if (format_list[j].symb != NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					chars_printed += write(1, format[i], 1);
					chars_printed += write(1, format[i + 1], 1);
				}
				else
					return (-1);
			}
			i++; /*To skip the format specifier*/
		}

		else
			chars_printed += write(1, format[i], 1);
	}

	return (chars_printed);
}
