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
	printf("Length:[%d, %i]\n", real, real);
	_printf("Length:[%d, %i]\n", mine, mine);
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
	printf("Octal:[%o]\n", ui);
	_printf("Octal:[%o]\n", ui);
	printf("hexadecimal:[%x, %X]\n", ui, ui);
	_printf("hexadecimal:[%x, %X]\n", ui, ui);
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
	printf("Unsigned length modifier <h>:[%hx, %hX, %ho, %hu]\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	_printf("Unsigned length modifier <h>:[%hx, %hX, %ho, %hu]\n", UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX);
	printf("Unsigned length modifier <h>:[%hx, %hX, %ho, %hu]\n", USHRT_MAX, USHRT_MAX, USHRT_MAX, USHRT_MAX);
	_printf("Unsigned length modifier <h>:[%hx, %hX, %ho, %hu]\n", USHRT_MAX, USHRT_MAX, USHRT_MAX, USHRT_MAX);
	printf("Unsigned length modifier <l>:[%lx, %lX, %lo, %lu]\n", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX);
	_printf("Unsigned length modifier <l>:[%lx, %lX, %lo, %lu]\n", ULONG_MAX, ULONG_MAX, ULONG_MAX, ULONG_MAX);
	printf("Unsigned length modifier <l>:[%lx, %lX, %lo, %lu]\n", (unsigned long)INT_MIN, (unsigned long)INT_MIN,
								      (unsigned long)INT_MIN,(unsigned long)INT_MIN);
	_printf("Unsigned length modifier <l>:[%lx, %lX, %lo, %lu]\n",(unsigned long)INT_MIN, (unsigned long)INT_MIN,
								      (unsigned long)INT_MIN, (unsigned long)INT_MIN);
	printf("Char width <*>:[%*c]\n", 2, 'c');
	_printf("Char width <*>:[%*c]\n", 2, 'c');
	printf("Char width <n>:[%4c]\n", 'c');
	_printf("Char width <n>:[%4c]\n", 'c');
	printf("String width <*>:[%*s]\n", 4, "42");
	_printf("String width <*>:[%*s]\n", 4, "42");
	printf("String width <n>:[%4s]\n", "42");
	_printf("String width <n>:[%4s]\n", "42");
	printf("Signed int width <*>:[%*d]\n", 4, 42);
	_printf("Signed int width <*>:[%*d]\n", 4, 42);
	printf("Signed int width <n>:[%4d]\n", 42);
	printf("Signed int width <n>:[%4d]\n", 42);
	real = printf("Signed int width:[%2d]\n", 42);
	mine = _printf("Signed int width:[%2d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int width:[%4d]\n", 42);
	mine = _printf("Signed int width:[%4d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int width:[%+3d]\n", 42);
	mine = _printf("Signed int width:[%+3d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int width:[% 3d]\n", 42);
	mine = _printf("Signed int width:[% 3d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int width:[%+03d]\n", 42);
	mine = _printf("Signed int width:[%+03d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int width:[%+4hd]\n", 42);
	mine = _printf("Signed int width:[%+4hd]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int width:[%+4d]\n", -42);
	mine = _printf("Signed int width:[%+4d]\n", -42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned width:[%*u]\n", 4, 2);
	mine = _printf("Unsigned width:[%*u]\n", 4, 2);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned width:[%2u]\n", 1);
	mine = _printf("Unsigned width:[%2u]\n", 1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal width:[%*o]\n", 4, 2);
	mine = _printf("octal width:[%*o]\n", 4, 2);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal width:[%2o]\n", 1);
	mine = _printf("octal width:[%2o]\n", 1);
	real = printf("hexadecimal width:[%4x, %4X]\n", 10, 7);
	mine = _printf("hexadecimal width:[%4x, %4X]\n", 10, 7);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal and flags:[%#3o]\n", 7);
	mine = _printf("octal and flags:[%#3o]\n", 7);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("String precision <n>:[%.2s]\n", "123456789");
	mine = _printf("String precision <n>:[%.2s]\n", "123456789");
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("String precision <*>:[%.*s]\n", 2, "123456789");
	mine = _printf("String precision <*>:[%.*s]\n", 2, "123456789");
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("String precision:[%.s]\n", "123456789");
	mine = _printf("String precision:[%.s]\n", "123456789");
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("String precision and width:[%12.6s]\n", "123456789");
	mine = _printf("String precision and width:[%12.6s]\n", "123456789");
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("String precision and width:[%4.6s]\n", "123456789");
	mine = _printf("String precision and width:[%4.6s]\n", "123456789");
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned precision <n>:[%.u]\n", 0);
	mine = _printf("Unsigned precision <n>:[%.u]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned precision <n>:[%.0u]\n", 0);
	mine = _printf("Unsigned precision <n>:[%.0u]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned precision <n>:[%.2u]\n", 42);
	mine = _printf("Unsigned precision <n>:[%.2u]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned precision <*>:[%.*u]\n", 3, 7);
	mine = _printf("Unsigned precision <*>:[%.*u]\n", 3, 7);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned precision and width:[%6.4u]\n", 42);
	mine = _printf("Unsigned precision and width:[%6.4u]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal precision <n>:[%4.o]\n", 0);
	mine = _printf("octal precision <n>:[%4.o]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal precision <n>:[%.0o]\n", 0);
	mine = _printf("octal precision <n>:[%.0o]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal precision <n>:[%.2o]\n", 42);
	mine = _printf("octal precision <n>:[%.2o]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal precision <*>:[%.*o]\n", 3, 7);
	mine = _printf("octal precision <*>:[%.*o]\n", 3, 7);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal precision and width:[%6.4o]\n", 42);
	mine = _printf("octal precision and width:[%6.4o]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal precision and flags:[%#.3o]\n", 1);
	mine = _printf("octal precision and flags:[%#.3o]\n", 1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal precision, width and flags:[%#4.3o]\n", 1);
	mine = _printf("octal precision, width and flags:[%#4.3o]\n", 1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal precision, width and flags:[%4.o]\n", 0);
	mine = _printf("octal precision, width and flags:[%4.o]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal precision, width and flags:[%#4.o]\n", 0);
	mine = _printf("octal precision, width and flags:[%#4.o]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision:[%.d]\n", 0);
	mine = _printf("Signed int precision:[%.d]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision:[%.d]\n", 12);
	mine = _printf("Signed int precision:[%.d]\n", 12);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision and width:[%4.1d]\n", 123);
	mine = _printf("Signed int precision and width:[%4.1d]\n", 123);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision and width:[%+2.d]\n", 0);
	mine = _printf("Signed int precision and width:[%+2.d]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision and width:[%+2.d]\n", 1);
	mine = _printf("Signed int precision and width:[%+2.d]\n", 1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision, width and flags:[% 2.d]\n", 1);
	mine = _printf("Signed int precision, width and flags:[% 2.d]\n", 1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision and width:[%2.d]\n", -1);
	mine = _printf("Signed int precision and width:[%2.d]\n", -1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision, width and flags:[%+4.2d]\n", 42);
	mine = _printf("Signed int precision, width and flags:[%+4.2d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision and width:[%.3d]\n", 42);
	mine = _printf("Signed int precision and width:[%.3d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int precision, width and flags:[%+5.3d]\n", 42);
	mine = _printf("Signed int precision, width and flags:[%+5.3d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Hexadecimal precision:[%.x]\n", 0);
	mine = _printf("Hexadecimal precision:[%.x]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Hexadecimal precision, width, and flags:[%#3.x]\n", -1);
	mine = _printf("Hexadecimal precision, width, and flags:[%#3.x]\n", -1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Hexadecimal precision, width, and flags:[%#5.2x]\n", 12);
	mine = _printf("Hexadecimal precision, width, and flags:[%#5.2x]\n", 12);
	printf("Length:[%d, %d]\n", real, mine);
	_printf("Reverse:[%r]\n", "ABCDEF");
	_printf("Rot13:[%R]\n", "Hello42");
	real = printf("Signed int zero flag:[%02d]\n", 1);
	mine = _printf("Signed int zero flag:[%02d]\n", 1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int zero flag:[%0d]\n", 1);
	mine = _printf("Signed int zero flag:[%0d]\n", 1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int flags:[%03d]\n", -1);
	mine = _printf("Signed int flags:[%03d]\n", -1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int flags:[%+03d]\n", 1);
	mine = _printf("Signed int flags:[%+03d]\n", 1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned int zero flag:[%03u]\n", 1);
	mine = _printf("Unsigned int zero flag:[%03u]\n", 1);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Hexadecimal zero flag:[%04X]\n", 10);
	mine = _printf("Hexadecimal zero flag:[%04X]\n", 10);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Hexadecimal flags and width:[%#05x]\n", 12);
	mine = _printf("Hexadecimal flags and width:[%#05x]\n", 12);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal zero flag:[%04o]\n", 10);
	mine = _printf("octal zero flag:[%04o]\n", 10);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("octal flags and width:[%#03o]\n", 7);
	mine = _printf("octal flags and width:[%#03o]\n", 7);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int minus flag:[%-d]\n", 42);
	mine = _printf("Signed int minus flag:[%-d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int minus flag:[%-5d]\n", 42);
	mine = _printf("Signed int minus flag:[%-5d]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int minus flag:[%-5d%5d]\n", 123, 42);
	mine = _printf("Signed int minus flag:[%-5d%5d]\n", 123, 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Signed int minus flag:[%-+5d% 5d]\n", 123, -42);
	mine = _printf("Signed int minus flag:[%-+5d% 5d]\n", 123, -42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned int minus flag:[%-u]\n", 42);
	mine = _printf("Unsigned int minus flag:[%-u]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned int minus flag:[%-5u]\n", 42);
	mine = _printf("Unsigned int minus flag:[%-5u]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Unsigned int minus flag:[%-5u%5u]\n", 123, 42);
	mine = _printf("Unsigned int minus flag:[%-5u%5u]\n", 123, 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Octal minus flag:[%-o]\n", 42);
	mine = _printf("Octal minus flag:[%-o]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Octal minus flag:[%-5o]\n", 42);
	mine = _printf("Octal minus flag:[%-5o]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Octal minus flag:[%-5.4o%05o]\n", 123, 42);
	mine = _printf("Octal minus flag:[%-5.4o%05o]\n", 123, 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Hexadecimal minus flag:[%-x]\n", 42);
	mine = _printf("Hexadecimal minus flag:[%-x]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Hexadecimal minus flag:[%-5x]\n", 42);
	mine = _printf("Hexadecimal minus flag:[%-5x]\n", 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Hexadecimal minus flag:[%-5.4x%05x]\n", 123, 42);
	mine = _printf("Hexadecimal minus flag:[%-5.4x%05x]\n", 123, 42);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Hexadecimal minus flag:[%-5.x]\n", 0);
	mine = _printf("Hexadecimal minus flag:[%-5.x]\n", 0);
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Char minus flag:[%-c]\n", 'c');
	mine = _printf("Char minus flag:[%-c]\n", 'c');
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Char minus flag:[%-5c]\n", 'c');
	mine = _printf("Char minus flag:[%-5c]\n", 'c');
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("Char minus flag:[%-5.4c%05c]\n", 'K', 'O');
	mine = _printf("Char minus flag:[%-5.4c%05c]\n", 'K', 'O');
	real = printf("String minus flag:[%-s]\n", "Hello");
	mine = _printf("String minus flag:[%-s]\n", "Hello");
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("String minus flag:[%-5s]\n", "World");
	mine = _printf("String minus flag:[%-5s]\n", "World");
	printf("Length:[%d, %d]\n", real, mine);
	real = printf("String minus flag:[%-5.4s%05s]\n", "OK", "KO");
	mine = _printf("String minus flag:[%-5.4s%05s]\n", "OK", "KO");
	printf("Length:[%d, %d]\n", real, mine);

	return 0;
}
