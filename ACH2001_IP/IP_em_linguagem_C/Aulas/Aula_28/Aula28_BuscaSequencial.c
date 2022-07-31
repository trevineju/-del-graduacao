/*	Programa que executa uma busca sequencial em um arranjo
	de números inteiros.                                      */

#include <stdio.h>

int buscaSeq(int arr[], int tam, int el) {
  int i;
  for (i=0; i<tam; i++)
    if (arr[i] == el) return i;
  return -1;
}

int main() {
  int v[] = {9, 8, 4, 6, 3, 4};
  printf("%i\n", buscaSeq(v, 6, 4));
  printf("%i\n", buscaSeq(v, 6, 12));
  return 0;
}



/* SAIDA
2
-1
*/