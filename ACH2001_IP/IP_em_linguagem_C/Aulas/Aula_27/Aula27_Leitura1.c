/*	Programa que recebe os valores de peso e altura digitados
	pelo usuário e imprime seu índice de massa corporal.    */

#include <stdio.h>

int main(){
  float peso;
  int altura;
  float imc;
  printf("Programa para o calculo do IMC (indice de massa corporal).\n");
  printf("Digite seu peso em quilogramas: ");
  scanf("%f",&peso);
  printf("Digite sua altura em centimetros: ");
  scanf("%i",&altura);
  if (peso <= 0 || altura <= 0) {
    printf("Erro: valores incorretos de peso ou altura.\n");
  }else{
    imc = 10000*peso/altura/altura;
    printf("IMC: %.2f\n",imc);
  }
  return 0;
}

/*SAIDA E INTERACAO
Programa para o calculo do IMC (indice de massa corporal).
Digite seu peso em quilogramas: 70
Digite sua altura em centimetros: 185
IMC: 20.45
*/