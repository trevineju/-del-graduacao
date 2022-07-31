/*	Programa que executa uma busca sequencial em um arranjo
	de números inteiros ordenados de forma crescente.         */

#include <stdio.h>

int buscaSeq2(int arr[], int tam, int el) {
  int i;
  for (i=0; i<tam; i++) {
    if (arr[i] == el) return i;
    if (arr[i] > el) break;
  }
  return -1;
}


int buscaSeq3(int arr[], int tam, int el) {
  int i;
  for (i=0; i<tam; i++) {
    if (arr[i] >= el) {
      if (arr[i] == el) return i;
      else return -1;
    }
  }
  return -1;
}

int main() {
  int v[] = {-78,-4,0,32,52,55,63,69,125,200};
  printf("%i\n", buscaSeq2(v, 10, 23));
  printf("%i\n", buscaSeq2(v, 10, 8));
  printf("%i\n", buscaSeq2(v, 10, 32));
  printf("----------------------\n");
  printf("%i\n", buscaSeq3(v, 10, 23));
  printf("%i\n", buscaSeq3(v, 10, 8));
  printf("%i\n", buscaSeq3(v, 10, 32));
  return 0;
}

/* SAIDA
-1
-1
3
----------------------
-1
-1
3
*/