all: build run clean

build:
	gcc main.c db_putstr_non_printable.c ../strcpy/db_strcpy.c -o db_putstr_non_printable

run:
	./db_putstr_non_printable

clean:
	rm -f ./db_putstr_non_printable
