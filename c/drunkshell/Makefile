all: build run clean

build:
	gcc main.c drunkshell.c commands.c -L../libdrunk -ldrunk -o drunkshell

run:
	./drunkshell

clean:
	rm -f ./drunkshell
