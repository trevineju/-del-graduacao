/*
	Programa que apresenta exemplos dos endereços de memórias das variáveis.
	Uso de alocação dinâmica de memória com a função malloc.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* end3 = (int*) malloc(sizeof(int));
   *end3 = 11;
   printf("Valor de end3: %p\n",end3);
   printf("Endereço de end3: %p\n",&end3);
   printf("Conteúdo apontado por end3: %i\n",*end3);
   return 0;
}


/* SAIDA
Valor de end3: 0x22af260
Endereço de end3: 0x7fffd942d860
Conteúdo apontado por end3: 11
*/