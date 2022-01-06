all: build run clean

build:
	gcc main.c db_rev_int_tab.c ../putnbr/db_putnbr.c ../putchar/db_putchar.c -o db_rev_int_tab

run:
	./db_rev_int_tab

clean:
	rm -f ./db_rev_int_tab
