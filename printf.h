#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include "utils.h"

#define NULL ((void *)0)

typedef struct fmt {
    char fmt;
    int (*fn)(va_list);
} fmt_t;


int _printf(const char *format, ...);
int (*get_fmt_func(char fmt))(va_list);

/* Format specifiers functions */
int print_char(va_list ap);
int print_string(va_list ap);
int print_int(va_list ap);
int print_unsigned_int(va_list ap);
int print_unsigned_int_rec(unsigned int ui, unsigned int len);
int print_octal(va_list ap);

/* Custom functions */
int print_binary(va_list ap);
int print_binary_rec(unsigned int x, unsigned int len);

#endif /* PRINTF_H */
