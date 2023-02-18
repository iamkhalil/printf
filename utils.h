#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>

#define BUFSIZE  1024
#define FLUSHBUF (-1)
#define CAPACITY 32

enum letcase { LOWERCASE, UPPERCASE, NONE };

int _putchar(char c);
int _puts(char *s);
int _puts_without_newline(char *s);
unsigned int _strlen(const char *s);
char *_strncpy(char *dest, const char *src, unsigned int n);
char *convert_number(char *res, unsigned long n, unsigned short base, enum letcase letcase);
void reverse_array(char *arr, unsigned int size);

#endif /* UTILS_H */
