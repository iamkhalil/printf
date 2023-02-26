CC=gcc
CFLAGS= -Wall -Wextra -Werror -pedantic -Wno-format -fsanitize=signed-integer-overflow
SRC= $(wildcard *.c)

all: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o output

.PHONY: clean

clean:
	rm output
