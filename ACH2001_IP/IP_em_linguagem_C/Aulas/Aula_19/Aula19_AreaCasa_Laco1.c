/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
	Uso de diferentes materiais e áreas com o faço FOR.
*/
#include <stdio.h>
#include <math.h>
#define false 0
#define true 1

typedef int bool;

int valorM2 = 1500;

const int ALVENARIA = 0;
const int VINIL = 1;
const int FIBRA = 2;
const int PLASTICO = 3;

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
   double area;
   int tipo = ALVENARIA;
   printf("Área\tValor\n");
   for(area = 200; area >= 50; area = area-50) {
      printf("%6.1f\t%9.2f\n", area, valorPiscina(area,tipo));
   }
   return 0;
}

/* SAIDA
Área    Valor
 200.0  300000.00
 150.0  225000.00
 100.0  150000.00
  50.0   75000.00
*/