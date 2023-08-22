#include "main.h"
#include <stdlib.h>

/**
 * print_rot13 - Prints a string in ROT13 format.
 * @rot13: The string to print.
 *
 * Return: The number of printed characters.
 */
int print_rot13(va_list rot13)
{
    char *str;
    unsigned int i = 0, j = 0;
    int counter = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(rot13, char *);
    if (str == NULL)
        str = "(ahyy)";
    for (; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                _putchar(out[j]);
                counter++;
                break;
            }
        }
        if (!in[j])
        {
            _putchar(str[i]);
            counter++;
        }
    }
    return (counter);
}
