all: build run clean

build:
	gcc main.c db_strcmp.c ../putnbr/db_putnbr.c ../strcpy/db_strcpy.c -o db_strcmp

run:
	./db_strcmp

clean:
	rm -f ./db_strcmp
