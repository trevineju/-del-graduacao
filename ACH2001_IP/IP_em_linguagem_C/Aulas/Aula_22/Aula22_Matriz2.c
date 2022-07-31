/*
	Programa que gerencia os nomes dos materiais em uma matriz e em 
	um arranjo de arranjos.
*/

#include <stdio.h>

char nomes[4][10];

int main() {

  nomes[0][0] = 'A';
  nomes[0][1] = 'l';
  nomes[0][2] = 'v';
  nomes[0][3] = 'e';
  nomes[0][4] = 'n';
  nomes[0][5] = 'a';
  nomes[0][6] = 'r';
  nomes[0][7] = 'i';
  nomes[0][8] = 'a';
  nomes[0][9] = '\0';
  nomes[1][0] = 'V';
  nomes[1][1] = 'i';
  nomes[1][2] = 'n';
  nomes[1][3] = 'i';
  nomes[1][4] = 'l';
  nomes[1][5] = '\0';
  nomes[2][0] = 'F';
  nomes[2][1] = 'i';
  nomes[2][2] = 'b';
  nomes[2][3] = 'r';
  nomes[2][4] = 'a';
  nomes[2][5] = '\0';
  nomes[3][0] = 'P';
  nomes[3][1] = 'l';
  nomes[3][2] = 'a';
  nomes[3][3] = 's';
  nomes[3][4] = 't';
  nomes[3][5] = 'i';
  nomes[3][6] = 'c';
  nomes[3][7] = 'o';
  nomes[3][8] = '\0';

  printf("%s\n",nomes[1]);
  printf("%c\n",nomes[1][2]);
  
  return 0;
}



/* SAIDA
Vinil
n
*/
