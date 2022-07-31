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
      printf("Erro: parametro < 0\\n");
   else {
      printf("Programa para calculo da area da casa\n");
      areas = lateral*lateral;
      printf("A area da sala e %f\n", areas);
      areaq = cquarto*(lateral/2);
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
  int i, j;
  double** valores = (double**) malloc(sizeof(double*)*4);
  for (i=0;i<4;i++) valores[i] = (double*) malloc(sizeof(double)*4);
  
  double descontos[][4] = {{0,0,0.2,0.2},{0.05,0.05,0.1,0.15}, {0.02,0.04,0.08,0.16}, {0,0,0,0.05}};

  carregaVal(valores);
  
  double** pFinal = calculaFinal(valores, descontos);
 
  for (i=0;i<4;i++){
	  for (j=0;j<4;j++) printf("%10.2f\t",pFinal[i][j]);
	  printf("\n");
  }
  
  return 0;
}


/* SAIDA
  75000.00   150000.00   180000.00   240000.00
  52250.00   104500.00   148500.00   187000.00
  36750.00    72000.00   103500.00   126000.00
  25000.00    50000.00    75000.00    95000.00
*/