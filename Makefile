CC= gcc
CFLAGS= -Wall -Wextra -Werror -pedantic -fsanitize=signed-integer-overflow
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
LIBNAME= libprintf.a

all: $(SRC)
	$(CC) -c $(CFLAGS) $(SRC)
	ar rcs $(LIBNAME) $(OBJ)
	@echo "$(LIBNAME) created successfully."

.PHONY: clean

clean:
	rm -f $(OBJ) $(LIBNAME)
