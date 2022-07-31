/*
	Programa para armazenar e imprimir os nomes dos materiais das
	nossas piscinas.
	Um caractere é modificado antes da impressão.
*/

#include <stdio.h>

/* nomes dos materiais */
char nAlvenaria[] = {'A','l','v','e','n','a','r','i','a','\0'};
char nVinil[] = {'V','i','n','i','l','\0'};
char nFibra[] = {'F','i','b','r','a','\0'};
char nPlastico[] = {'P','l','a','s','t','i','c','o','\0'};

int main() {
  printf("Caractere: %c\n",nVinil[1]);
  nVinil[1] = 'c';
  printf("Material: %s\n",nVinil);
  return 0;
}



/* SAIDA
Caractere: i
Material: Vcnil
*/
