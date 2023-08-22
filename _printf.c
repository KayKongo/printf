#include <main.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to be written.
 * Return: On success, returns the character written. On error, returns -1.
 */
int _putchar(char c) {
    return write(1, &c, 1);
}

/**
 * _printf - Custom printf function that handles 'c', 's', and '%'.
 * @format: A format string with optional conversion specifiers.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && *format) {
        if (*format != '%') {
            // Regular character, print it to stdout using _putchar
            _putchar(*format);
            count++;
        } else {
            format++; // Move past '%'
            if (*format == 'c') {
                // Character specifier
                char c = va_arg(args, int); // Get the character argument
                _putchar(c);
                count++;
            } else if (*format == 's') {
                // String specifier
                char *str = va_arg(args, char *); // Get the string argument
                if (str == NULL)
                    str = "(null)";
                while (*str) {
                    _putchar(*str);
                    str++;
                    count++;
                }
            } else if (*format == '%') {
                // Percentage sign
                _putchar('%');
                count++;
            } else {
                // Unsupported specifier, just print the '%'
                _putchar('%');
                count++;
            }
        }
        format++;
    }

    va_end(args);

    return count;
}

