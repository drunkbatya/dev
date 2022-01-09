all: build run clean

build:
	gcc main.c ../putstr/db_putstr.c ../putnbr/db_putnbr.c db_div_mod.c -o db_div_mod

run:
	./db_div_mod

clean:
	rm -f ./db_div_mod
