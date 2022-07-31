/*
	Programa que cria um arranjo utilizando alocação dinâmica de memória
	com quatro elementos e imprime a média dos valores usando uma função
	auxiliar.
*/
#include <stdio.h>
#include <stdlib.h>

double media(double* arranjo){
  int i;
  double resp = 0;
  for (i=0;i<4;i++) resp += arranjo[i];
  return resp/4;
}

int main() {
  double* precos = (double*) malloc(sizeof(double)*4);
  precos[0] = 1500;
  precos[1] = 1100;
  precos[2] = 750;
  precos[3] = 500;

  printf("%8.2f\n", media(precos));

  return 0;
}



/* SAIDA
  962.50
*/