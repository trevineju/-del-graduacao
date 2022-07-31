/*
	Programa para calcular a área de uma piscina circular.
	Este programa utiliza a constante M_PI oriunda de math.h e
	também a função pow (potência).
*/
#include <stdio.h>
#include <math.h>
int main() {
     // raio da piscina
    double raio = 2;
    // área da piscina
    double areap;
    areap = M_PI * pow(raio, 2);
    printf("Área: %f\n", areap);

    return 0;
}


/* SAIDA
Área: 12.566371
*/