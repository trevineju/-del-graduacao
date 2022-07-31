/*
	Programa para armazenar e imprimir os nomes dos materiais das
	nossas piscinas.
*/

#include <stdio.h>

/* nomes dos materiais */
char nAlvenaria[] = {'A','l','v','e','n','a','r','i','a','\0'};
char nVinil[] = {'V','i','n','i','l','\0'};
char nFibra[] = {'F','i','b','r','a','\0'};
char nPlastico[] = {'P','l','a','s','t','i','c','o','\0'};

int main() {
  printf("Piscina de %s\n",nAlvenaria);
  printf("Piscina de %s\n",nVinil);
  printf("Piscina de %s\n",nFibra);
  printf("Piscina de %s\n",nPlastico);
  return 0;
}



/* SAIDA
Piscina de Alvenaria
Piscina de Vinil
Piscina de Fibra
Piscina de Plastico
*/
