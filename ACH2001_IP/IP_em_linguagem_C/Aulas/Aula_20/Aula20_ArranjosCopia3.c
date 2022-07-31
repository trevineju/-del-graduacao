/*
	Programa que copia todos os elementos de um arranjo para outro.
	A cópia precisa ser feita elemento a elemento.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
  int* a1 = (int*) malloc(sizeof(int)*4);
  int* a2 = (int*) malloc(sizeof(int)*4);
  int x;
  for (x=0;x<4;x++) a1[x] = x;
  
  for (x=0;x<4;x++) a2[x] = a1[x];
  a1[3] = 9;
  for (x=0;x<4;x++) printf("%i, ", a1[x]);
  printf("\n");
  for (x=0;x<4;x++) printf("%i, ", a2[x]);
  printf("\n");

  return 0;
}

/* SAIDA
0, 1, 2, 9, 
0, 1, 2, 3, 
*/