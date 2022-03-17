all: build run clean

build:
	gcc main.c db_str_is_numeric.c ../putnbr/db_putnbr.c ../putchar/db_putchar.c ../strcpy/db_strcpy.c -o ./db_str_is_numeric

run:
	./db_str_is_numeric

clean:
	rm -f ./db_str_is_numeric
