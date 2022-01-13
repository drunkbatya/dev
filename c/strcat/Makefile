all: build run clean

build:
	gcc main.c db_strcat.c ../strcpy/db_strcpy.c ../putstr/db_putstr.c -o db_strcat

run:
	./db_strcat

clean:
	rm -f ./db_strcat
