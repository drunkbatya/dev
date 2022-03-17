all: build run clean

build:
	gcc main.c db_strlcat.c ../putstr/db_putstr.c ../strcpy/db_strcpy.c -o db_strlcat

run:
	./db_strlcat

clean:
	rm -f ./db_strlcat
