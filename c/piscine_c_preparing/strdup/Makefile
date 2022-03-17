all: build run clean

build:
	gcc main.c db_strdup.c ../putstr/db_putstr.c -o db_strdup

run:
	./db_strdup

clean:
	rm -f ./db_strdup
