CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: data_module_entry

data_module_entry: data_module_entry.o data_process.o data_io.o data_stat.o
	$(CC) $(CFLAGS) data_module_entry.o data_process.o data_io.o data_stat.o -o data_module_entry

data_stat.o:
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o data_stat.o

data_io.o:
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c -o data_io.o

data_module_entry.o:
	$(CC) $(CFLAGS) -c data_module_entry.c -o data_module_entry.o

data_process.o:
	$(CC) $(CFLAGS) -c data_process.c -o data_process.o

clean:
	rm -f *.o data_module_entry
