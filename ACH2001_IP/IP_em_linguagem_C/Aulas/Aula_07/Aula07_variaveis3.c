#include <stdio.h>

int main() {
    float lateral = 11; // comprimento da lateral da cabana
    float cquarto = 7; // comprimento da lateral maior do quarto
    float areaq; // área do quarto
    float areas; // área da sala
    float areat; // área total

    printf("Programa para cálculo da área da casa\n");
    areas = lateral*lateral;
    printf("A área da sala é %f\n", areas);
    areaq = cquarto*(lateral/2);
    printf("A área do quarto é %f\n", areaq);
    printf("A área do banheiro é %f\n", areaq);
    areat = areas + 2*areaq;
    printf("A área total é %f\n", areat);
    return 0;
}


/* SAIDA:
Programa para cálculo da área da casa
A área da sala é 121.000000
A área do quarto é 38.500000
A área do banheiro é 38.500000
A área total é 198.000000
*/