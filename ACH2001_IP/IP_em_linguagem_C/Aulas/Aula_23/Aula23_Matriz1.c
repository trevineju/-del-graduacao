/*
	Programa que cria uma matriz de double, preenche seus valores com uma
	função auxiliar e os imprime.
*/
#include <stdio.h>
#include <stdlib.h>

double precos[] = {1500, 1100, 750, 500};

void carregaVal(double** m){
  int i,j;
  for (i=0; i<4; i++) {
    for (j=50; j<=200; j+=50) {
      m[i][j / 50 - 1] = precos[i]*j;
    }
  }
}

int main() {
  int i,j;
  double** valores = (double**) malloc(sizeof(double*)*4);
  for (i=0;i<4;i++) valores[i] = (double*) malloc(sizeof(double)*4);
  carregaVal(valores);
  
  for (i=0; i<4; i++) {
    for (j=0; j<4; j++) {
      printf("%9.2f\t",valores[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}


/* SAIDA
 75000.00   150000.00   225000.00   300000.00
 55000.00   110000.00   165000.00   220000.00
 37500.00    75000.00   112500.00   150000.00
 25000.00    50000.00    75000.00   100000.00
*/