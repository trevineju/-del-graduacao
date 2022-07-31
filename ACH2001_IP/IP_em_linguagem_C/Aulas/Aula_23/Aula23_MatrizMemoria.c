/*
	Programa exemplo que percorre uma matriz de 10000 x 10000 valores
	inteiros (cem milhões de valores).
	Se a ordem do percurso for invertida (linhas x colunas) o tempo
	execução mudará drasticamente.
*/
#include <stdlib.h>
#define ORDEM 10000

int main() {
  int i, j, w;
  
  double** matriz = (double**) malloc(sizeof(double*)*ORDEM);
  for (i=0;i<ORDEM;i++) matriz[i] = (double*) malloc(sizeof(double)*ORDEM);

  for (i=0;i<ORDEM;i++)
	  for (j=0;j<ORDEM;j++) w = matriz[i][j];
  
  return 0;
}
