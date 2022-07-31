/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
*/
#include <stdio.h>
#include <math.h>
#define false 0
#define true 1

typedef int bool;
int valorM2 = 1500;

void areaCasa(float lateral, float cquarto){
    float areaq;
    float areas;
    float areat;
    printf("Programa para cálculo da área da casa\n");
    areas = lateral*lateral;
    printf("A área da sala é %f\n", areas);
    areaq = cquarto*(lateral/2);
    printf("A área do quarto é %f\n", areaq);
    printf("A área do banheiro é %f\n", areaq);
    areat = areas + 2*areaq;
    printf("A área total é %f\n", areat);
}

double areaPiscina(double raio){
    return M_PI * raio*raio;
}

double valor(double area) {
    if (area >= 0) {
        return(valorM2*area);
    }
    return(-1);
}

int main() {
    double preco;
    bool valorOK = false;

    preco = valor(-20);
    valorOK = preco >= 0;

    if (valorOK) printf("O valor da construção é %f\n", preco);
    else printf("Valor de área negativo\n");
    return 0;
}


/* SAIDA
Valor de área negativo
*/