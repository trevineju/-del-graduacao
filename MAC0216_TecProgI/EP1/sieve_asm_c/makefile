CFLAGS =  -O3 -W -Wall -ansi -pedantic
CC = gcc

all: sieve_asm
	rm -rf *.o

sieve_asm: is_prime.o sieve_asm.c
	$(CC) $(CFLAGS) -o sieve_asm is_prime.o sieve_asm.c -m32

is_prime.o: is_prime.s
	nasm -f elf is_prime.s

clean:
	rm -rf *.o sieve_asm
