CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell cd ../build && pwd)

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests strtok_tests

rebuild: clean all

strlen_tests: s21_strlen_test.o s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) s21_strlen_test.o s21_string_test.o s21_string.o -o $(OUT_DIR)/Quest_1

strcmp_tests: s21_strcmp_test.o s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) s21_strcmp_test.o s21_string_test.o s21_string.o -o $(OUT_DIR)/Quest_2

strcpy_tests: s21_strcpy_test.o s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) s21_strcpy_test.o s21_string_test.o s21_string.o -o $(OUT_DIR)/Quest_3

strcat_tests: s21_strcat_test.o s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) s21_strcat_test.o s21_string_test.o s21_string.o -o $(OUT_DIR)/Quest_4

strchr_tests: s21_strchr_test.o s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) s21_strchr_test.o s21_string_test.o s21_string.o -o $(OUT_DIR)/Quest_5

strstr_tests: s21_strstr_test.o s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) s21_strstr_test.o s21_string_test.o s21_string.o -o $(OUT_DIR)/Quest_6

strtok_tests: s21_strtok_test.o s21_string_test.o s21_string.o
	$(CC) $(CFLAGS) s21_strtok_test.o s21_string_test.o s21_string.o -o $(OUT_DIR)/Quest_7

s21_strlen_test.o: s21_strlen_test.c
	$(CC) $(CFLAGS) -c s21_strlen_test.c -o s21_strlen_test.o

s21_strcmp_test.o: s21_strcmp_test.c
	$(CC) $(CFLAGS) -c s21_strcmp_test.c -o s21_strcmp_test.o

s21_strcpy_test.o: s21_strcpy_test.c
	$(CC) $(CFLAGS) -c s21_strcpy_test.c -o s21_strcpy_test.o

s21_strcat_test.o: s21_strcat_test.c
	$(CC) $(CFLAGS) -c s21_strcat_test.c -o s21_strcat_test.o

s21_strchr_test.o: s21_strchr_test.c
	$(CC) $(CFLAGS) -c s21_strchr_test.c -o s21_strchr_test.o

s21_strstr_test.o: s21_strstr_test.c
	$(CC) $(CFLAGS) -c s21_strstr_test.c -o s21_strstr_test.o

s21_strtok_test.o: s21_strtok_test.c
	$(CC) $(CFLAGS) -c s21_strtok_test.c -o s21_strtok_test.o

s21_string_test.o: s21_string_test.c s21_string_test.h
	$(CC) $(CFLAGS) -c s21_string_test.c -o s21_string_test.o

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o

out_dir:
	mkdir -p $(OUT_DIR)

clean:
	rm -f *.o $(OUT_DIR)/*
