#include <stdio.h>

int is_prime(int n){
    int i;

    /*verifica se eh 1 ou 2*/
    if(n==1 || n==2) return 1;

    /*verifica se eh 0 ou divisivel por 2, unico primo par*/
    if (n==0 || n%2==0) return 0;

    /*checa de 2 em 2 se o numero eh divisivel, a partir do 3*/
    for(i = 3; i < n; i+=2)
      if(n % i == 0) return 0;

    return 1;
}

int char2int (char *array){
    int len;
    int number = 0;
    int m = 1;

    /*conta o tamanho do array*/
    for(len=0; array[len] != '\0'; ++len);

    /*converte para int*/
    while(len--){
      number += (array[len] - '0') * m;
      m *= 10;
    }
    return number;
}

int main(int argc, char *argv[]) {
  if(argc > 1){
    int num = char2int(argv[1]);
    int primo = is_prime(num);
    printf("%d\n", primo);
  }
  return 0;
}
