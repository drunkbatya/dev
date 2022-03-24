CC = gcc
CFLAGS = -Wall -Wextra -Werror
OUT_DIR = $(shell cd ../build && pwd)

build: all

all: cipher loggin_cipher

cipher: cipher.c
	$(CC) $(CFLAGS) cipher.c -o $(OUT_DIR)/cipher

loggin_cipher: cipher.c logger.c
	$(CC) $(CFLAGS) cipher.c logger.c -DLOG -o $(OUT_DIR)/logging_cipher

clean:
	rm -f *.o $(OUT_DIR)/*

rebuild: clean build
