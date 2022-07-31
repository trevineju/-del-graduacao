/*
	Exemplo de laço for
*/
#include <stdio.h>

int main() {
   int a;
   int b;
   for(a=1, b=4; a<b; a++,b--) {
      printf("a=%i\n",a);
      printf("b=%i\n",b);
   }
   return 0;
}

/* SAIDA
a=1
b=4
a=2
b=3
*/