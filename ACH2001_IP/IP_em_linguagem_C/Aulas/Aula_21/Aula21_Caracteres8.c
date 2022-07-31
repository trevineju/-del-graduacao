/*
	Programa para armazenar uma string como um conjunto de caracteres
	alocados dinamicamente.
	Um caractere é modificado antes da impressão.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  char* nVinil = (char*) malloc(sizeof(char)*6);	
  nVinil[0] = 'V';
  nVinil[1] = 'i';
  nVinil[2] = 'n';
  nVinil[3] = 'i';
  nVinil[4] = 'l';
  nVinil[5] = '\0';
  printf("Material: %s\n",nVinil);
  return 0;
}



/* SAIDA
Material: Vinil
*/
