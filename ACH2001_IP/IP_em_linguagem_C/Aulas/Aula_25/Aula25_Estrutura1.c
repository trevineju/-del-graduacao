/* Programa que cria e utiliza uma primeira estrutura de dados. */

#include <stdio.h>

/* Estrutura para agrupar as informações de uma casa */
struct casa {
  float lateral;  // lateral da casa
  float cquarto;  // comprimento do quarto
};

int main() {
  struct casa c1;
  c1.lateral = 11;
  c1.cquarto = 7;

  printf("A lateral da casa vale: %.2f\n", c1.lateral);  
  return 0;
}


/* SAIDA
A lateral da casa vale: 11.00
*/