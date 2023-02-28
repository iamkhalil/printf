#include "printf.h"
#include <stdlib.h>

int print_char(va_list ap, const fields_t *fields)
{
	int len = 0, i;

	if (!fields->is_minus) {
		for (i = 0; i < (int)fields->width - 1; ++i)
			_putchar(' ');
	}
	len += _putchar(va_arg(ap, int));
	if (fields->is_minus) {
		for (i = 0; i < (int)fields->width - 1; ++i)
			_putchar(' ');
	}
	return len + i;
}

int print_string(va_list ap, const fields_t *fields)
{
	char *sp = va_arg(ap, char *);
	unsigned int len = 0, padding, precision, threshold;

	if (fields->precision == UINT_MAX) /* no precision is provided */
		padding = (fields->width > _strlen(sp)) ? fields->width - _strlen(sp) : 0;
	else if (fields->width > fields->precision)
		padding = fields->width - fields->precision;
	else
		padding = 0;

	if (!fields->is_minus) {
		while (padding--)
			len += _putchar(' ');
	}

	precision = (fields->precision == UINT_MAX) ? _strlen(sp) : fields->precision;
	while (*sp && precision) {
		len += _putchar(*sp++);
		--precision;
	}

	threshold = 0;
	if (fields->precision != UINT_MAX && fields->precision > fields->width)
		threshold = fields->precision - fields->width;

	while (precision-- > threshold)
		len += _putchar(' ');

	if (fields->is_minus) {
		while (padding--)
			len += _putchar(' ');
	}
	return len;
}

int print_int(va_list ap, const fields_t *fields)
{
	long val;
	char sval[CAPACITY] = { '\0' };
	unsigned int len, padding, precision;
	int sign;
	char cpad;

	CHECK_LENGTH_MOD(val, fields->is_h_mod, int, short, fields->is_l_mod, long, int);
	sign = (val < 0) ? (val = -val, -1) : 1;
	convert_number(sval, val, 10, NONE);
	len = _strlen(sval);
	padding = get_padding(fields, len, sval[0], sign);
	cpad = (fields->is_zero && fields->precision == UINT_MAX) ? '0' : ' ';
	if (cpad == ' ' && !fields->is_minus) {
		while (padding--)
			len += _putchar(cpad);
	}

	if (sign < 0)
		len += _putchar('-');
	else if (fields->is_plus)
		len += _putchar('+');
	else if (fields->is_space)
		len += _putchar(' ');

	if (cpad == '0' && !fields->is_minus) {
		while (padding--)
			len += _putchar(cpad);
	}

	if (sval[0] != '0' && fields->precision != UINT_MAX) {
		precision = (fields->precision > _strlen(sval)) ?
			     fields->precision - _strlen(sval) : 0;
		while (precision--)
			len += _putchar('0');
	}
	if (sval[0] == '0' && fields->precision == 0) {
		sval[0] = '\0';
		--len;
	}

	_puts_without_newline(sval);

	if (fields->is_minus) {
		while (padding--)
			len += _putchar(cpad);
	}
	return len;
}

int print_unsigned_int(va_list ap, const fields_t *fields)
{
	unsigned long val;
	char sval[CAPACITY] = { '\0' };
	unsigned int len, padding, precision;
	char cpad;

	CHECK_LENGTH_MOD(val, fields->is_h_mod, unsigned int, unsigned short,
			 fields->is_l_mod, unsigned long, unsigned int);
	convert_number(sval, val, 10, NONE);
	len = _strlen(sval);
	padding = get_padding(fields, len, sval[0], 1);
	cpad = (fields->is_zero && fields->precision == UINT_MAX) ? '0' : ' ';
	while (!fields->is_minus && padding--)
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
	while (fields->is_minus && padding--)
		len += _putchar(cpad);
	return len;
}

int print_octal(va_list ap, const fields_t *fields)
{
	unsigned long val;
	char sval[CAPACITY] = { '\0' };
	unsigned int len, padding, precision;
	char cpad;

	CHECK_LENGTH_MOD(val, fields->is_h_mod, unsigned int, unsigned short,
			 fields->is_l_mod, unsigned long, unsigned int);
	convert_number(sval, val, 8, NONE);
	len = _strlen(sval) + fields->is_hash;
	padding = get_padding(fields, len, sval[0], 1);
	cpad = (fields->is_zero && fields->precision == UINT_MAX) ? '0' : ' ';
	while (!fields->is_minus && padding--)
		len += _putchar(cpad);

	if (sval[0] != '0' && fields->precision != UINT_MAX) {
		precision = (fields->precision > _strlen(sval) + fields->is_hash) ?
			     fields->precision - _strlen(sval) - fields->is_hash : 0;
		while (precision--)
			len += _putchar('0');
	}
	if (sval[0] == '0' && fields->precision == 0) {
		sval[0] = '\0';
		--len;
	}

	if (fields->is_hash)
		_putchar('0');

	_puts_without_newline(sval);

	while (fields->is_minus && padding--)
		len += _putchar(cpad);
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

	CHECK_LENGTH_MOD(val, fields->is_h_mod, unsigned int, unsigned short,
			 fields->is_l_mod, unsigned long, unsigned int);
	convert_number(sval, val, 16, letcase);
	len = _strlen(sval) + ((fields->is_hash) ? 2 : 0);
	if (fields->precision != UINT_MAX && fields->precision > _strlen(sval))
		precision = fields->precision - _strlen(sval);

	cpad = (fields->is_zero && fields->precision == UINT_MAX) ? '0' : ' ';
	if (cpad == ' ' && !fields->is_minus) {
		while (len + precision < fields->width)
			len += _putchar(cpad);
	}

	if (fields->is_hash)
		_puts_without_newline((letcase & UPPERCASE) ? "0X" : "0x");

	if (cpad == '0' && !fields->is_minus) {
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

	if (fields->is_minus) {
		while (len < fields->width)
			len += _putchar(cpad);
	}
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
