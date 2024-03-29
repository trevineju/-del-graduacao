/*
	Programa para calcular a área de uma casa com piscina, conforme
	projeto específico.
	No conteúdo da aula de hoje vários condicionais são adicionados ao código.
*/
#include <stdio.h>
#include <math.h>
#define false 0
#define true 1

typedef int bool;
int valorM2 = 1500;

void areaCasa(float lateral, float cquarto){
   float areaq;
   float areas;
   float areat;
   if (lateral<0) printf("Erro: lateral da sala < 0\n");
   else {
      if (cquarto<0) printf("Erro: lateral do quarto < 0\n");
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
}

double areaPiscina(double raio){
   if (raio >= 0) return M_PI * raio*raio;
   return -1;
}

double valor(double area) {
   if (area >= 0) {
      return(valorM2*area);
   }
   return(-1);
}

int main() {
   double preco;
   bool valorOK = false;

   preco = valor(-20);
   valorOK = preco >= 0;

   printf("O valor da construção ");
   if (valorOK) printf("é %f\n",preco);
   else printf("não foi obtido: área negativa\n");

   return 0;
}


/* SAIDA
O valor da construção não foi obtido: área negativa
*/