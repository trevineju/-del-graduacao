/*
	Exemplo das expressões contraídas ++ e --
*/
#include <stdio.h>

int main() {
   int x = 1;
   int y = x++ + 4;
   printf("x = %i, y = %i\n", x, y);
   int z = ++x + 4;
   printf("x = %i, z = %i\n", x, z);
   return 0;
}

/* SAIDA
x = 2, y = 5
x = 3, z = 7
*/