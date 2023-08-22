#include "main.h"

/**
 * print_cat - Prints a character.
 * @c: The character to print.
 *
 * Return: Always 1 (Success).
 */
int print_cat(va_list cat)
{
    char character = (char)va_arg(cat, int);

    _putchar(character);
    return (1);
}
