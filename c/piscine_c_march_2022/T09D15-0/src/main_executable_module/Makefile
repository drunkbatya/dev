CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell cd ../../build && pwd)

all: main_executable_module

rebuild: clean main_executable_module

main_executable_module: out_dir main_executable_module.o data_process.o data_sort.o data_io.o data_stat.o decision.o
	$(CC) $(CFLAGS) main_executable_module.o data_sort.o data_stat.o data_io.o decision.o data_process.o -o $(OUT_DIR)/Quest_3

build_with_static: out_dir data_stat.a main_executable_module.o data_process.o data_sort.o data_io.o decision.o
	$(CC) $(CFLAGS) data_stat.a main_executable_module.o data_sort.o data_io.o decision.o data_process.o -o $(OUT_DIR)/Quest_5

build_with_dynamic: out_dir data_process.so main_executable_module.o data_sort.o data_io.o data_stat.o decision.o
	$(CC) $(CFLAGS) $(OUT_DIR)/data_process.so main_executable_module.o data_sort.o data_io.o decision.o data_stat.o -o $(OUT_DIR)/Quest_6

main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c -o main_executable_module.o

data_process.o: ../data_module/data_process.c ../data_module/data_process.h
	$(CC) $(CFLAGS) -c ../data_module/data_process.c -o data_process.o

data_process_pic.o: ../data_module/data_process.c ../data_module/data_process.h
	$(CC) $(CFLAGS) -fPIC -c ../data_module/data_process.c -o data_process_pic.o

data_stat_pic.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	$(CC) $(CFLAGS) -fPIC -c ../data_libs/data_stat.c -o data_stat_pic.o

data_sort.o: ../data_libs/data_sort.c ../data_libs/data_sort.h
	$(CC) $(CFLAGS) -c ../data_libs/data_sort.c -o data_sort.o

data_stat.o: ../data_libs/data_stat.c ../data_libs/data_stat.h
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o data_stat.o

data_io.o: ../data_libs/data_io.c ../data_libs/data_stat.h
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c -o data_io.o

decision.o: ../yet_another_decision_module/decision.c ../yet_another_decision_module/decision.h
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c -o decision.o

data_stat.a: data_stat.o
	$(AR) -rcs data_stat.a data_stat.o

data_process.so: data_process_pic.o data_stat_pic.o
	$(CC) $(CFLAGS) -shared data_process_pic.o data_stat_pic.o -o $(OUT_DIR)/data_process.so

out_dir:
	mkdir -p $(OUT_DIR)

clean:
	rm -f *.o *.a $(OUT_DIR)/*
