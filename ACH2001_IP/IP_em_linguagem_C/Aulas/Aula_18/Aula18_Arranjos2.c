/*
	Programa que cria um arranjo usando alocação dinâmica de memória.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   double* precos = (double*) malloc(sizeof(double)*4);
   precos[0] = 1500;
   precos[1] = 1100;
   precos[2] = 750;
   precos[3] = 500;
   
   
   return 0;
}
  
