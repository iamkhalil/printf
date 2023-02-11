#include <stdio.h>
#include <limits.h>
#include "printf.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int real, mine;
	unsigned int ui;
	void *addr;

	real = printf("Char:[%c]\n", 'K');
	mine = _printf("Char:[%c]\n", 'K');
	real = printf("String:[%s]\n", "Hello, world!");
	mine = _printf("String:[%s]\n", "Hello, world!");
	printf("Length:[%d, %i]\n", real, real);
	_printf("Length:[%d, %i]\n", mine, mine);
	real = printf("Negative:[%d]\n", -1024);
	mine = _printf("Negative:[%d]\n", -1024);
	printf("Length:[%d, %i]\n", real, real);
	_printf("Length:[%d, %i]\n", mine, mine);
	_printf("Binary:[%b]\n", 42);
	ui = (unsigned int)INT_MAX + 2048;
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned Octal:[%o]\n", ui);
	_printf("Unsigned Octal:[%o]\n", ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Non-printable:[%S]\n", "Choose\r\nLife!");
	printf("Percent:[%%]\n");
	_printf("Percent:[%%]\n");
	addr = (void *)0x7ffe6a4241f0;
	printf("Address:[%p]\n", addr);
	_printf("Address:[%p]\n", addr);
	printf("Plus flag:[%+d]\n", 42);
	_printf("Plus flag:[%+d]\n", 42);
	printf("Space flag:[% d]\n", 1337);
	_printf("Space flag:[% d]\n", 1337);
	printf("Hash flag:[%#o, %#x, %#X]\n", 7, ui, ui);
	_printf("Hash flag:[%#o, %#x, %#X]\n", 7, ui, ui);
	return 0;
}
