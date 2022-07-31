/*
	Programa que cria um arranjo com quatro elementos e imprime
	seus valores usando um laço for.
*/
#include <stdio.h>

const int ALVENARIA = 0;
const int VINIL = 1;
const int FIBRA = 2;
const int PLASTICO = 3;

int main() {
   double precos[] = {1500, 1100, 750, 500};
   int i;
   for (i=ALVENARIA; i<=PLASTICO; i++){
      printf("%8.2f\n", precos[i]);
   }
   return 0;
}


/* SAIDA
 1500.00
 1100.00
  750.00
  500.00
*/