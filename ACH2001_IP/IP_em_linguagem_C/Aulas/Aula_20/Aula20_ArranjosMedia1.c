/*
	Programa que cria um arranjo utilizando alocação dinâmica de memória
	com quatro elementos e imprime a média dos valores.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  double* precos = (double*) malloc(sizeof(double)*4);
  precos[0] = 1500;
  precos[1] = 1100;
  precos[2] = 750;
  precos[3] = 500;

  double media = 0;
  int i;
  for (i=0;i<4;i++) media += precos[i];
  media = media/4;

  printf("%8.2f\n", media);
  return 0;
}



/* SAIDA
  962.50
*/