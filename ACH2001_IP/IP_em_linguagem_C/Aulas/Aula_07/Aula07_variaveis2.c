#include <stdio.h>
int main() {
    int lateral = 10; // comprimento da lateral da cabana
    int cquarto = 7; // comprimento da lateral maior do quarto
    int areaq; // área do quarto
    int areas; // área da sala
    int areat; // área total

    printf("Programa para cálculo da área da casa\n");
    areas = lateral*lateral;
    printf("A área da sala é %i\n", areas);
    areaq = cquarto*(lateral/2);
    printf("A área do quarto é %i\n", areaq);
    printf("A área do banheiro é %i\n", areaq);
    areat = areas + 2*areaq;
    printf("A área total é %i\n", areat);
    return 0;
}


/* SAIDA:
Programa para cálculo da área da casa
A área da sala é 100
A área do quarto é 35
A área do banheiro é 35
A área total é 170
*/