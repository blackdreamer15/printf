#include "main.h"

/**
 * print_binary - prints int values
 * in their binary format
 * @arg: int to be printed
 *
 * Return: number of bytes written
 */
int print_binary(va_list arg)
{
    int len;
    char *bit = _binary(va_arg(arg, int));

    if (bit != NULL)
    {
        len = write(1, bit, strlen(bit));
        free(bit);
    }
    else
        return (-1);
    return (len);
}

/**
 * print_hex - converts from decimal to hexadecimal
 * @args: list of arguments
 * Return: length of number printed.
 */
int print_hex(va_list args)
{
    int len;
    char *hex = _hex(va_arg(args, int));

    if (hex != NULL)
    {
        len = write(1, hex, strlen(hex));
        free(hex);
    }
    else
        return (-1);
    return (len);
}