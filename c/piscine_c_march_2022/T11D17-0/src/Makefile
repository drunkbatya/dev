CC = gcc
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell cd ../build && pwd)

all: door_struct list_test stack_test

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) dmanager_module.o -o $(OUT_DIR)/Quest_1

list_test: list.o list_test.o
	$(CC) $(CFLAGS) list.o list_test.o -o $(OUT_DIR)/Quest_2

stack_test: stack.o stack_test.o
	$(CC) $(CFLAGS) stack.o stack_test.o -o $(OUT_DIR)/Quest_3

dmanager_module.o: dmanager_module.c door_struct.h
	$(CC) $(CFLAGS) -c dmanager_module.c -o dmanager_module.o

list_test.o: list_test.c
	$(CC) $(CFLAGS) -c list_test.c -o list_test.o

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c -o list.o

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm -f *.o $(OUT_DIR)/*
