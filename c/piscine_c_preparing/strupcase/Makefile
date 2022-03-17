all: build run clean

build:
	gcc main.c db_strupcase.c ../putstr/db_putstr.c ../strcpy/db_strcpy.c -o db_strupcase

run:
	./db_strupcase

clean:
	rm -f ./db_strupcase
