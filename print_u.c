#include "main.h"
#include <stdlib.h>

/**
 * print_u - Prints an unsigned integer.
 * @u: An unsigned integer to print.
 *
 * Return: The number of printed digits.
 */
int print_u(va_list u)
{
	unsigned int a[10];
	unsigned int j = 1, m = 1000000000, n, sum = 0;
	int counter = 0;

	n = va_arg(u, unsigned int);
	a[0] = n / m;
	for (; j < 10; j++)
	{
		m /= 10;
		a[j] = (n / m) % 10;
	}
	for (j = 0; j < 10; j++)
	{
		sum += a[j];
		if (sum || j == 9)
		{
			_putchar('0' + a[j]);
			counter++;
		}
	}
	return (counter);
}
