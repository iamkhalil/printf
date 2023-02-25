#include "printf.h"
#include <stdlib.h>

int print_char(va_list ap, const fields_t *fields)
{
	int i;

	for (i = 0; i < (int) fields->width - 1; ++i)
		_putchar(' ');
	return i + _putchar(va_arg(ap, int));
}

int print_string(va_list ap, const fields_t *fields)
{
	char *sp = va_arg(ap, char *);
	unsigned int len, padding, precision;

	padding = get_padding(fields, _strlen(sp));
	for (len = 0; len < padding; ++len)
		_putchar(' ');
	precision = fields->precision;
	while (*sp && precision--)
		len += _putchar(*sp++);
	return len;
}

int print_int(va_list ap, const fields_t *fields)
{
	long val;
	char sval[CAPACITY] = { '\0' };
	unsigned int len, padding, precision, total_len;
	int sign;
	char cpad;

	if (fields->is_h_mod)
		val = (short) va_arg(ap, int);
	else if (fields->is_l_mod)
		val = va_arg(ap, long);
	else
		val = va_arg(ap, int);

	sign = (val < 0) ? (val = -val, -1) : 1;
	convert_number(sval, val, 10, NONE);
	len = _strlen(sval);
	total_len = len + (fields->is_plus | fields->is_space | (sign < 0));

	if (fields->precision == UINT_MAX) {
		padding = (fields->width > total_len) ? fields->width - total_len : 0;
	} else if (fields->precision == 0 && val == 0) {
		padding = fields->width - (fields->is_plus | fields->is_space);
	} else {
		if (fields->precision > fields->width)
			padding = 0;
		else if (fields->precision < total_len)
			padding = (fields->width > total_len) ? fields->width - total_len : 0;
		else
			padding = fields->width - total_len - (fields->precision - len);
	}

	cpad = (fields->is_zero && fields->precision == UINT_MAX) ? '0' : ' ';
	if (cpad != '0') {
		while (padding--)
			total_len += _putchar(cpad);
	}

	if (sign < 0)
		_putchar('-');
	else if (fields->is_plus)
		_putchar('+');
	else if (fields->is_space)
		_putchar(' ');

	if (cpad == '0') {
		while (padding--)
			total_len += _putchar(cpad);
	}

	if (sval[0] != '0' && fields->precision != UINT_MAX) {
		precision = (fields->precision > len) ? fields->precision - len : 0;
		while (precision--)
			total_len += _putchar('0');
	}
	if (sval[0] == '0' && fields->precision == 0) {
		sval[0] = '\0';
		--total_len;
	}
	_puts_without_newline(sval);
	return total_len;
}

int print_unsigned_int(va_list ap, const fields_t *fields)
{
	unsigned long val;
	char sval[CAPACITY] = { '\0' };
	unsigned int len, padding, precision;
	char cpad;

	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	convert_number(sval, val, 10, NONE);
	len = _strlen(sval);
	padding = get_padding(fields, len);
	cpad = (fields->is_zero && fields->precision == UINT_MAX) ? '0' : ' ';
	while (padding--)
		len += _putchar(cpad);

	if (sval[0] == '0' && fields->precision == 0)
		return len - 1;
	if (sval[0] != '0' && fields->precision != UINT_MAX) {
		precision = (fields->precision > _strlen(sval)) ?
			     fields->precision - _strlen(sval) : 0;
		while (precision--)
			len += _putchar('0');
	}
	_puts_without_newline(sval);
	return len;
}

int print_octal(va_list ap, const fields_t *fields)
{
	unsigned long val;
	char sval[CAPACITY] = { '\0' };
	unsigned int len, padding, precision;
	char cpad;

	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	convert_number(sval, val, 8, NONE);
	len = _strlen(sval) + fields->is_hash;
	padding = (fields->is_hash && sval[0] == '0') ?
		   get_padding(fields, len) - 1 : get_padding(fields, len);
	cpad = (fields->is_zero && fields->precision == UINT_MAX) ? '0' : ' ';
	while (padding--)
		len += _putchar(cpad);

	if (sval[0] != '0' && fields->precision != UINT_MAX) {
		precision = (fields->precision > _strlen(sval) + fields->is_hash) ?
			     fields->precision - (_strlen(sval) + fields->is_hash) : 0;
		while (precision--)
			len += _putchar('0');
	}
	if (sval[0] == '0' && fields->precision == 0) {
		--len;
		sval[0] = '\0';
	}
	if (fields->is_hash)
		_putchar('0');
	_puts_without_newline(sval);
	return len;
}

int print_hex_uppercase(va_list ap, const fields_t *fields)
{
	return print_hex(ap, fields, UPPERCASE);
}

int print_hex_lowercase(va_list ap, const fields_t *fields)
{
	return print_hex(ap, fields, LOWERCASE);
}

int print_hex(va_list ap, const fields_t *fields, enum letcase letcase)
{
	char sval[CAPACITY] = { '\0' };
	unsigned long val;
	unsigned int len, precision = 0;
	char cpad;

	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	convert_number(sval, val, 16, letcase);
	len = _strlen(sval) + ((fields->is_hash) ? 2 : 0);

	if (fields->precision != UINT_MAX && fields->precision > _strlen(sval))
		precision = fields->precision - _strlen(sval);
	cpad = (fields->is_zero && fields->precision == UINT_MAX) ? '0' : ' ';
	if (cpad != '0') {
		while (len + precision < fields->width)
			len += _putchar(cpad);
	}
	if (fields->is_hash)
		_puts_without_newline((letcase & UPPERCASE) ? "0X" : "0x");
	if (cpad == '0') {
		while (len + precision < fields->width)
			len += _putchar(cpad);
	}
	while (precision--)
		len += _putchar('0');
	if (sval[0] == '0' && fields->precision == 0) {
		--len;
		sval[0] = '\0';
	}
	_puts_without_newline(sval);
	return len;
}

int print_percent(va_list ap, const fields_t *fields)
{
	(void)ap;
	(void)fields;
	return _putchar('%');
}

int print_address(va_list ap, const fields_t *fields)
{
	char saddr[CAPACITY] = { '\0' };
	unsigned long addr = va_arg(ap, unsigned long);
	unsigned int len;

	if (!addr)
		return _puts_without_newline("(nil)");
	convert_number(saddr, addr, 16, LOWERCASE);
	len = _strlen(saddr) + 2; /* +2 for "0x" */
	while (len < fields->width)
		len += _putchar(' ');
	_puts_without_newline("0x");
	_puts_without_newline(saddr);
	return len;
}
