/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
	Uso de diferentes materiais em um laço.
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
  switch (material) {
    case ALVENARIA: return area*1500;
    case VINIL: return area*1100;
    case FIBRA: return area*750;
    case PLASTICO: return area*500;
    default: return -1;    
  }
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
   double area = 100;
   printf("Material\tValor\n");
   int tipo = 0;
   while (tipo <= 3) {
      printf("%8i\t%9.2f\n", tipo, valorPiscina(area,tipo));
      tipo = tipo+1;
   }
   return 0;
}


/* SAIDA
Material    Valor
       0    150000.00
       1    110000.00
       2     75000.00
       3     50000.00
*/