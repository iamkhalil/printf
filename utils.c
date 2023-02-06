#include "utils.h"

/**
 * _putchar - print a character to stdout
 * @c: the character to print
 *
 * Return: On success, 1 is returned. On error, -1 is returned, and errno is
 * set appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _puts - print a string, followed by a newline.
 * @s: the string to print
 *
 * Return: The number of characters written
 */
int _puts(char *s)
{
	int len = 0;

	while (*s) {
		len += _putchar(*s);
		++s;
	}
	_putchar('\n');
	return len;
}
