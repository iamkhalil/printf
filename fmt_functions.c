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
	char *sval = va_arg(ap, char *);
	int len;

	for (len = _strlen(sval); len < fields->width; ++len)
		_putchar(' ');
	while (*sval)
		_putchar(*sval++);
	return len;
}

int print_int(va_list ap, const fields_t *fields)
{
	long val;
	int tmp, divisor = 1, len = 1;

	/* Check length modifiers */
	if (fields->is_h_mod)
		val = (short) va_arg(ap, int);
	else if (fields->is_l_mod)
		val = va_arg(ap, long);
	else
		val = va_arg(ap, int);

	tmp = (val < 0) ? -val : val;
	while (tmp / 10) {
		tmp /= 10;
		divisor *= 10;
		++len;
	}

	/* Check width */
	len += (fields->is_plus | fields->is_space);
	tmp = fields->width;
	while (tmp-- > len)
		_putchar(' ');
	len += (fields->width > len) ? fields->width - len : 0;

	/* Check flags */
	if (val < 0) {
		len += _putchar('-');
		/* '+' flag should not be taken into account when val < 0 */
		if (fields->is_plus)
			--len;
		val = -val;
	} else {
		if (fields->is_plus)
			_putchar('+');
		else if (fields->is_space)
			_putchar(' ');
	}

	while (divisor) {
		_putchar((val / divisor) + '0');
		val %= divisor;
		divisor /= 10;
	}
	return len;
}

int print_unsigned_int(va_list ap, const fields_t *fields)
{
	unsigned long val, tmp;
	int ndigits = 1, len = 0;

	if (fields->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	tmp = val;
	while (tmp / 10) {
		tmp /= 10;
		++ndigits;
	}
	tmp = fields->width;
	while ((int)tmp-- > ndigits)
		len += _putchar(' ');

	return len + print_unsigned_int_rec(val, 0);
}

int print_unsigned_int_rec(unsigned long ui, unsigned int len)
{
	if (ui > 10)
		len += print_unsigned_int_rec(ui / 10, len);
	return len + _putchar((ui % 10) + '0');
}

// FIXME: Remove dynamic memory allocation
int print_octal(va_list ap, const fields_t *fields)
{
	unsigned int *arr;
	unsigned long ui, tmp;
	short ndigits = 1, i, len = 0;

	/* Check length modifiers */
	if (fields->is_h_mod)
		ui = (unsigned short) va_arg(ap, unsigned int);
	else if (fields->is_l_mod)
		ui = va_arg(ap, unsigned long);
	else
		ui = va_arg(ap, unsigned int);

	tmp = ui;
	while (tmp / 8) {
		tmp /= 8;
		++ndigits;
	}

	/* Check width */
	tmp = fields->width;
	while ((int)tmp-- > ndigits)
		len += _putchar(' ');

	arr = malloc(sizeof(ui) * ndigits);
	if (!arr) {
		_puts("Error: Failed to allocate memory.");
		exit(99);
	}
	for (i = 0; i < ndigits; ++i) {
		arr[i] = ui % 8;
		ui /= 8;
	}
	if (arr[i - 1] && fields->is_hash) {
		++ndigits;
		_putchar('0');
	}
	while (i--)
		_putchar(arr[i] + '0');
	free(arr);
	return len + ndigits;
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
