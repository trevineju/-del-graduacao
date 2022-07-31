/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
*/
#include <stdio.h>
#include <math.h>

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
    return M_PI * pow(raio,2);
}

double valor(double area) {
	if (area >= 0) return(valorM2*area);
	return(-1);
}

int main() {
    double areap;
    areaCasa(11,7);

    areap = areaPiscina(2);
    printf("A área da piscina é: %f\n", areap);

	return 0;
}

/* SAIDA
Programa para cálculo da área da casa
A área da sala é 121.000000
A área do quarto é 38.500000
A área do banheiro é 38.500000
A área total é 198.000000
A área da piscina é: 12.566371
*/