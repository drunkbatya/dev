all: build run clean

build:
	gcc main.c db_strcpy.c ../putstr/db_putstr.c -o db_strcpy

run:
	./db_strcpy

clean:
	rm -f ./db_strcpy
