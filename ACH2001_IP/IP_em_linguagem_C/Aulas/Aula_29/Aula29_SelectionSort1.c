/*	Programa que ordena um arranjo de números inteiros
	utilizando o algoritmo de ordenação bolha (Bubble Sort) */

#include <stdio.h>

void imprimir(int arr[], int tam) {
  int i;
  for (i=0; i<tam; i++) printf("%i ",arr[i]);
  printf("\n");
}


int posMenorEl(int v[], int tam, int inicio) {
  int i, posMenor;
  posMenor = -1;
  if ((inicio>=0) && (inicio < tam)) {
    posMenor = inicio;
    for (i=inicio+1; i<tam; i++)
      if (v[i] < v[posMenor]) posMenor = i;
  }
  return posMenor;
}

void selecao(int v[], int tam) {
  int i, posMenor, aux;
  for (i=0; i<tam-1; i++) {
    posMenor = posMenorEl(v,tam,i);
    aux = v[i];
    v[i] = v[posMenor];
    v[posMenor] = aux;
  }
}

int main() {
  int v[] = {200,-4,125,52,32,0,55,69,63,-78};
  imprimir(v,10);
  selecao(v,10);
  imprimir(v,10);
  return 0;
}

/* SAIDA
200 -4 125 52 32 0 55 69 63 -78 
-78 -4 0 32 52 55 63 69 125 200 
*/