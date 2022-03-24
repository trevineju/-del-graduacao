CFLAGS= -O3 -W -Wall -ansi -pedantic
CC = gcc

all: sieve
	rm -rf *.o

sieve: sieve.c
	$(CC) $(CFLAGS) -o sieve sieve.c

clean:
	rm -rf *.o sieve
