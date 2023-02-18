#include "printf.h"
#include <stdlib.h>
#include <stdio.h>
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

	if (fields->precision == UINT_MAX) /* no precision is provided */
		padding = (fields->width > _strlen(sp)) ? fields->width - _strlen(sp) : 0;
	else if (fields->width > fields->precision)
		padding = fields->width - fields->precision;
	else
		padding = 0;

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
	unsigned int len;
	int sign;

	if (fields->is_h_mod)
		val = (short) va_arg(ap, int);
	else if (fields->is_l_mod)
		val = va_arg(ap, long);
	else
		val = va_arg(ap, int);

	sign = (val < 0) ? (val = -val, -1) : 1;
	convert_number(sval, val, 10, NONE);
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
	unsigned int len;

	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	convert_number(sval, val, 10, NONE);
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
	unsigned int len;

	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	convert_number(sval, val, 8, NONE);
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
	unsigned int len;

	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	convert_number(sval, val, 16, letcase);
	len = _strlen(sval) + ((fields->is_hash) ? 2 : 0);
	while (len < fields->width)
		len += _putchar(' ');
	if (fields->is_hash)
		_puts_without_newline((letcase & UPPERCASE) ? "0X" : "0x");
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
