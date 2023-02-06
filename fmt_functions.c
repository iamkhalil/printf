#include "printf.h"

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
