#include "printf.h"

/**
 * get_fmt_func - Select a function based on the format specifier
 * @fmt: the given format specifier
 *
 * Return: On success, a pointer to the function that match the format
 * specifier is returned. NULL otherwise.
 */
int (*get_fmt_func(char fmt))(va_list, const fields_t *)
{
	static const fmt_t map[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_unsigned_int},
		{'o', print_octal},
		{'x', print_hex_lowercase},
		{'X', print_hex_uppercase},
		{'S', print_S},
		{'%', print_percent},
		{'p', print_address},
		{'\0', NULL}
	};
	unsigned int i;

	i = 0;
	while (map[i].fmt != '\0') {
		if (map[i].fmt == fmt)
			return map[i].fn;
		++i;
	}
	return NULL;
}
