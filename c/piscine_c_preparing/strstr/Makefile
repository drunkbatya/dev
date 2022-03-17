all: build run clean

build:
	gcc main.c db_strstr.c ../putstr/db_putstr.c ../strcpy/db_strcpy.c -o db_strstr

run:
	./db_strstr

clean:
	rm -f ./db_strstr
