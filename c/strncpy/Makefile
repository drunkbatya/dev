all: build run clean

build:
	gcc main.c db_strncpy.c ../putstr/db_putstr.c ../putnbr/db_putnbr.c -o db_strncpy

run:
	./db_strncpy

clean:
	rm -f ./db_strncpy
