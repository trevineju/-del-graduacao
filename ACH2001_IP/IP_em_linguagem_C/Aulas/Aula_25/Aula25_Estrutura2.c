/* Uso de typedef em conjunto com a definição de uma estrutura */

#include <stdio.h>

typedef struct aux {
  float lateral;
  float cquarto;
} casa;

int main() {
  struct aux c1;
  casa c2;
  c1.lateral = 11;
  c2.lateral = 15;

  printf("A lateral da casa1 vale: %.2f\n", c1.lateral);  
  printf("A lateral da casa2 vale: %.2f\n", c2.lateral);  
  return 0;
}


/* SAIDA
A lateral da casa1 vale: 11.00
A lateral da casa2 vale: 15.00
*/