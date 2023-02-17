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
 	static char buffer[BUFSIZE];
	static unsigned int i;

	if (i < BUFSIZE && c != FLUSHBUF) {
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

/**
 * _strlen - Calculate the length of a string
 * @s: the given string
 *
 * Return: The length of s
 */
unsigned int _strlen(const char *s)
{
	const char *sp = s;

	while (*sp)
		++sp;
	return sp - s;
}

/**
 * convert_number - Convert a number from one base to another.
 * @res: pointer to the resulting number
 * @n: the number to convert
 * @base: the desired base (decimal, octal)
 *
 * Result: pointer to the resulting number res
 */
char *convert_number(char *res, unsigned long n, unsigned short base)
{
	char number[CAPACITY] = { '\0' };
	unsigned short i;

	i = 0;
	while (n / base) {
		number[i++] = n % base + '0';
		n /= base;
	}
	number[i] = n % base + '0';
	reverse_array(number, i + 1);
	return _strncpy(res, number, i + 1);
}

/**
 * reverse_array - Reverse an array of characters
 * @arr: the given array
 * @size: size of arr
 */
void reverse_array(char *arr, unsigned int size)
{
	unsigned int i;
	char tmp;

	for (i = 0; i < size / 2; ++i) {
		tmp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = tmp;
	}
}

/**
 * _strncpy - Copie at most n bytes from src to dest
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * @n: number of bytes
 *
 * Return: pointer to the resulting string dest
 */
char *_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n && src[i]; ++i)
		dest[i] = src[i];
	for (; i < n; ++i)
		dest[i] = '\0';
	return dest;
}
