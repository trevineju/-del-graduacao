/*	Programa que ordena um arranjo de números inteiros
	utilizando o algoritmo de ordenação bolha (Bubble Sort) */

#include <stdio.h>

void imprimir(int arr[], int tam) {
  int i;
  for (i=0; i<tam; i++) printf("%i ",arr[i]);
  printf("\n");
}


void selecao2(int v[], int tam) {
  int i, p, aux, posMenor;
  for (i=0; i<tam-1; i++) {
    posMenor = i;
    for (p=i+1; p<tam; p++)
      if (v[p] < v[posMenor])
        posMenor = p;
    aux = v[i];
    v[i] = v[posMenor];
    v[posMenor] = aux;
  }
}

int main() {
  int v[] = {200,-4,125,52,32,0,55,69,63,-78};
  imprimir(v,10);
  selecao2(v,10);
  imprimir(v,10);
  return 0;
}

/* SAIDA
200 -4 125 52 32 0 55 69 63 -78 
-78 -4 0 32 52 55 63 69 125 200 
*/