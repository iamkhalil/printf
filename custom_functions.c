#include "printf.h"

int print_binary(va_list ap, const fields_t *fields)
{
	(void)fields;
	return print_binary_rec(va_arg(ap, int), 0);
}

int print_binary_rec(unsigned int x, unsigned int len)
{
	if (x > 1)
		len += print_binary_rec(x / 2, len);
	return len + _putchar((x % 2) + '0');
}

/**
 * print_S - Print a string and convert any non-printable character to their
 * hexadecimal value.
 * @ap: argument pointer
 *
 * Return: The number of characters printed
 */
int print_S(va_list ap, const fields_t *fields)
{
	char *sval = va_arg(ap, char *);
	unsigned int len = 0;

	for (; *sval; ++sval) {
		/* Convert non printable chars to hex */
		if (*sval > 0 && (*sval < 32 || *sval >= 127)) {
			_puts_without_newline("\\x");
			if (*sval <= 15)
				_putchar('0');
			print_hex(*sval, 1, UPPERCASE, fields);
			len += 4;
			continue;
		}
		len += _putchar(*sval);
	}
	return len;
}
