/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   Turma 94 - Prof. Luciano Digiampietri                         **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

/*
	Implementacao de diversas funcoes matematicas
*/

#include <stdio.h>

/* Variaveis globais utilizas pela funcao separaNumero */
int unidades;
int dezenas;
int centenas;
int milhares;
	
/*
	Separa o valor de entrada em unidades, dezenas, centenas e milhares.

	Se o numero passado como parametro for menor que zero ou maior que 9999,
	a funcao devera colocar o valor -1 nas quatro variaveis globais
	existentes no programa: unidades, dezenas, centenas e milhares.

	Caso contrario, a funcao devera separar o numero de acordo com suas
	unidades, dezenas, centenas e milhares e colocar esses valores nas
	respectivas variaveis globais.
	Isto e, para o numero 2345, deve atribuir o valor 2 na variavel
	milhares, o valor 3 na variavel centenas, o valor 4 na variavel dezenas
	e o valor 5 na variavel unidades.
	
	Parametro:
		valor - Valor a ter seus digitos separados
*/
void separaNumero(int valor){

	/* IMPLEMENTE SEU CODIGO AQUI */

}


/*
	Realiza a operacao de potenciacao por meio de sucessivas multiplicacoes.

	Esta funcao recebe um numero real (valor) e um numero inteiro (expoente).
	Se os dois parâmetros valerem zero, a funcao devera retornar 0 (apenas 
	como uma excecao e nao para representar o resultado da operacao);
	se o valor de expoente for negativo, a funcao tambem devera retornar 0;
	se o valor de expoente for igual a zero e o valor de base for diferente
	de zero, devera retornar 1 (um).
	
	Caso contrario, a funcao devera retornar o resultado de:
                      base elevada a expoente
	Este resultado devera ser obtido a partir de sucessivas multiplicacoes.
	Por exemplo, para base=3 e expoente=4, a funcao devera retornar 81,
	valor obtido pela seguinte conta: 3*3*3*3.

	Parametros:
		base - Base da potenciacao (numero que sera elevado ao expoente)
		expoente - Expoente da potenciacao (numero de vezes que a base
			   sera multiplicada por ela mesma.
*/
double potenciacao(double base, int expoente){

	/* IMPLEMENTE SEU CODIGO AQUI */

}


/*
	Realiza a soma de valores a partir de inicio, enquanto menores do que
	fim e variando de acordo com o passo.
	Esta funcao recebe tres numeros reais (inicio, fim e passo).
	Se qualquer desses numeros for negativo ou nulo a funcao devera
	retornar 0 (apenas como uma excecao e nao para representar o resultado
	da operacao);
	Se o valor de fim for menor do que o valor de inicio, a funcao tambem
	devera retornar 0 (zero).
	
	Caso contrario, a funcao devera retornar a soma de todos os valores
	comecando por inicio, variando de acordo com o passo e enquanto forem
	menores do que fim.

	Por exemplo [valores decimais indicados com . (ponto) ao inves de , (virgula)],
	para inicio=3.2 e fim=4 e passo=0.2, a funcao devera retornar 14,
	valor obtido pela soma dos seguintes valores: 3.2 + 3.4 + 3.6 + 3.8.
	Ja para inicio=3.2, fim=4, passo=0.3, a funcao devera retornar 10.5,
	valor obtido pela soma dos seguintes valores: 3.2 + 3.5 + 3.8.

	Parametros:
		inicio - Primeiro valor a participar da soma
		fim - Os valores utilizados na soma devem ser menores do que fim
		passo - Variacao aplicada a cada valor a partir do valor de inicio
*/
double somaIntervalo(double inicio, double fim, double passo){

	/* IMPLEMENTE SEU CODIGO AQUI */

}


