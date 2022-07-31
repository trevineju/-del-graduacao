/* Programa que testa a modificação nos valores dos campos de uma
   estrutura. */

#include <stdio.h>

typedef struct auxCasa {
  float lateral;
  float cquarto;
} casa;

void ampliaCasa(casa ca) {
  ca.lateral++;
  ca.cquarto++;
  printf("Lateral na funcao: %.2f\n",ca.lateral);
}

void ampliaCasa2(casa* ca) {
  (*ca).lateral++;
  ca->cquarto++;
  printf("Lateral na funcao: %.2f\n",ca->lateral);
}

int main() {
  casa c1;
  c1.lateral = 11;
  c1.cquarto = 15;
  printf("Lateral inicial: %.2f\n",c1.lateral);
  ampliaCasa2(&c1);
  printf("Lateral final: %.2f\n",c1.lateral);
  return 0;
}


/* SAIDA
Lateral inicial: 11.00
Lateral na funcao: 12.00
Lateral final: 12.00
*/
