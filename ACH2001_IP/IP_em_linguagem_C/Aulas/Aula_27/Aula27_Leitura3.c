#include <stdio.h>

int main(){
  float comprimento;
  float largura;
  float area;
  printf("Programa para o calculo da area do retangulo.\n");
  while (1==1){
    printf("Digite o comprimento ou 0 (zero) para sair: ");
    scanf("%f",&comprimento);
    if (comprimento==0) break;
    printf("Digite a largura ou 0 (zero) para sair: ");
    scanf("%f",&largura);
    if (largura==0) break;
    area = comprimento*largura;
    printf("Area: %.2f\n\n",area);
  }
  return 0;
}

/*SAIDA E INTERACAO
Programa para o calculo da area do retangulo.
Digite o comprimento ou 0 (zero) para sair: 12
Digite a largura ou 0 (zero) para sair: 7
Area: 84.00

Digite o comprimento ou 0 (zero) para sair: 3.5
Digite a largura ou 0 (zero) para sair: 4.5
Area: 15.75

Digite o comprimento ou 0 (zero) para sair: 0
*/
