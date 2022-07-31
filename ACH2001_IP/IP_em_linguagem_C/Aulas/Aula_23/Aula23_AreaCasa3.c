/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
	Há um arranjo com o preço dos materiais, bem como uma matriz com os
	nomes dos materiais.
	Há também a criação de uma matriz de preços, criada usando alocação
	dinâmica de memória e cujos valores são preenchidos/carregados usando
	uma função auxiliar (que utiliza a função valorPiscina já implementada
	anteriormente).
*/
#include <stdio.h>
#include <stdlib.h>
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

void carregaVal(double** m){
  int i, j;
  for (i=0; i<4; i++) {
    for (j=50; j<=200; j+=50) {
      m[i][j / 50 - 1] = valorPiscina(j,i);
    }
  }
}

int main() {
  int i;
  double** valores = (double**) malloc(sizeof(double*)*4);
  for (i=0;i<4;i++) valores[i] = (double*) malloc(sizeof(double)*4);
  carregaVal(valores);
  
  printf("Piscina de plastico de 150m2: %.2f\n", valores[PLASTICO][2]);
  
  double media = 0;
  for (int i=0; i<4; i++) media += valores[PLASTICO][i];
  media /= 4;
  printf("Media: %.2f\n",media);
  
  return 0;
}


/* SAIDA
Piscina de plastico de 150m2: 75000.00
Media: 62500.00
*/