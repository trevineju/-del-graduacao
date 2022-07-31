/*
	Programa que imprime os caracteres da tabela ASCII e
	verifica se correspondem a letras minúsculas.
*/
#include <stdio.h>

char paraMin(char c) {
  char aux;
  if (c >= 'A' && c <= 'Z') {
    aux = c - 'A' + 'a';
    return aux;
  }
  return(c);
}

int main(){ 
  char a = 'A';
  char b = 'X';
  printf("%c %c\n", a, paraMin(a));
  printf("%c %c\n", b, paraMin(b));
  return 0;
}

/* SAIDA
A a
X x
*/