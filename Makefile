CC=gcc
CFLAGS= -Wall -Wextra -Werror -pedantic -fsanitize=signed-integer-overflow
SRC= $(wildcard *.c)

all: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o output

.PHONY: clean

clean:
	rm output
