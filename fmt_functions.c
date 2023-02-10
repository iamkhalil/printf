#include "printf.h"
#include <stdlib.h>

int print_char(va_list ap)
{
	return _putchar(va_arg(ap, int));
}

int print_string(va_list ap)
{
	char *sval;
	int len = 0;

	for (sval = va_arg(ap, char *); *sval; ++sval) {
		len += _putchar(*sval);
	}
	return len;
}

int print_int(va_list ap)
{
	int val = va_arg(ap, int);
	int tmp, divisor = 1, len = 0;

	if (val < 0) {
		len += _putchar('-');
		val = -val;
	}

	tmp = val;
	while (tmp / 10) {
		tmp /= 10;
		divisor *= 10;
	}

	while (divisor) {
		len += _putchar((val / divisor) + '0');
		val %= divisor;
		divisor /= 10;
	}
	return len;
}

int print_unsigned_int(va_list ap)
{
	return print_unsigned_int_rec(va_arg(ap, unsigned int), 0);
}

int print_unsigned_int_rec(unsigned int ui, unsigned int len)
{
	if (ui > 10)
		len += print_unsigned_int_rec(ui / 10, len);
	return len + _putchar((ui % 10) + '0');
}

//!TODO: Remove dynamic memory allocation
int print_octal(va_list ap)
{
	unsigned int *arr;
	unsigned int ui, tmp, ndigits, i;

	ui = tmp = va_arg(ap, unsigned int);
	ndigits = 1;
	while (tmp / 8) {
		tmp /= 8;
		++ndigits;
	}
	arr = malloc(sizeof(unsigned int) * ndigits);
	if (!arr) {
		_puts("Error: Failed to allocate memory.");
		exit(99);
	}
	for (i = 0; i < ndigits; ++i) {
		arr[i] = ui % 8;
		ui /= 8;
	}
	while (i--)
		_putchar(arr[i] + '0');
	free(arr);
	return ndigits;
}

int print_hex_uppercase(va_list ap)
{
	return print_hex(va_arg(ap, unsigned int), UPPERCASE);
}

int print_hex_lowercase(va_list ap)
{
	return print_hex(va_arg(ap, unsigned int), LOWERCASE);
}

int print_hex(unsigned int ui, short flag)
{
	char buffer[8]; /* UINT_MAX == FFFFFFFF */
	unsigned int i, padding, ndigits = 0;
	short is_trailing_zero = 1;

	padding = (flag & UPPERCASE) ? 'A' - ':' : 'a' - ':';
	for (i = 0; i < 8; ++i) {
		if (ui % 16 > 9)
			buffer[i] = (ui % 16) + padding + '0';
		else
			buffer[i] = (ui % 16) + '0';
		ui /= 16;
	}

	while (i--) {
		/* Skip trailing zeros */
		if (buffer[i] == '0' && is_trailing_zero)
			continue;
		is_trailing_zero = 0;
		ndigits += _putchar(buffer[i]);
	}
	return ndigits;
}
