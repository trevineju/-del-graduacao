#include <stdio.h>

double valorM2 = 1500;

double valor(double area) {
    return(valorM2*area);
}

int main() {
    double preco;
    preco = valor(-20);
    printf("O valor da construção é %f\n", preco);
    return 0;
}


/* SAIDA
O valor da construção é -30000.000000
*/