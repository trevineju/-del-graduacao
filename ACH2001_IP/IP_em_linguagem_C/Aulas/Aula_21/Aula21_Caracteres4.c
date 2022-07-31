/*
	Programa que imprime os caracteres da tabela ASCII e
	verifica se correspondem a letras minúsculas.
*/
#include <stdio.h>

int minuscula(char c) {
  return(c >= 'a' && c <= 'z');
}

int main(){ 
  int i;
  for (i = 32; i <= 126; i++) {
    printf("%c %i\n", i, minuscula(i));
  }
  return 0;
}

/* SAIDA
  0
! 0
" 0
# 0
$ 0
% 0
& 0
' 0
( 0
) 0
* 0
+ 0
, 0
- 0
. 0
/ 0
0 0
1 0
2 0
3 0
4 0
5 0
6 0
7 0
8 0
9 0
: 0
; 0
< 0
= 0
> 0
? 0
@ 0
A 0
B 0
C 0
D 0
E 0
F 0
G 0
H 0
I 0
J 0
K 0
L 0
M 0
N 0
O 0
P 0
Q 0
R 0
S 0
T 0
U 0
V 0
W 0
X 0
Y 0
Z 0
[ 0
\ 0
] 0
^ 0
_ 0
` 0
a 1
b 1
c 1
d 1
e 1
f 1
g 1
h 1
i 1
j 1
k 1
l 1
m 1
n 1
o 1
p 1
q 1
r 1
s 1
t 1
u 1
v 1
w 1
x 1
y 1
z 1
{ 0
| 0
} 0
~ 0
*/