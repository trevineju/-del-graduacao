/* Programa que cria e utiliza três estruturas de dados. */

#include <stdio.h>

typedef struct auxPisc {
  float raio;
} piscina;

typedef struct auxCasa {
  float lateral;
  float cquarto;
} casa;

typedef struct auxCaba {
  casa cas;
  piscina pis;
} cabana;

int main() {
  casa c1;
  c1.lateral = 11;
  c1.cquarto = 15;

  piscina p1;
  p1.raio = 3.5;
  
  cabana cab1;
  cab1.cas = c1;
  cab1.pis = p1;
  cab1.cas.lateral = 12;

  printf("A lateral da casa da cabana1 vale: %.2f\n", cab1.cas.lateral);  
  printf("O raio da piscina da cabana1 vale: %.2f\n", cab1.pis.raio);  
  return 0;
}


/* SAIDA
A lateral da casa da cabana1 vale: 12.00
O raio da piscina da cabana1 vale: 3.50
*/