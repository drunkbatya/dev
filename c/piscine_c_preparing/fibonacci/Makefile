all: build run clean

build:
	gcc main.c db_fibonacci.c ../putnbr/db_putnbr.c -o db_fibonacci

run:
	./db_fibonacci

clean:
	rm -f ./db_fibonacci
