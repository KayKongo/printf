#include "main.h"
#include <stdlib.h>

/**
 * print_S - Prints a string and nonprintable character ASCII values.
 * @S: The string to print.
 *
 * Return: The number of printed characters.
 */
int print_S(va_list S)
{
    unsigned int i = 0;
    int counter = 0;
    char *str = va_arg(S, char *);

    if (str == NULL)
        str = "(null)";
    for (; str[i]; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            _putchar('\\');
            _putchar('x');
            counter += 2;
            counter += print_x(S);
        }
        else
        {
            _putchar(str[i]);
            counter++;
        }
    }
    return (counter);
}
