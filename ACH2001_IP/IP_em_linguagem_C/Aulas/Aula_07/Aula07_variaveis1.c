#include <stdio.h>

int main() {
    int areaq; // area do quarto
    int areas; // area da sala
    int areat; // area total
    printf("Programa para calculo da area da casa\n");
    areas = 10*10;
    printf("A area da sala e %i\n", areas);
    areaq = 7*5;
    printf("A area do quarto e %i\n", areaq);
    printf("A area do banheiro e %i\n", areaq);
    areat = areas + 2*areaq;
    printf("A area total e %i\n", areat);
    return 0;
}

/* SAIDA:
Programa para calculo da area da casa
A area da sala e 100
A area do quarto e 35
A area do banheiro e 35
A area total e 170
*/