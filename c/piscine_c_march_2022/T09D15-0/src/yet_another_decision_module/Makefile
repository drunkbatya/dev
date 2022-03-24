CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: yet_another_decision_module_entry

yet_another_decision_module_entry: yet_another_decision_module_entry.o decision.o data_io.o data_stat.o
	$(CC) $(CFLAGS) yet_another_decision_module_entry.o data_io.o data_stat.o decision.o -o yet_another_decision_module_entry

data_stat.o:
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o data_stat.o

data_io.o:
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c -o data_io.o

yet_another_decision_module_entry.o:
	$(CC) $(CFLAGS) -c yet_another_decision_module_entry.c -o yet_another_decision_module_entry.o

decision.o:
	$(CC) $(CFLAGS) -c decision.c -o decision.o

clean:
	rm -f $(wildcard *.o) yet_another_decision_module_entry
