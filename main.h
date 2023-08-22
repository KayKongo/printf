#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdio.h>

/**
 * struct print - Structure for handling various print types.
 * @t: Format specifier for the data type.
 * @f: Function pointer to the corresponding print function.
 */
typedef struct print
{
    char *t;
    int (*f)(va_list);
} print_t;

/**
 * _printf - Custom printf function with variable argument support.
 * @format: Format string containing directives.
 * @...: Additional arguments corresponding to format directives.
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...);

/**
 * _putchar - Writes a character to the standard output.
 * @c: The character to be written.
 *
 * Return: The character written as an unsigned char cast.
 */
int _putchar(char c);

/* Function prototypes for various print types */
int print_c(va_list c);
int print_s(va_list s);
int print_i(va_list i);
int print_d(va_list d);
int print_f(va_list f);
int print_e(va_list e);
int print_g(va_list g);
int print_l(va_list l);
int print_0(va_list zero);
int print_h(va_list h);
int print_u(va_list u);
int print_b(va_list b);
int print_o(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_p(va_list p);
int print_S(va_list S);
int print_r(va_list r);
int print_rot13(va_list rot13);
int print_add(va_list add);
int print_less(va_list less);
int print_space(va_list space);
int print_sharp(va_list sharp);

#endif /* _MAIN_H */
