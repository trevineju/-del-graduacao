/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
	Há um arranjo com o preço dos materiais, bem como uma matriz com os
	nomes dos materiais.
*/
#include <stdio.h>
#include <math.h>
#define false 0
#define true 1

#define ALVENARIA 0
#define VINIL 1
#define FIBRA 2
#define PLASTICO 3

typedef int bool;

/* nomes dos materiais */
char nomes[4][10] = {{'A','l','v','e','n','a','r','i','a'},{'V','i','n','i','l'},
{'F','i','b','r','a'},{'P','l','a','s','t','i','c','o'}};

int valorM2 = 1500;

double precos[] = {1500, 1100, 750, 500};

double valorPiscina(double area, int material) {
  if (material<ALVENARIA || material>PLASTICO || area<0) return(-1);
  return(area*precos[material]);
}

void areaCasa(float lateral, float cquarto){
   float areaq;
   float areas;
   float areat;
   if (!(lateral>=0 && cquarto>=0))
      printf("Erro: parâmetro < 0\\n");
   else {
      printf("Programa para cálculo da área da casa\n");
      areas = lateral*lateral;
      printf("A área da sala é %f\n", areas);
      areaq = cquarto*(lateral/2);
      printf("A área do quarto é %f\n", areaq);
      printf("A área do banheiro é %f\n", areaq);
      areat = areas + 2*areaq;
      printf("A área total é %f\n", areat);
   }
}

double areaPiscina(double raio){
   return((raio >= 0) ? M_PI*raio*raio : -1);
}

double valor(double area) {
   if (area >= 0) {
      return valorM2*area;
   }
   return -1;
}

int main() {
  printf("Piscina de %s: %8.2f\n", nFibra,valorPiscina(100,FIBRA));
   return 0;
}

/* SAIDA
Piscina de Fibra: 75000.00
*/