/*
	Esta funcao calcula o numero de passos de uma dada divisao, seguindo
	as regras detalhadas a seguir.
	
	Esta funcao recebe tres numeros reais (dividendo, divisor e limiar).
	Se qualquer desses numeros for negativo ou nulo a funcao devera
	retornar -1 (apenas como uma excecao e nao para representar o resultado
	da operacao);
	Se o valor de divisor for menor ou igual a 1, a funcao devera retornar -1;
	Se o valor de limiar for maior do que o valor de dividendo, a funcao
	devera retornar 0 (zero).

	Caso contrario, a funcao devera retornar o numero de vezes que e 
	possivel dividir o dividendo pelo divisor enquanto o resultado da
	operacao for maior ou igual ao valor de limiar, dada a regra a seguir.
	A cada divisao, o valor do dividendo deve ser atualizado com o 
	resultado da divisao realizada.

	Por exemplo [valores decimais indicados com . (ponto) ao inves de , (virgula)],
	Para dividendo=3.2 e divisor=1.6 e limiar=1.1, a funcao devera
	retornar 3, pois havera tres passos ate que o resultado sucessivo da
	divisao seja menor do que o limiar: 3.2/1.6=2 [primeiro passo (note 
	que 2 e maior ou igual ao limiar)], 2/1.6=1.25 [segundo passo (note
	que 1.25 e maior ou igual ao limiar)], 1.25/1.6=0.78125 [terceiro passo
	(note que 0.78125 e menor do que o limiar)], assim, ocorreram tres
	passos e a funcao devera retornar 3.
	Ja para dividendo=5 e divisor=8 e limiar=1.0, a funcao devera
	retornar 1, pois 5/8=0.625 [primeiro passo (note que 0.625 e menor do
	que o limiar)], assim, ocorreu apenas um passo e a funcao devera
	retornar 1.

	Parametros:
		dividendo - Dividendo inicial da divisao
		divisor - Divisor da divisao
		limiar - Limiar para o encerramento das divisoes: quando o 
			 resultado da divisao for menor do que o valor de
			 limiar, a sequencia de divisoes devera parar.

*/
int passosDaDivisao(double dividendo, double divisor, double limiar){

	/* IMPLEMENTE SEU CODIGO AQUI */

}


/*
	Funcao que retorna o n-esimo numero da serie (ou sequencia) de Fibonacci
	O calculo de n-esimo numero deve ocorrer de forma iterativa.

	Esta funcao recebe um numero inteiro como parâmetro (n).
	Se este numero for menor do que zero, a funcao devera retornar -1.
	
	Caso contrario, a funcao devera retornar o n-esimo numero da sequencia
	de Fibonacci, conforme descrito a seguir.
	O `zerezimo' numero de Fibonacci (isto e, para n=0) e igual a 0 (zero)
	[ou seja, fibonacci(0)=0];
	O numero seguinte de Fibonacci (isto e, para n=1) e igual a 1
	[ou seja, fibonacci(1)=1].
	Para os demais valores de n, temos:
		fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)

	Por exemplo fibonacci(2) = fibonacci(1) + fibonacci(0) = 1 + 0 = 1;
	Ja fibonacci(3) = fibonacci(2) + fibonacci(1) = 1 + 1 = 2;
	E fibonacci(4) = fibonacci(3) + fibonacci(2) = 2 + 1 = 3.

	Esta definicao da funcao da sequencia de Fibonacci (que usa a propria
	funcao para sua resolucao) e chamada de definicao recorrente e poderia
	ser resolvida por uma implementacao recursiva (mas este sera o assunto
	de outra aula!). O que se pede, neste EP, e que voce implemente a 
	funcao de forma iterativa. Isto e, para calcular o valor no `n-esimo'
	numero da sequencia de Fibonacci voce calculara o segundo, terceiro,
	quarto ... ate atingir o valor do n-esimo.

	Ja que cada numero da sequencia e calculado pela soma dos dois
	anteriores, voce pode ter duas variaveis auxiliares, por exemplo
	ultimo e penultimo e a cada iteracao o valor atual (por exemplo,
	guardado em uma terceira variavel chamada atual) sera igual a soma
	dessas duas variaveis e a variavel penultimo devera ser atualizada com
	o valor de ultimo e a variavel ultimo devera ser atualizada com o valor
	de atual.

	Por exemplo, para n=4 e sabendo que os primeiros numeros de Fibonacci
	sao 0 (zero) e 1, podemos ter tres variaveis do tipo long (penultimo,
	ultimo e atual) e sempre iniciarmos penultimo com o valor 0 (zero) e
	ultimo com o valor 1. Dentro de um laco que devera iterar,
	neste exemplo, tres vezes (correspondendo a n=2, n=3 e n=4) teremos,
	na primeira iteracao: atual = ultimo + penultimo (ou seja, 1 + 0 = 1);
	penultimo = ultimo (ou seja, 1); e ultimo = atual (ou seja, 1).
	Na segunda iteracao: atual = ultimo + penultimo (ou seja, 1 + 1 = 2);
	penultimo = ultimo (ou seja, 1); e ultimo = atual (ou seja, 2).
	Na terceira iteracao: atual = ultimo + penultimo (ou seja, 2 + 1 = 3);
	penultimo = ultimo (ou seja, 2); e ultimo = atual (ou seja, 3).
	Assim, para n=4 a funcao devera retornar 3 que e o valor da variavel
	atual (após tres iteracoes), conforme exemplificado.

	Parametro:
		n - indica o numero da sequencia que devera ser calculado
*/	

long fibonacci(int n){

	/* IMPLEMENTE SEU CODIGO AQUI */

}






