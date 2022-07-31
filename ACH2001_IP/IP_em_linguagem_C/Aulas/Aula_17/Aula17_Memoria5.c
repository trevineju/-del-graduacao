/*
	Programa que apresenta exemplos dos endereços de memórias das variáveis.
	Uso de alocação dinâmica de memória com a função malloc e liberação com
	a função free.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* end3 = (int*) malloc(sizeof(int));
   *end3 = 11;
   free(end3);
   printf("Valor de end3: %p\n",end3);
   printf("Endereço de end3: %p\n",&end3);
   printf("Conteúdo apontado por end3: %i\n",*end3);
   return 0;
}


/* SAIDA (o conteúdo de end3 pode variar de acordo com a execução)
Valor de end3: 0x1f3c260
Endereço de end3: 0x7ffd1ccd1f20
Conteúdo apontado por end3: 0
*/