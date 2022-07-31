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
    preco = valor(-20);
    printf("O valor da construção é %f\n", preco);
    return 0;
}


/* SAIDA
O valor da construção é -1.000000
*/