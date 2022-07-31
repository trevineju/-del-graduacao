#include <stdio.h>
#include <math.h>
int main() {
    // raio da piscina
    double raio = 2;
    // área da piscina
    double areap;
    areap = M_PI * raio * raio;
    printf("Área: %f\n", areap);
    return 0;
}

/* SAIDA:
Área: 12.566371
*/