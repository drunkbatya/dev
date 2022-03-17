all: build run clean

build:
	gcc main.c db_strncmp.c ../putnbr/db_putnbr.c ../strcpy/db_strcpy.c -o db_strncmp

run:
	./db_strncmp

clean:
	rm -f ./db_strncmp
