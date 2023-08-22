#include "main.h"
#include <unistd.h>

/**
 * print_s - Prints a string.
 * @s: A va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_s(va_list s)
{
	char *str = va_arg(s, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
		_putchar(str[i++]);
	return (i);
}
