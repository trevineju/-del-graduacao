/*
	Tentativa de acesso a memória que não foi alocada.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   double* precos;
   printf("%8.2f\n", precos[1]);
   return 0;
}

/* SAIDA (erro de execução)
Segmentation fault (core dumped)
*/