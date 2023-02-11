#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include "utils.h"

#define NULL ((void *)0)

enum letcase { LOWERCASE, UPPERCASE };

typedef struct flags {
        unsigned short is_plus   :1;
        unsigned short is_space  :1;
} flags_t;

typedef struct fmt {
        char fmt;
        int (*fn)(va_list, const flags_t *);
} fmt_t;

/* Function prototypes */
int _printf(const char *format, ...);
int (*get_fmt_func(char fmt))(va_list, const flags_t *);

/* Format specifiers functions */
int print_char(va_list ap, const flags_t *flags);
int print_string(va_list ap, const flags_t *flags);
int print_int(va_list ap, const flags_t *flags);
int print_unsigned_int(va_list ap, const flags_t *flags);
int print_unsigned_int_rec(unsigned int ui, unsigned int len);
int print_octal(va_list ap, const flags_t *flags);
int print_hex(unsigned long ui, unsigned int size, enum letcase letcase);
int print_hex_uppercase(va_list ap, const flags_t *flags);
int print_hex_lowercase(va_list ap, const flags_t *flags);
int print_percent(va_list ap, const flags_t *flags);
int print_address(va_list ap, const flags_t *flags);

/* Custom format specifiers functions */
int print_binary(va_list ap, const flags_t *flags);
int print_binary_rec(unsigned int x, unsigned int len);
int print_S(va_list ap, const flags_t *flags);

/* flags handlers */
int update_flags(flags_t *flags, char c);
void reset_flags(flags_t *flags);

#endif /* PRINTF_H */
