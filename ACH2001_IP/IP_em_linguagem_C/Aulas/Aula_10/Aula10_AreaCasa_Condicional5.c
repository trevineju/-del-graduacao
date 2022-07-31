#include <stdio.h>

double valorM2 = 1500;

double valor(double area) {
    if (area >= 0) {
        return(valorM2*area);
    }
    return(-1);
}

int main() {
    double preco;
    int valorOK = 0;

    preco = valor(-20);
    if (preco >= 0) valorOK = 1;

    if (valorOK) printf("O valor da construção é %f\n", preco);
    else printf("Valor de área negativo\n");
    return 0;
}


/* SAIDA
Valor de área negativo
*/