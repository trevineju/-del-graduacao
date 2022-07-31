/* Programa que cria e utiliza uma estrutura com uma auto referência. */

#include <stdlib.h>

typedef struct auxP {
  int cpf;
  struct auxP* conjuge;
} Pessoa;


int main() {
  Pessoa p1;
  p1.cpf = 12345;

  Pessoa* p2 = (Pessoa*) malloc(sizeof(Pessoa));
  p2->cpf = 56789;
  
  Pessoa p3;
  p3.cpf = 44444;

  p1.conjuge = p2;
  p2->conjuge = &p1;
  
  p3.conjuge = NULL;
  
  return 0;
}
