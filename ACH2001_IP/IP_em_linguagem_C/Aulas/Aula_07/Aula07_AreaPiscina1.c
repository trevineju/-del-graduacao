#include <stdio.h>

int main() {
  // raio da piscina
  double raio = 2;
  // área da piscina
  double areap;
  // valor do pi
  double pi = 3.14159;
  areap = pi * raio * raio;
  printf("Área: %f\n", areap);
  return 0;
}

/* SAIDA:
Área: 12.566360
*/