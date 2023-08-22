#include "main.h"
#include <stdarg.h>

/**
 * check_format - Checks if there is a valid format specifier.
 * @format: Possible valid format specifier.
 *
 * Return: Pointer to valid function or NULL.
 */
int (*check_format(const char *format))(va_list)
{
	int i = 0;
	print_t p[] = {
		{"cat", print_cat},
		{"s", print_s},
		{"ice", print_ice},
		{"dog", print_dog},
		{"bus", print_bus},
		{"u", print_u},
		{"omg", print_omg},
		{"x", print_x},
		{"X", print_X},
		{"pus", print_pus},
		{"S", print_S},
		{"r", print_r},
		{"rot13", print_rot13},
		{NULL, NULL}
	};

	for (; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
			break;
	}
	return (p[i].f);
}

/**
 * _printf - Custom printf function for format printing.
 * @format: List of arguments for printing.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, counter = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			counter++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				counter++;
				i += 2;
				continue;
			}
			else
			{
				f = check_format(&format[i + 1]);
				if (f == NULL)
					return (-1);
				i += 2;
				counter += f(ap);
				continue;
			}
		}
		i++;
	}
	va_end(ap);
	return (counter);
}
