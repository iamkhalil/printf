#include "printf.h"

/**
 * update_flags - Update a flag of the struct fields when it matches a flag.
 * @fields: pointer to a struct fields
 * @flag: the given flag
 *
 * Return: if a member gets updated, 1 is returned. 0 otherwise.
 */
int update_flags(fields_t *fields, char flag)
{
	int ret;

	switch (flag) {
	case '+':
		fields->is_plus = 1;
		ret = 1;
		break;
	case ' ':
		fields->is_space = 1;
		ret = 1;
		break;
	case '#':
		fields->is_hash = 1;
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

/**
 * update_length_modifiers - Update the length modifier of the struct fields
 * when it matches the given modifier.
 * @fields: pointer to a struct fields
 * @mod: the given modifier
 *
 * Return: if a member gets updated, 1 is returned. 0 otherwise.
 */
int update_length_modifiers(fields_t *fields, char mod)
{
	int ret;

	switch (mod) {
	case 'l':
		fields->is_l_mod = 1;
		ret = 1;
		break;
	case 'h':
		fields->is_h_mod = 1;
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

/**
 * update_width - Get the width number, and update the width member of the
 * struct fields.
 * @fields: pointer to a struct fields
 * @s: pointer to character string
 *
 * Return: number of characters that format has to skip.
 */
int update_width(fields_t *fields, va_list ap, const char * const s)
{
	unsigned int width = 0;
	const char *sp = s;

	if (*sp == '*') {
		width = va_arg(ap, unsigned int);
		++sp;
	} else { /* number */
		while (*sp >= '0' && *sp <= '9')
			width = (width * 10) + (*sp++ - '0');
	}
	fields->width = width;
	return sp - s;
}

/**
 * reset_fields - Reset the values of all struct fields members to zero.
 * @fields: pointer to a struct fields
 */
void reset_fields(fields_t *fields)
{
	fields->is_plus  = 0;
	fields->is_space = 0;
	fields->is_hash  = 0;
	fields->is_l_mod = 0;
	fields->is_h_mod = 0;
	fields->width	 = 0;
}
