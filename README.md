# printf

An implementation of the `printf` function as defined by the C89 standard with
some custom format specifiers.

## Description

The `printf` function converts, formats, and writes it's arguments to `stdout`
under the control of `format`. On success, it returns the number of characters
written, or a negative value if an error occured. <br>
The `format` string contains two types of objects: ordinary characters, which are
copied to the output stream, and format specifiers, each of which causes
conversion and printing of the next successive argument to printf. <br>
A `format `specifier follows this prototype: `%[flags][width][.precision][length]specifier`

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

## Author
- **Mohamed khalil El-Bechir** - [medkhalilelb@gmail.com](medkhalilelb@gmail.com) | [GitHub/iamkhalil](https://github.com/iamkhalil)
## Licence
MIT License
