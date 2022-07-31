/*
	Acesso a posições incorretas/inválidas do arranjo.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   double* precos = (double*) malloc(sizeof(double)*4);
   printf("%8.2f\n", precos[-1]);
   printf("%8.2f\n", precos[4]);
   return 0;
}


/* SAIDA (pode variar de acordo com a execução)
    0.00
    0.00
*/