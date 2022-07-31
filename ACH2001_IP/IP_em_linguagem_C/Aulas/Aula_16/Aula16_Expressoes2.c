/*
	Exemplo das expressões contraídas ++ e --
*/
#include <stdio.h>

int main() {
   int x = 2;
   int y = 2;
   printf("x = %i, y = %i\n", x++, ++y);
   printf("x = %i, y = %i\n", x, y);
   return 0;
}

/* SAIDA
x = 2, y = 3
x = 3, y = 3
*/