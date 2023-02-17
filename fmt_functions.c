#include "printf.h"
#include <stdlib.h>

int print_char(va_list ap, const fields_t *fields)
{
	int i;

	for (i = 0; i < fields->width - 1; ++i)
		_putchar(' ');
	return i + _putchar(va_arg(ap, int));
}

int print_string(va_list ap, const fields_t *fields)
{
	char *sp = va_arg(ap, char *);
	int len;

	for (len = _strlen(sp); len < fields->width; ++len)
		_putchar(' ');
	while (*sp)
		_putchar(*sp++);
	return len;
}

int print_int(va_list ap, const fields_t *fields)
{
	long val;
	char sval[CAPACITY] = { '\0' };
	int len, sign;

	if (fields->is_h_mod)
		val = (short) va_arg(ap, int);
	else if (fields->is_l_mod)
		val = va_arg(ap, long);
	else
		val = va_arg(ap, int);

	sign = (val < 0) ? (val = -val, -1) : 1;
	convert_number(sval, val, 10);
	len = _strlen(sval) + (fields->is_plus | fields->is_space | (sign < 0));
	while (len < fields->width)
		len += _putchar(' ');

	if (sign < 0)
		_putchar('-');
	else if (fields->is_plus)
		_putchar('+');
	else if (fields->is_space)
		_putchar(' ');
	_puts_without_newline(sval);
	return len;
}

int print_unsigned_int(va_list ap, const fields_t *fields)
{
	unsigned long val;
	char sval[CAPACITY] = { '\0' };
	int len;

	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	convert_number(sval, val, 10);
	len = _strlen(sval);
	while (len < fields->width)
		len += _putchar(' ');
	_puts_without_newline(sval);
	return len;
}

int print_octal(va_list ap, const fields_t *fields)
{
	unsigned long val;
	char sval[CAPACITY] = { '\0' };
	int len;

	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	convert_number(sval, val, 8);
	len = _strlen(sval) + fields->is_hash;
	while (len < fields->width)
		len += _putchar(' ');
	if (fields->is_hash)
		_putchar('0');
	_puts_without_newline(sval);
	return len;
}

int print_hex_uppercase(va_list ap, const fields_t *fields)
{
	int ndigits = 0;
	unsigned long val;

	/* Check flags */
	if (fields->is_hash)
		ndigits += _puts_without_newline("0X");
	/* Check length modifiers */
	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	ndigits += print_hex(val, 16, UPPERCASE, fields);
	return ndigits;
}

int print_hex_lowercase(va_list ap, const fields_t *fields)
{
	int ndigits = 0;
	unsigned long val;

	/* Check flags */
	if (fields->is_hash)
		ndigits += _puts_without_newline("0x");
	/* Check length modifiers */
	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	ndigits += print_hex(val, 16, LOWERCASE, fields);
	return ndigits;
}

int print_hex(unsigned long ui, unsigned int size, enum letcase letcase, const fields_t *fields)
{
	char buffer[size];
	unsigned int i, padding, ndigits = 0;
	short is_trailing_zero = 1;
	int len = 0, tmp;

	padding = (letcase & UPPERCASE) ? 'A' - ':' : 'a' - ':';
	for (i = 0; i < size; ++i) {
		if (ui % 16 > 9)
			buffer[i] = (ui % 16) + padding + '0';
		else
			buffer[i] = (ui % 16) + '0';
		ui /= 16;
	}
	/* Check width */
	for (i = size - 1; buffer[i] == '0'; --i)
		;
	tmp = fields->width;
	while (--tmp > (int)i)
		len += _putchar(' ');

	i = size;
	while (i--) {
		/* Skip trailing zeros */
		if (i && buffer[i] == '0' && is_trailing_zero)
			continue;
		is_trailing_zero = 0;
		ndigits += _putchar(buffer[i]);
	}
	return len + ndigits;
}

int print_percent(va_list ap, const fields_t *fields)
{
	(void)ap;
	(void)fields;
	return _putchar('%');
}

int print_address(va_list ap, const fields_t *fields)
{
	unsigned long addr = va_arg(ap, unsigned long);

	if (!addr)
		return _puts_without_newline("(nil)");
	/* 16 == max number of digits needed to represent an address */
	return _puts_without_newline("0x") + print_hex(addr, 16, LOWERCASE, fields);
}
