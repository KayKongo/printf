#include "main.h"

/**
 * print_omg - Prints an unsigned integer in octal notation.
 * @omg: The unsigned integer to print.
 *
 * Return: The number of printed digits.
 */
int print_omg(va_list omg)
{
    unsigned int a[11];
    unsigned int j = 1, m = 1073741824, n, sum = 0;
    int counter = 0;

    n = va_arg(omg, unsigned int);
    a[0] = n / m;

    for (; j < 11; j++)
    {
        m /= 8;
        a[j] = (n / m) % 8;
    }

    for (j = 0; j < 11; j++)
    {
        sum += a[j];
        if (sum || j == 10)
        {
            _putchar('0' + a[j]);
            counter++;
        }
    }

    return (counter);
}
