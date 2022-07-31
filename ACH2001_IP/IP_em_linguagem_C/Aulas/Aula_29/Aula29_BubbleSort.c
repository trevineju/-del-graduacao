/*	Programa que ordena um arranjo de números inteiros
	utilizando o algoritmo de ordenação bolha (Bubble Sort) */

#include <stdio.h>

void imprimir(int arr[], int tam) {
  int i;
  for (i=0; i<tam; i++) printf("%i ",arr[i]);
  printf("\n");
}


void bolha(int v[], int tam) {
  int ult, i, aux;
  for (ult = tam-1; ult>0; ult--)
    for (i=0; i<ult; i++)
      if (v[i] > v[i+1]) {
        aux = v[i];
        v[i] = v[i+1];
        v[i+1] = aux;
      }
}


int main() {
  int v[] = {200,-4,125,52,32,0,55,69,63,-78};
  imprimir(v,10);
  bolha(v,10);
  imprimir(v,10);
  return 0;
}

/* SAIDA
200 -4 125 52 32 0 55 69 63 -78 
-78 -4 0 32 52 55 63 69 125 200 
*/