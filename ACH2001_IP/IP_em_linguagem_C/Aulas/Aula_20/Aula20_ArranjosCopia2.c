/*
	Primeira tentativa para copiar o conteúdo de um arranjo em outro.
	A tentativa não funciona, pois o que é copiada é a referência ao
	primeiro arranjo, conforme pode ser verificado com a mudança no valor
	de um dos elementos do arranjo.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
  int* a1 = (int*) malloc(sizeof(int)*4);
  int* a2 = (int*) malloc(sizeof(int)*4);
  int x;
  for (x=0;x<4;x++) a1[x] = x;
  
  a2 = a1;
  a1[3] = 9;
  for (x=0;x<4;x++) printf("%i, ", a1[x]);
  printf("\n");
  for (x=0;x<4;x++) printf("%i, ", a2[x]);
  printf("\n");

  return 0;
}

/* SAIDA
0, 1, 2, 9, 
0, 1, 2, 9, 
*/