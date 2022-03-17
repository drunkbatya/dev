CC = gcc
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell pwd)

all: build

build: list_test stack_test

list_test: list.o list_test.o
	$(CC) $(CFLAGS) list.o list_test.o -o $(OUT_DIR)/list_test

stack_test: stack.o stack_test.o
	$(CC) $(CFLAGS) stack.o stack_test.o -o $(OUT_DIR)/stack_test

list_test.o: list_test.c
	$(CC) $(CFLAGS) -c list_test.c -o list_test.o

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c -o list.o

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm -f *.o list_test stack_test

rebuild: clean build
