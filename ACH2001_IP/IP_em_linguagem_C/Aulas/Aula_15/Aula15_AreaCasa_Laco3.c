/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
	Uso de diferentes materiais e áreas.
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
   double area = 50;
   int tipo;

   printf("Área\tTipo\tValor\n");
   do {
      tipo = ALVENARIA;
      do {
         printf("%6.1f\t%4i\t%9.2f\n", area, tipo, valorPiscina(area,tipo));
         tipo = tipo+1;
      } while (tipo <= PLASTICO);
      area = area+50;
   } while (area <= 200);
   return 0;
}


/* SAIDA
Área    Tipo    Valor
  50.0     0     75000.00
  50.0     1     55000.00
  50.0     2     37500.00
  50.0     3     25000.00
 100.0     0    150000.00
 100.0     1    110000.00
 100.0     2     75000.00
 100.0     3     50000.00
 150.0     0    225000.00
 150.0     1    165000.00
 150.0     2    112500.00
 150.0     3     75000.00
 200.0     0    300000.00
 200.0     1    220000.00
 200.0     2    150000.00
 200.0     3    100000.00
*/