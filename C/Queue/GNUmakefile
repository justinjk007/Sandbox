CC      = gcc
CFLAGS  = -g -Wall -Wextra
CSTANDARD = -std=c11
BIN	= ./bin

$(shell mkdir -p $(BIN)) # Create bin directory automatically

default: main

main: main.c
	$(CC) $(CFLAGS) $(CSTANDARD) -o $(BIN)/main main.c

.PHONY: clean

clean:
	rm -f $(BIN)
