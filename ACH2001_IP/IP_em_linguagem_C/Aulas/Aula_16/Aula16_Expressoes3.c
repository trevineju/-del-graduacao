/*
	Exemplo das expressões contraídas ++ e --
*/
#include <stdio.h>

int main() {
   int x = 2;
   int y = 2;
   printf("x = %i, y = %i\n", x--, --y);
   printf("x = %i, y = %i\n", x, y);
   return 0;
}

/* SAIDA
x = 2, y = 1
x = 1, y = 1
*/