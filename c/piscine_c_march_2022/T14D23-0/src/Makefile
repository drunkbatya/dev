CC = gcc
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell cd ../build && pwd)

all: state_sort

state_sort: state_sort.o
	$(CC) $(CFLAGS) state_sort.o -o $(OUT_DIR)/Quest_1

state_sort.o: state_sort.c state_sort.h
	$(CC) $(CFLAGS) -c state_sort.c -o state_sort.o

clean:
	rm -f *.o $(OUT_DIR)/*
