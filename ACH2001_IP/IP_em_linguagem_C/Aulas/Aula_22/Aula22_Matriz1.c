/*
	Programa que gerencia os nomes dos materiais em uma matriz e em 
	um arranjo de arranjos.
*/

#include <stdio.h>

char nomes[4][10] = {{'A','l','v','e','n','a','r','i','a','\0'},{'V','i','n','i','l','\0'},
{'F','i','b','r','a','\0'},{'P','l','a','s','t','i','c','o','\0'}};

int main() {

  printf("%s\n",nomes[1]);
  printf("%c\n",nomes[1][2]);
  
  return 0;
}



/* SAIDA
Vinil
n
*/
