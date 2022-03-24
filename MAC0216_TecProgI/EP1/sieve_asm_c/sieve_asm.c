#include <stdio.h>

int is_prime(int n);

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
