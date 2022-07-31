/*
	Cálculo da média.
*/
#include <stdio.h>
#define TAMANHO 4
double precos[] = {1500, 1100, 750, 500};

int main() {
   double media = 0;
   int i;
   for (i=0; i<TAMANHO; i++){
      media += precos[i];
   }
   media = media/TAMANHO;
   printf("%8.2f\n", media);
   return 0;
}



/* SAIDA
  962.50
*/