all: build run clean

build:
	gcc main.c db_strlen.c ../putnbr/db_putnbr.c ../putchar/db_putchar.c -o db_strlen

run:
	./db_strlen

clean:
	rm -f db_strlen
