# printf

An implementation of the `printf` function as defined by the C89 standard with
some custom format specifiers.

## Description

The `printf` function converts, formats, and writes it's arguments to `stdout`
under the control of `format`. <br>
On success, it returns the number of characters written, or a negative
value if an error occured. <br>
The `format` string contains two types of objects: ordinary characters, which are
copied to the output stream, and format specifiers, each of which causes
conversion and printing of the next successive argument to printf. <br>
A `format` specifier follows this prototype: `%[flags][width][.precision][length]specifier`

## Features

This section covers all the format specifiers and sub-specifiers supported by
our `_printf` function.

#### Format Specifiers

| specifier | Output                                                                          |
| --------  | -----------                                                                     |
| %d or %i  | Signed decimal integer                                                          |
| %u        | Unsigned decimal integer                                                        |
| %o        | Unsigned octal                                                                  |
| %x        | Unsigned hexadecimal integer (lowercase)                                        |
| %X        | Unsigned hexadecimal integer (uppercase)                                        |
| %c        | Single character                                                                |
| %s        | String of characters                                                            |
| %p        | Pointer address                                                                 |
| %%        | Single %                                                                        |
| %b        | Unsigned binary integer                                                         |
| %r        | Reversed string                                                                 |
| %R        | Rot13'd string                                                                  |
| %S        | String of characters, non-printable characters are converted to their hex value |

#### Sub-specifiers

**1. Flags:**
- [x] minus flag
- [x] plus flag
- [x] space flag
- [x] zero flag
- [x] hash flag

**2. Width:**
- [x] number
- [x] asterisk

**3. Precision:**
- [x] .number
- [x] asterisk

**4. Length Modifiers:**
- [x] h
- [x] l (ell)

## Usage

The simplest way to add our `_printf` function to your project is by cloning
the source code into your own project tree, then creating a static library from
it:
```shell
$ git clone https://github.com/iamkhalil/printf.git
$ cd printf
$ make
```
You can now use our `_printf` as a static library with your C applications:
```shell
$ gcc myapp.c -L. -lprintf -o myapp
```

## Examples
```
$ cat myapp.c
#include <stdio.h>
#include "printf.h"

int main(void)
{
	const char* s = "Hello";
	int real, mine;
	void *addr;

	real = printf("Hello, world!\n");
	mine = _printf("Hello, world!\n");
	_printf("Length: [%d, %d]\n", real, mine);

	printf("Strings:\n");
	printf(" padding:\n");
	_printf(" padding:\n");
	printf("\t[%10s]\n", s);
	_printf("\t[%10s]\n", s);
	printf("\t[%-10s]\n", s);
	_printf("\t[%-10s]\n", s);
	printf("\t[%*s]\n", 10, s);
	_printf("\t[%*s]\n", 10, s);
	printf(" truncating:\n");
	_printf(" truncating:\n");
	printf("\t%.4s\n", s);
	_printf("\t%.4s\n", s);
	printf("\t%.*s\n", 3, s);
	_printf("\t%.*s\n", 3, s);

	printf("Characters:\t%c %%\n", 'A');
	_printf("Characters:\t%c %%\n", 'A');

	printf("Integers:\n");
	_printf("Integers:\n");
	real = printf("\tDecimal:\t%i %d %.6i %i %.0i %+i %i\n", 1, 2, 3, 0, 0, 4, -4);
	mine = _printf("\tDecimal:\t%i %d %.6i %i %.0i %+i %i\n", 1, 2, 3, 0, 0, 4, -4);
	_printf("Length: [%d, %d]\n", real, mine);
	printf("\tUnsigned:\t%6.4u\n", 42);
	_printf("\tUnsigned:\t%6.4u\n", 42);
	printf("\tHexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
	_printf("\tHexadecimal:\t%x %x %X %#x\n", 5, 10, 10, 6);
	printf("\tOctal:\t\t%o %#o %#o\n", 10, 10, 4);
	_printf("\tOctal:\t\t%o %#o %#o\n", 10, 10, 4);

	addr = (void *)0x7fff1038675c;
	printf("Address:[%p]\n", addr);
	_printf("Address:[%p]\n", addr);

	printf("Custom format specifiers:\n");
	_printf("Reverse:\t[%r]\n", "Live");
	_printf("Rot13:\t[%R]\n", "SHA");

	return 0;
}

$ gcc -Wall -Werror -Wextra -pedanitc *.c -o myapp
$ ./myapp
Hello, world!
Hello, world!
Length: [14, 14]
Strings:
 padding:
 padding:
	[     Hello]
	[     Hello]
	[Hello     ]
	[Hello     ]
	[     Hello]
	[     Hello]
 truncating:
 truncating:
	Hell
	Hell
	Hel
	Hel
Characters:	A %
Characters:	A %
Integers:
Integers:
	Decimal:	1 2 000003 0  +4 -4
	Decimal:	1 2 000003 0  +4 -4
Length: [30, 30]
	Unsigned:	  0042
	Unsigned:	  0042
	Hexadecimal:	5 a A 0x6
	Hexadecimal:	5 a A 0x6
	Octal:		12 012 04
	Octal:		12 012 04
Address:[0x7fff1038675c]
Address:[0x7fff1038675c]
Custom format specifiers:
Reverse:	[eviL]
Rot13:	[FUN]

```

## Author
- **Mohamed khalil El-Bechir** - [medkhalilelb@gmail.com](medkhalilelb@gmail.com) | [GitHub/iamkhalil](https://github.com/iamkhalil)
## Licence
MIT License
