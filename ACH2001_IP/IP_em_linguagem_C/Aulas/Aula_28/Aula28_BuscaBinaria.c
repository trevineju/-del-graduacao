/*	Programa que executa uma busca binária em um arranjo
	de números inteiros ordenados de forma crescente.         */

#include <stdio.h>

int buscaBin(int arr[], int tam, int el){
  int fim = tam-1;
  int ini = 0;
  while (ini <= fim) {
    int meio = (fim + ini)/2;
    if (arr[meio] < el)
      ini = meio + 1;
    else {
      if (arr[meio] > el)
         fim = meio - 1;
      else return meio;
    }
  }
  return -1;
}
int main() {
  int v[] = {-78,-4,0,32,52,55,63,69,125,200};
  printf("%i\n", buscaBin(v, 10, 23));
  printf("%i\n", buscaBin(v, 10, 125));
  printf("%i\n", buscaBin(v, 10, 32));
  return 0;
}

/* SAIDA
-1
8
3
*/