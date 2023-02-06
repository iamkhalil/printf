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
	return print_unsigned_int_rec((unsigned int)va_arg(ap, int), 0);
}

int print_unsigned_int_rec(unsigned int ui, unsigned int len)
{
	if (ui > 10)
		len += print_unsigned_int_rec(ui / 10, len);
	return len + _putchar((ui % 10) + '0');
}

int print_octal(va_list ap)
{
	unsigned int *arr;
	unsigned int ui, tmp, ndigits, i;

	ui = tmp = (unsigned int) va_arg(ap, int);
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
