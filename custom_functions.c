#include "printf.h"

int print_binary(va_list ap)
{
	return print_binary_rec(va_arg(ap, int), 0);
}

int print_binary_rec(unsigned int x, unsigned int len)
{
	if (x > 1)
		len += print_binary_rec(x / 2, len);
	return len + _putchar((x % 2) + '0');
}
