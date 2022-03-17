all: build run clean

build:
	gcc main.c db_strlowcase.c ../putstr/db_putstr.c ../strcpy/db_strcpy.c -o db_strlowcase

run:
	./db_strlowcase

clean:
	rm -f ./db_strlowcase
