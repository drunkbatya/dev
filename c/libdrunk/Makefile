CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: libdrunk.a

libdrunk.a: db_putchar.o db_getchar.o db_swap.o db_strcmp.o db_getstr.o db_putstr.o db_strlen.o db_strnlcut.o
	ar rc libdrunk.a srcs/db_putchar.o srcs/db_getchar.o srcs/db_swap.o srcs/db_strcmp.o srcs/db_getstr.o srcs/db_putstr.o srcs/db_strlen.o srcs/db_strnlcut.o

db_putchar.o:
	$(CC) $(CFLAGS) -c srcs/db_putchar.c -o srcs/db_putchar.o

db_getchar.o:
	$(CC) $(CFLAGS) -c srcs/db_getchar.c -o srcs/db_getchar.o

db_swap.o:
	$(CC) $(CFLAGS) -c srcs/db_swap.c -o srcs/db_swap.o

db_strcmp.o:
	$(CC) $(CFLAGS) -c srcs/db_strcmp.c -o srcs/db_strcmp.o

db_getstr.o:
	$(CC) $(CFLAGS) -c srcs/db_getstr.c -o srcs/db_getstr.o

db_putstr.o:
	$(CC) $(CFLAGS) -c srcs/db_putstr.c -o srcs/db_putstr.o

db_strlen.o:
	$(CC) $(CFLAGS) -c srcs/db_strlen.c -o srcs/db_strlen.o

db_strnlcut.o:
	$(CC) $(CFLAGS) -c srcs/db_strnlcut.c -o srcs/db_strnlcut.o

fclean: clean
	rm -f libdrunk.a

clean:
	rm -f srcs/*.o

re: fclean all
