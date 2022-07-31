/*
	Programa que cria um primeiro arranjo com quatro elementos e imprime
	seus valores.
*/
#include <stdio.h>

int main() {
   double precos[] = {1500, 1100, 750, 500};
   int i;
   for (i=0; i<4; i++){
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