/*
	Funcao main criada apenas para seus testes.
	Voce pode adicionar novos testes se quiser.
	ESTA FUNCAO SERA IGNORADA NA CORRECAO
*/
int main() {

	/* Exemplos de testes para a funcao separaNumero: */
	int valor;

	valor = 2345;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

	valor = 606;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");

	valor = -1;
	separaNumero(valor);
	printf("Valor: %i\n",valor);
	printf("Milhares: %i\n", milhares);
	printf("Centenas: %i\n", centenas);
	printf("Dezenas : %i\n", dezenas);
	printf("Unidades: %i\n", unidades);
	printf("\n");


	/* Exemplos de testes para a funcao potenciacao: */
	double base;
	int expoente;
	
	base = 0;
	expoente = 0;
	printf("Base: %f; Expoente: %i; Resultado: %f\n\n", base, expoente, potenciacao(base, expoente));
	
	base = 10;
	expoente = -2;
	printf("Base: %f; Expoente: %i; Resultado: %f\n\n", base, expoente, potenciacao(base, expoente));

	base = 10;
	expoente = 0;
	printf("Base: %f; Expoente: %i; Resultado: %f\n\n", base, expoente, potenciacao(base, expoente));

	base = 3;
	expoente = 4;
	printf("Base: %f; Expoente: %i; Resultado: %f\n\n", base, expoente, potenciacao(base, expoente));

	base = 3.141592;
	expoente = 2;
	printf("Base: %f; Expoente: %i; Resultado: %f\n\n", base, expoente, potenciacao(base, expoente));

	base = 2;
	expoente = 20;
	printf("Base: %f; Expoente: %i; Resultado: %f\n\n", base, expoente, potenciacao(base, expoente));


	/* Exemplos de testes para a funcao somaIntervalo: */
	double inicio;
	double fim;
	double passo;

	inicio = 0;
	fim = 10;
	passo = 2;
	printf("Inicio: %f; Fim: %f; Passo: %f; Resultado: %f\n\n", inicio, fim, passo, somaIntervalo(inicio, fim, passo));
	
	inicio = 3.2;
	fim = 4;
	passo = 0.2;
	printf("Inicio: %f; Fim: %f; Passo: %f; Resultado: %f\n\n", inicio, fim, passo, somaIntervalo(inicio, fim, passo));

	inicio = 3.2;
	fim = 4;
	passo = 0.3;
	printf("Inicio: %f; Fim: %f; Passo: %f; Resultado: %f\n\n", inicio, fim, passo, somaIntervalo(inicio, fim, passo));

	inicio = 1;
	fim = 2;
	passo = 0.25;
	printf("Inicio: %f; Fim: %f; Passo: %f; Resultado: %f\n\n", inicio, fim, passo, somaIntervalo(inicio, fim, passo));


	/* Exemplos de testes para a funcao passosDaDivisao: */
	double dividendo;
	double divisor;
	double limiar;

	dividendo = 0;
	divisor = 10;
	limiar = 2;
	printf("Dividendo: %f; Divisor: %f; Limiar: %f; Passos: %i\n\n", dividendo, divisor, limiar, passosDaDivisao(dividendo, divisor, limiar));

	dividendo = 10;
	divisor = 1;
	limiar = 2;
	printf("Dividendo: %f; Divisor: %f; Limiar: %f; Passos: %i\n\n", dividendo, divisor, limiar, passosDaDivisao(dividendo, divisor, limiar));

	dividendo = 3.2;
	divisor = 1.6;
	limiar = 1.1;
	printf("Dividendo: %f; Divisor: %f; Limiar: %f; Passos: %i\n\n", dividendo, divisor, limiar, passosDaDivisao(dividendo, divisor, limiar));

	dividendo = 5;
	divisor = 8;
	limiar = 1;
	printf("Dividendo: %f; Divisor: %f; Limiar: %f; Passos: %i\n\n", dividendo, divisor, limiar, passosDaDivisao(dividendo, divisor, limiar));


	/* Exemplos de testes para a funcao fibonacci: */
	int valorDeN;
	
	valorDeN = -1;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));
	
	valorDeN = 0;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));

	valorDeN = 1;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));

	valorDeN = 2;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));

	valorDeN = 3;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));

	valorDeN = 4;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));

	valorDeN = 5;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));

	valorDeN = 6;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));

	valorDeN = 7;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));

	valorDeN = 10;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));

	valorDeN = 50;
	printf("Valor de n: %i; Resultado: %li\n\n", valorDeN, fibonacci(valorDeN));



	/* se desejar, escreva seu codigo (para testes) aqui */


	return 0;
}

