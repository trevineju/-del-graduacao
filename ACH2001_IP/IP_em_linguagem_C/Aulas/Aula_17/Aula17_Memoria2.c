/*
	Programa que apresenta exemplos dos endereços de memórias das variáveis.
*/
#include <stdio.h>

int main() {
   int var1 = 25;
   int* end1 = &var1;
   printf("Valor de var1: %i\n",var1);
   printf("Endereço de var1: %p\n",&var1);
   printf("Valor de end1: %p\n",end1);
   printf("Endereço de end1: %p\n",&end1);
   *end1 = 12;
   printf("Valor de var1: %i\n",var1);
   printf("Endereço de var1: %p\n",&var1);
   printf("Valor de end1: %p\n",end1);
   printf("Endereço de end1: %p\n",&end1);
   printf("Conteúdo apontado por end1: %i\n",*end1);
   return 0;
}


/* SAIDA
Valor de var1: 25
Endereço de var1: 0x7ffca515b548
Valor de end1: 0x7ffca515b548
Endereço de end1: 0x7ffca515b540
Valor de var1: 12
Endereço de var1: 0x7ffca515b548
Valor de end1: 0x7ffca515b548
Endereço de end1: 0x7ffca515b540
Conteúdo apontado por end1: 12
*/