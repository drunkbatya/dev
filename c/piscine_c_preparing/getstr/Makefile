all: build run clean

build:
	gcc main.c db_getstr.c ../putstr/db_putstr.c -o db_getstr

run:
	./db_getstr

clean:
	rm -f ./db_getstr
