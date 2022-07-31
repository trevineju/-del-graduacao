/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
	Uso de diferentes materiais e ifs aninhados.
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

int valorM2 = 1500;

double valorPiscina(double area, int material) {
  double valor;
  switch (material) {
    case ALVENARIA: valor = 1500;
                    break;
    case VINIL: valor = 1100;
                break;
    case FIBRA: valor = 750;
                break;
    case PLASTICO: valor = 500;
                   break;
    default: valor = -1;
  }
  return(area*valor);
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
	printf("%.2f\n", valorPiscina(100,ALVENARIA));
   return 0;
}


/* SAIDA
150000.00
*/