#include <stdio.h>
#include "printf.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int real, mine;

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
	mine = _printf("%b", 42);

	return 0;
}
