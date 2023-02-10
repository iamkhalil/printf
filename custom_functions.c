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

/**
 * print_S - Print string and convert any non-printable characters to their hex value.
 * @ap: argument pointer
 *
 * Return: The number of characters written
 */
int print_S(va_list ap)
{
	char *sval = va_arg(ap, char *);
	unsigned int len = 0;

	for (; *sval; ++sval) {
		/* Convert non printable chars to hex */
		if (*sval > 0 && (*sval < 32 || *sval >= 127)) {
			_putchar('\\');
			_putchar('x');
			if (*sval <= 15)
				_putchar('0');
			print_hex(*sval, UPPERCASE);
			len += 4;
			continue;
		}
		len += _putchar(*sval);
	}
	return len;
}
