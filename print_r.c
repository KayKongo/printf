#include "main.h"
#include <stdlib.h>

/**
 * print_r - Prints a string in reverse.
 * @r: A va_list containing the string to print.
 *
 * Return: The number of printed characters.
 */
int print_r(va_list r)
{
	char *str;
	int i = 0, counter = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	while (str[i])
		i++;
	for (i -= 1; i >= 0; i--)
	{
		_putchar(str[i]);
		counter++;
	}
	return (counter);
}
