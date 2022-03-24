CC = gcc
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell cd ../build && pwd)

build: all

all: print_module documentation_module bst_create_test bst_insert_test bst_traverse_test

print_module: print_module.o main_module_entry_point.c
	$(CC) $(CFLAGS) print_module.o main_module_entry_point.c -DPRINT_MODULE -o $(OUT_DIR)/Quest_1

documentation_module: documentation_module.o main_module_entry_point.c print_module.o
	$(CC) $(CFLAGS) documentation_module.o main_module_entry_point.c -DDOCUMENTATION_MODULE print_module.o -o $(OUT_DIR)/Quest_2

bst_create_test: bst_create_test.o bst.o
	$(CC) $(CFLAGS) bst_create_test.o bst.o -o $(OUT_DIR)/Quest_3

bst_insert_test: bst_insert_test.o bst.o
	$(CC) $(CFLAGS) bst_insert_test.o bst.o -o $(OUT_DIR)/Quest_4

bst_traverse_test: bst_traverse_test.o bst.o
	$(CC) $(CFLAGS) bst_traverse_test.o bst.o -o $(OUT_DIR)/Quest_5

print_module.o: print_module.c print_module.h
	$(CC) $(CFLAGS) -c print_module.c -o print_module.o

documentation_module.o: documentation_module.c documentation_module.h
	$(CC) $(CFLAGS) -c documentation_module.c -o documentation_module.o

bst_create_test.o: bst_create_test.c
	$(CC) $(CFLAGS) -c bst_create_test.c -o bst_create_test.o

bst_insert_test.o: bst_insert_test.c
	$(CC) $(CFLAGS) -c bst_insert_test.c -o bst_insert_test.o

bst_traverse_test.o: bst_traverse_test.c
	$(CC) $(CFLAGS) -c bst_traverse_test.c -o bst_traverse_test.o

bst.o: bst.c bst.h
	$(CC) $(CFLAGS) -c bst.c -o bst.o

clean:
	rm -f *.o $(OUT_DIR)/*

rebuild: clean build
