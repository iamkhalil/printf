#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include "utils.h"

#define NULL ((void *)0)

typedef struct fields {
        /* Flags */
        unsigned short is_plus   :1;
        unsigned short is_space  :1;
        unsigned short is_hash   :1;
        /* Length modifiers */
        unsigned short is_l_mod  :1;
        unsigned short is_h_mod  :1;
        /* Width */
        int width;
} fields_t;

typedef struct fmt {
        char fmt;
        int (*fn)(va_list, const fields_t *);
} fmt_t;

/* Function prototypes */
int _printf(const char *format, ...);
int (*get_fmt_func(char fmt))(va_list, const fields_t *);

/* Format specifiers functions */
int print_char(va_list ap, const fields_t *fields);
int print_string(va_list ap, const fields_t *fields);
int print_int(va_list ap, const fields_t *fields);
int print_unsigned_int(va_list ap, const fields_t *fields);
int print_unsigned_int_rec(unsigned long ui, unsigned int len);
int print_octal(va_list ap, const fields_t *fields);
int print_hex(va_list ap, const fields_t *fields, enum letcase letcase);
int print_hex_uppercase(va_list ap, const fields_t *fields);
int print_hex_lowercase(va_list ap, const fields_t *fields);
int print_percent(va_list ap, const fields_t *fields);
int print_address(va_list ap, const fields_t *fields);

/* Custom format specifiers functions */
int print_binary(va_list ap, const fields_t *fields);
int print_binary_rec(unsigned int x, unsigned int len);
int print_S(va_list ap, const fields_t *fields);

/* fields handlers */
int update_flags(fields_t *fields, char flag);
int update_length_modifiers(fields_t *fields, char mod);
int update_width(fields_t *fields, va_list ap, const char * const s);
void reset_fields(fields_t *fields);

#endif /* PRINTF_H */
