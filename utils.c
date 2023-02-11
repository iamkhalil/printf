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
 	static char buffer[CAPACITY];
	static unsigned int i;

	if (i < CAPACITY && c != FLUSHBUF) {
		buffer[i++] = c;
	} else {
		write(1, &buffer, i);
		i = 0;
	}
	return 1;
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
	len += _putchar('\n');
	return len;
}

int _puts_without_newline(char *s)
{
	int len = 0;

	while (*s)
		len += _putchar(*s++);
	return len;
}
