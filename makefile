all: main.o
	gcc -o pointers main.o

main.o: main.c
	gcc -c main.c

run:
	./pointer*