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
	int (*fn)(va_list, const fields_t *);
	va_list ap;
	int nchars = 0;
	fields_t fields = { 0, 0, 0, 0, 0, 0 };

	va_start(ap, format);
	for (; *format; ++format) {
		/* print ordinary characters as is */
		if (*format != '%') {
			nchars += _putchar(*format);
			continue;
		}
		/* handle flags */
		while (update_flags(&fields, *++format))
			;
		/* handle width */
		format += update_width(&fields, ap, format);
		/* handle length modifiers */
		format += update_length_modifiers(&fields, *format);
		/* get specifier function */
		fn = get_fmt_func(*format);
		if (!fn) {
			_puts("Error: Unknown format specifier.");
			exit(98);
		}
		nchars += (*fn)(ap, &fields);
		reset_fields(&fields);
	}
	_putchar(FLUSHBUF); /* needed to flush the buffer used by _putchar */
	va_end(ap);
	return nchars;
}
