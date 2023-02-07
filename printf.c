#include "printf.h"
#include <stdlib.h>

/**
 * _printf - Produce output according to a format
 * @format: format string
 *
 * Return: On success, the number of characters printed is returned.
 * On error, exit() is called which causes normal process termination.
 */
int _printf(const char *format, ...)
{
	int (*fn)(va_list);
	va_list ap;
	int nbytes = 0;

	va_start(ap, format);
	for (; *format; ++format) {
		/* print ordinary characters as is */
		if (*format != '%') {
			nbytes += _putchar(*format);
			continue;
		}
		fn = get_fmt_func(*++format);
		if (!fn) {
			_puts("Error: Unknown format specifier.");
			exit(98);
		}
		nbytes += (*fn)(ap);
	}
	va_end(ap);
	return nbytes;
}
