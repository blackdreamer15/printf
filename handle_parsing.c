#include "main.h"

/**
 * handle_parsing - takes a string and other params
 *		    to print a formatted string
 *
 * @format: string to be formatted
 * @format_list: List of all possible format-handling functions
 * @args: List of all arguments passed to the program
 *
 * Return: number of characters printed.
*/
int handle_parsing(char *format, formatter_t format_list[], va_list args)
{
	int i, j,val_return, chars_printed = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; format_list[j].symb != NULL; j++)
			{
				if (format[i + 1] == format_list[j].symb[0])
				{
					val_return  = format_list[j].func(args);
					
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
