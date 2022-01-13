all: build run clean

build:
	gcc main.c db_strncat.c ../strcpy/db_strcpy.c ../putstr/db_putstr.c -o db_strncat

run:
	./db_strncat

clean:
	rm -f ./db_strncat
