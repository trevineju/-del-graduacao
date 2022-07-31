#include <stdio.h>

int main() {
  // valor de pi
  const double PI = 3.14159;
  // raio da piscina
  double raio = 2;
  // área da piscina
  double areap;
  areap = PI * raio * raio;
  printf("Área: %f\n", areap);
  return 0;
}

/* SAIDA:
Área: 12.566360
*/