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
 * @fields: pointer to a struct fields
 *
 * Return: The number of characters printed
 */
int print_S(va_list ap, const fields_t *fields)
{
	(void)fields;
	char *sval = va_arg(ap, char *);
	int len = 0, offset;

	for (; *sval; ++sval) {
		/* Convert non printable chars to hex */
		if (*sval > 0 && (*sval < 32 || *sval >= 127)) {
			_puts_without_newline("\\x");
			if (*sval <= 15)
				_putchar('0');
			offset = (*sval < 10) ? 0 : 'A' - ':';
			_putchar(*sval + '0' + offset);
			len += 4;
			continue;
		}
		len += _putchar(*sval);
	}
	return len;
}

/**
 * print_rev - Print a string, in reverse.
 * @ap: argument pointer
 * @fields: pointer to a struct fields
 *
 * Return: the number of characters printed
 */
int print_rev(va_list ap, const fields_t *fields)
{
	(void)fields;
	char *sp = va_arg(ap, char *);
	int len, i;

	len = i = _strlen(sp);
	while (i--)
		_putchar(*(sp + i));
	return len;
}

/**
 * print_rot13 - print the rot13'ed string
 * @ap: argument pointer
 * @fields: pointer to a struct fields
 *
 * Return: The number of characters printed
 */
int print_rot13(va_list ap, const fields_t *fields)
{
	(void)fields;
	const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const char mirror[]   = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	const char *sp = va_arg(ap, char *);
	unsigned int i, j, len = 0;

	for (i = 0; sp[i]; ++i) {
		for (j = 0; alphabet[j]; ++j) {
			if (alphabet[j] == sp[i]) {
				len += _putchar(mirror[j]);
				break;
			}
		}
	}
	return len;
}
