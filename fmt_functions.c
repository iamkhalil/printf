#include "printf.h"
#include <stdlib.h>

int print_char(va_list ap, const flags_t *flags)
{
	(void)flags;
	return _putchar(va_arg(ap, int));
}

int print_string(va_list ap, const flags_t *flags)
{
	(void)flags;
	char *sval;
	int len = 0;

	for (sval = va_arg(ap, char *); *sval; ++sval) {
		len += _putchar(*sval);
	}
	return len;
}

int print_int(va_list ap, const flags_t *flags)
{
	long val;
	int tmp, divisor = 1, len = 0;

	/* Check length modifiers */
	if (flags->is_h_mod)
		val = (short) va_arg(ap, int);
	else if (flags->is_l_mod)
		val = va_arg(ap, long);
	else
		val = va_arg(ap, int);

	if (val < 0) {
		len += _putchar('-');
		val = -val;
	} else { /* Check flags */
		if (flags->is_plus)
			len += _putchar('+');
		else if (flags->is_space)
			len += _putchar(' ');
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

int print_unsigned_int(va_list ap, const flags_t *flags)
{
	(void)flags;
	return print_unsigned_int_rec(va_arg(ap, unsigned int), 0);
}

int print_unsigned_int_rec(unsigned int ui, unsigned int len)
{
	if (ui > 10)
		len += print_unsigned_int_rec(ui / 10, len);
	return len + _putchar((ui % 10) + '0');
}

//!TODO: Remove dynamic memory allocation
int print_octal(va_list ap, const flags_t *flags)
{
	unsigned int *arr;
	unsigned long ui, tmp;
	short ndigits = 1, i;

	/* Check length modifiers */
	if (flags->is_h_mod)
		ui = (unsigned short) va_arg(ap, unsigned int);
	else if (flags->is_l_mod)
		ui = va_arg(ap, unsigned long);
	else
		ui = va_arg(ap, unsigned int);

	tmp = ui;
	while (tmp / 8) {
		tmp /= 8;
		++ndigits;
	}
	arr = malloc(sizeof(ui) * ndigits);
	if (!arr) {
		_puts("Error: Failed to allocate memory.");
		exit(99);
	}
	for (i = 0; i < ndigits; ++i) {
		arr[i] = ui % 8;
		ui /= 8;
	}
	if (arr[i - 1] && flags->is_hash) {
		++ndigits;
		_putchar('0');
	}
	while (i--)
		_putchar(arr[i] + '0');
	free(arr);
	return ndigits;
}

int print_hex_uppercase(va_list ap, const flags_t *flags)
{
	int ndigits = 0;
	unsigned long val;

	/* Check flags */
	if (flags->is_hash)
		ndigits += _puts_without_newline("0X");
	/* Check length modifiers */
	if (flags->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (flags->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	ndigits += print_hex(val, 16, UPPERCASE);
	return ndigits;
}

int print_hex_lowercase(va_list ap, const flags_t *flags)
{
	int ndigits = 0;
	unsigned long val;

	/* Check flags */
	if (flags->is_hash)
		ndigits += _puts_without_newline("0x");
	/* Check length modifiers */
	if (flags->is_h_mod)
		val = (unsigned short) va_arg(ap, unsigned int);
	else if (flags->is_l_mod)
		val = va_arg(ap, unsigned long);
	else
		val = va_arg(ap, unsigned int);

	ndigits += print_hex(val, 16, LOWERCASE);
	return ndigits;
}

int print_hex(unsigned long ui, unsigned int size, enum letcase letcase)
{
	char buffer[size];
	unsigned int i, padding, ndigits = 0;
	short is_trailing_zero = 1;

	padding = (letcase & UPPERCASE) ? 'A' - ':' : 'a' - ':';
	for (i = 0; i < size; ++i) {
		if (ui % 16 > 9)
			buffer[i] = (ui % 16) + padding + '0';
		else
			buffer[i] = (ui % 16) + '0';
		ui /= 16;
	}

	while (i--) {
		/* Skip trailing zeros */
		if (i && buffer[i] == '0' && is_trailing_zero)
			continue;
		is_trailing_zero = 0;
		ndigits += _putchar(buffer[i]);
	}
	return ndigits;
}

int print_percent(va_list ap, const flags_t *flags)
{
	(void)ap;
	(void)flags;
	return _putchar('%');
}

int print_address(va_list ap, const flags_t *flags)
{
	(void)flags;
	unsigned long addr = va_arg(ap, unsigned long);

	if (!addr)
		return _puts_without_newline("(nil)");
	/* 16 == max number of digits needed to represent an address */
	return _puts_without_newline("0x") + print_hex(addr, 16, LOWERCASE);
}
