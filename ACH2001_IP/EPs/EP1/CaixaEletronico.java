/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   Manhã - Luciano                                 							**/
/**                                                                 **/
/**   Primeiro Exercício-Programa                                   **/
/**                                                                 **/
/**   Juliana B Trevine - 10819311          												**/
/**                                                                 **/
/**   13/04/2020                                                    **/
/*********************************************************************/

/*
	Caixa eletrônico das Ilhas Weblands, com estoque ilimitado de cédulas
	de B$50,00, B$10,00, B$5,00 e B$1,00.
*/
public class CaixaEletronico {
	// Número de cédulas de B$50,00
	static int n50;
	// Número de cédulas de B$10,00
	static int n10;
	// Número de cédulas de B$5,00
	static int n5;
	// Número de cédulas de B$1,00
	static int n1;


	/*
		Determina a quantidade de cada nota necessária para totalizar
		um determinado valor de retirada, de modo a minimizar a quantidade
		de cédulas entregues.

		Abastece as variáveis globais n50,n10, n5 e n1 com seu respectivo
		número de cédulas.

		Parâmetro:
			valor - O valor a ser retirado
	*/

	static void fazRetirada(int valor) {
		/* Metodo que calcula quantas notas sao necessarias para se sacar diferentes
		valores de dinheiro, tendo em vista que se tem apenas notas de 50, 10, 5 e 1

		O código faz seguidas conferencias quanto ao conteudo da variavel valor. Isto
		para evitar contas extras quando já gerou a combinação de notas adequada para
		sacar o dinheiro
		*/

		if (valor>=0){									//executa se for uma quantia $ coerente
				n50=0; n10=0; n5=0; n1=0;		//zera os contadores das notas
				if (valor!=0) {							//checa se ainda há valor (>0) a se sacar
						n50 = valor/50;					//calcula quantas notas de 50 são necessarias
						valor = valor%50;				//atualiza a variavel valor com o restante
						if (valor!=0){				//checa se ainda há valor (>0) a se sacar
							n10 = valor/10;			//calcula quantas notas de 10 são necessarias
							valor = valor%10;		//atualiza a variavel valor com o restante
							if (valor!=0){			//checa se ainda há valor (>0) a se sacar
								n5 = valor/5;			//calcula quantas notas de 5 são necessarias
								valor = valor%5;	//atualiza a variavel valor com o restante
								if (valor!=0){		//checa se ainda há valor (>0) a se sacar
									n1 = valor;			//todo restante é necessariamente em notas de 1
						}
					}
				}
			}
		}
		else {		//devolve valores considerados erro
				n50=-1; n10=-1; n5=-1; n1=-1;
		}
	}


	/*
		Apenas para seus testes. ISSO SERÁ IGNORADO NA CORREÇÃO
	*/
public static void main(String[] args) {
		// escreva seu código (para testes) aqui

		// Exemplo de teste:
		fazRetirada(0);
		System.out.println("0");
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);

		fazRetirada(50);
		System.out.println("50");
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);

		fazRetirada(25);
		System.out.println("25");
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);

		fazRetirada(10);
		System.out.println("10");
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);

		fazRetirada(15);
		System.out.println("15");
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);

		fazRetirada(5);
		System.out.println("5");
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);

		fazRetirada(1);
		System.out.println("1");
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);

		fazRetirada(-25);
		System.out.println("-25");
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);

		fazRetirada(-220);
		System.out.println("-220");
		System.out.println("Notas de 50: "+n50);
		System.out.println("Notas de 10: "+n10);
		System.out.println("Notas de 5:  "+n5);
		System.out.println("Notas de 1:  "+n1);
	}
}
