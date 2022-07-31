/*
	Programa que apresenta exemplos dos endereços de memórias das variáveis.
	O símbolo * é usado com três significados diferentes.
*/
#include <stdio.h>

int main() {
   int var2 = 3 * 4;
   int* end2 = &var2;
   printf("Valor resultante: %i\n", *end2);
   return 0;
}


/* SAIDA
Valor resultante: 12
*/