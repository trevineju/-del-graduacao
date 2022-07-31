/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
	Há um arranjo com o preço dos materiais, bem como uma matriz com os
	nomes dos materiais.
	Há também a criação de uma matriz de preços, criada usando alocação
	dinâmica de memória e cujos valores são preenchidos/carregados usando
	uma função auxiliar (que utiliza a função valorPiscina já implementada
	anteriormente).
	A média dos valores de um arranjo é calculada utilizando uma 
	função auxiliar.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

#define ALVENARIA 0
#define VINIL 1
#define FIBRA 2
#define PLASTICO 3

typedef int bool;

typedef struct auxPisc {
  float raio;
} piscina;

typedef struct auxCasa {
  float lateral;
  float cquarto;
} casa;

typedef struct auxCaba {
  casa cas;
  piscina pis;
} cabana;
/* nomes dos materiais */
char nomes[4][10] = {{'A','l','v','e','n','a','r','i','a'},{'V','i','n','i','l'},
{'F','i','b','r','a'},{'P','l','a','s','t','i','c','o'}};

int valorM2 = 1500;

double precos[] = {1500, 1100, 750, 500};

double valorPiscina(double area, int material) {
  if (material<ALVENARIA || material>PLASTICO || area<0) return(-1);
  return(area*precos[material]);
}

void areaCasa(casa pCasa){
   float areaq;
   float areas;
   float areat;
   if (!(pCasa.lateral>=0 && pCasa.cquarto>=0))
      printf("Erro: parametro < 0\\n");
   else {
      printf("Programa para calculo da area da casa\n");
      areas = pCasa.lateral*pCasa.lateral;
      printf("A area da sala e %f\n", areas);
      areaq = pCasa.cquarto*(pCasa.lateral/2);
      printf("A area do quarto e %f\n", areaq);
      printf("A area do banheiro e %f\n", areaq);
      areat = areas + 2*areaq;
      printf("A area total e %f\n", areat);
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

double calculaMedia(double* arranjo, int tam){
  int i;
  double resp = 0;
  for (i=0;i<tam;i++) resp += arranjo[i];
  return resp/tam;
}

double** calculaFinal(double** val, double desc[][4]) {
  int i, j; 
  double** saida = (double**) malloc(sizeof(double*)*4);
  for (i=0;i<4;i++) saida[i] = (double*) malloc(sizeof(double)*4);
  for (i=0;i<4;i++)
    for (j=0;j<4;j++)
      saida[i][j] = val[i][j]*(1-desc[i][j]);
  return saida;
}



int main() {
  casa c1;
  c1.lateral = 11;
  c1.cquarto = 15;
  areaCasa(c1);
  return 0;
}


/* SAIDA
Programa para calculo da area da casa
A area da sala e 121.000000
A area do quarto e 82.500000
A area do banheiro e 82.500000
A area total e 286.000000
*/