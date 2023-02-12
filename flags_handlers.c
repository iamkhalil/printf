#include "printf.h"

/**
 * update_flags - Update a member of the flags struct when it matches a flag.
 * @flags: pointer to a struct flags
 * @flag: the given flag
 *
 * Return: if a member gets updated, 1 is returned. 0 otherwise.
 */
int update_flags(flags_t *flags, char flag)
{
	int ret;

	switch (flag) {
	case '+':
		flags->is_plus = 1;
		ret = 1;
		break;
	case ' ':
		flags->is_space = 1;
		ret = 1;
		break;
	case '#':
		flags->is_hash = 1;
		ret = 1;
		break;
	case 'l':
		flags->is_l_mod = 1;
		ret = 1;
		break;
	case 'h':
		flags->is_h_mod = 1;
		ret = 1;
		break;
	default:
		ret = 0;
		break;
	}
	return ret;
}

/**
 * reset_flags - Reset the values of all struct flags members to zero.
 * @flags: pointer to a struct flags
 */
void reset_flags(flags_t *flags)
{
	flags->is_plus  = 0;
	flags->is_space = 0;
	flags->is_hash  = 0;
	flags->is_l_mod = 0;
	flags->is_h_mod = 0;
}
