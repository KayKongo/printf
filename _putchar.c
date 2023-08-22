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
 * _printf - Custom printf function that handles 'c', 's', '%', 'd', and 'i'.
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
            } else if (*format == 'd' || *format == 'i') {
                // Integer specifier
                int num = va_arg(args, int); // Get the integer argument
                // Convert and print the integer digit by digit
                if (num < 0) {
                    _putchar('-');
                    count++;
                    num = -num;
                }
                if (num == 0) {
                    _putchar('0');
                    count++;
                } else {
                    int temp = num;
                    int num_of_digits = 0;
                    while (temp != 0) {
                        temp /= 10;
                        num_of_digits++;
                    }
                    while (num_of_digits > 0) {
                        int divisor = 1;
                        for (int i = 1; i < num_of_digits; i++) {
                            divisor *= 10;
                        }
                        int digit = num / divisor;
                        _putchar('0' + digit);
                        count++;
                        num %= divisor;
                        num_of_digits--;
                    }
                }
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
