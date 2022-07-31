/*
Trunca um valor na 2a casa
*/

#include <stdio.h>

double trunca(double valor) {
  int novoValor = (int)(valor*100);
  return((double)novoValor/100);
}

int main() {
  printf("%f\n", trunca(12.566370614359172));
  return 0;
}

/*SAIDA:
12.560000
*/
