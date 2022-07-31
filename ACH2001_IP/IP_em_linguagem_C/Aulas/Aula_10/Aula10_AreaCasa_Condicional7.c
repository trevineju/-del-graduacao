#include <stdio.h>
#define false 0
#define true 1

typedef int bool;

double valorM2 = 1500;

double valor(double area) {
    if (area >= 0) {
        return(valorM2*area);
    }
    return(-1);
}

int main() {
    double preco;
    bool valorOK = false;

    preco = valor(-20);
    valorOK = preco >= 0;

    if (valorOK) printf("O valor da construção é %f\n", preco);
    else printf("Valor de área negativo\n");
    return 0;
}


/* SAIDA
Valor de área negativo
*/