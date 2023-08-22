#include "main.h"

/**
 * print_bus - Prints an unsigned integer in binary notation.
 * @b: The unsigned integer to print.
 *
 * Return: The number of printed digits.
 */
int print_bus(va_list bus)
{
    unsigned int n, m = 2147483648, j = 1, sum = 0;
    unsigned int a[32];
    int counter = 0;

    n = va_arg(bus, unsigned int);
    a[0] = n / m;

    for (; j < 32; j++)
    {
        m /= 2;
        a[j] = (n / m) % 2;
    }

    for (j = 0; j < 32; j++)
    {
        sum += a[j];
        if (sum || j == 31)
        {
            _putchar('0' + a[j]);
            counter++;
        }
    }

    return (counter);
}
