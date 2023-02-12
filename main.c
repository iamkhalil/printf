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
	printf("Signed length modifier <h>:[%hd, %hi]\n", INT_MAX, INT_MAX);
	_printf("Signed length modifier <h>:[%hd, %hi]\n", INT_MAX, INT_MAX);
	printf("Signed length modifier <h>:[%hd, %hi]\n", SHRT_MAX, SHRT_MAX );
	_printf("Signed length modifier <h>:[%hd, %hi]\n", SHRT_MAX, SHRT_MAX);
	printf("Signed length modifier <l>:[%ld, %li]\n", (long)INT_MAX, (long)INT_MAX);
	_printf("Signed length modifier <l>:[%ld, %li]\n", (long)INT_MAX, (long)INT_MAX);
	printf("Signed length modifier <l>:[%ld, %li]\n", ULONG_MAX, ULONG_MAX);
	_printf("Signed length modifier <l>:[%ld, %li]\n", ULONG_MAX, ULONG_MAX);
	printf("Unsigned length modifier <h>:[%hx, %hX, %ho]\n", UINT_MAX, UINT_MAX, UINT_MAX);
	_printf("Unsigned length modifier <h>:[%hx, %hX, %ho]\n", UINT_MAX, UINT_MAX, UINT_MAX);
	printf("Unsigned length modifier <h>:[%hx, %hX, %ho]\n", USHRT_MAX, USHRT_MAX, USHRT_MAX);
	_printf("Unsigned length modifier <h>:[%hx, %hX, %ho]\n", USHRT_MAX, USHRT_MAX, USHRT_MAX);
	printf("Unsigned length modifier <l>:[%lx, %lX, %lo]\n", ULONG_MAX, ULONG_MAX, ULONG_MAX);
	_printf("Unsigned length modifier <l>:[%lx, %lX, %lo]\n", ULONG_MAX, ULONG_MAX, ULONG_MAX);
	printf("Unsigned length modifier <l>:[%lx, %lX, %lo]\n", (unsigned long)INT_MIN, (unsigned long)INT_MIN,
								 (unsigned long)INT_MIN);
	_printf("Unsigned length modifier <l>:[%lx, %lX, %lo]\n",(unsigned long)INT_MIN, (unsigned long)INT_MIN,
								 (unsigned long)INT_MIN);

	return 0;
}
