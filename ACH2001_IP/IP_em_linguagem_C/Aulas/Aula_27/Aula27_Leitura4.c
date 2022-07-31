#include <stdio.h>
#include <stdlib.h>


int contaCaracteres(char** palavras, int n){
  int total = 0;
  int i, j;
  for (i=0;i<n;i++) {
    j=0;
    while(palavras[i][j] != '\0'){
      total++;
      j++;
    }
  }
  return total;
}


int main(){
  int i, n;
  printf("Digite o numero de palavras: ");
  scanf("%i", &n);

  char** palavras = (char**) malloc(sizeof(char*)*n);

  printf("Digite as palavras: ");
  for (i=0;i<n;i++){
    palavras[i] = (char*) malloc(sizeof(char)*256);
    scanf("%s",palavras[i]);
    printf("Palavra %2i: %s\n", i, palavras[i]);
  }

  printf("Quantidade de caracteres: %i\n", contaCaracteres(palavras,n));

  return 0;
}
