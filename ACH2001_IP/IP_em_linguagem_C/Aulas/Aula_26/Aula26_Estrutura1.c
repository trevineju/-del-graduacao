#include <stdio.h>

typedef struct auxCasa {
  float lateral;
  float cquarto;
} casa;

casa inicializaCasa(float lateral, float cquarto){
  casa resp;
  resp.lateral = lateral;
  resp.cquarto = cquarto;
  return resp;
}

void areaCasa(casa pCasa){
   float areaq;
   float areas;
   float areat;
   if (!(pCasa.lateral>=0 && pCasa.cquarto>=0))
      printf("Erro: parametro < 0\n");
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

int main() {
  casa c1 = inicializaCasa(11,15);
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