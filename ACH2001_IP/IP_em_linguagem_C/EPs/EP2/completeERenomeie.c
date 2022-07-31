/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   <turma> - <nome do professor>                                 **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   <nome do(a) aluno(a)>                   <numero USP>          **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

typedef struct{
	char* nome;
	int nusp;
} PESSOA;


typedef struct{
	PESSOA pessoa;
	int nota;
	int frequencia;
	char status;
} ALUNOMATRICULADO;


typedef struct{
	PESSOA pessoa;
	ALUNOMATRICULADO* alunos[20];
	int numAlunos;
} MINISTRANTE;


typedef struct{
	MINISTRANTE* ministrantes[10];
	int numMinistrantes;
} CURSO;


/********************** FUNCOES PARA CRIAR ALUNOMATRICULADOS, MINISTRANTES OU CURSOS ******/


/* Funcao para a criacao de um novo ALUNOMATRICULADO.
   A funcao preenche todos os valores de seus campos e retorna esse novo ALUNOMATRICULADO.
*/
ALUNOMATRICULADO novoAluno(char* nome, int nusp){
	ALUNOMATRICULADO novo;
	novo.pessoa.nome = nome;
	novo.pessoa.nusp = nusp;
	novo.nota = 0;
	novo.frequencia = 0;
	novo.status = 'M';
	return novo;
}


/* Funcao para a criacao de um novo ministrante.
   A funcao preenche os valores de seus campos e retorna esse novo ministrante.
*/
MINISTRANTE novoMinistrante(char* nome, int nusp){
	MINISTRANTE novo;
	novo.pessoa.nome = nome;
	novo.pessoa.nusp = nusp;
	novo.numAlunos = 0;
	return novo;
}

/* Funcao para a criacao de um novo curso.
   A funcao preenche os valores de seus campos e retorna esse novo curso.
*/
CURSO novoCurso(){
	CURSO novo;
	novo.numMinistrantes = 0;
	return novo;
}





/********************** FUNCOES DOS alunos *********************************/


/* Funcao que retorna true caso nota seja maior ou igual que 30 e a frequencia
   seja maior ou igual a 70. Caso contrario devera retornar false.  */
bool preRequisitoFraco(ALUNOMATRICULADO* a1) {
	
	/* COMPLETE/IMPLEMENTE SEU CODIGO AQUI */
	
	return false;
}

/* Funcao para o ALUNOMATRICULADO atual (referenciado por a1) obter ponto(s) extra(s) de acordo com o valor passado por parametro
 *   Caso o valor do parametro seja menor ou igual a zero, a funcao deve retornar false
 *   Caso contrario ha duas situacoes:
 *     1a) se o valor do parametro mais o valor da nota for maior do que 100,
 *         a nota deve ser atualizada para 100 e a funcao deve retornar true
 *     2a) caso contrario, a nota devera ser atualizada para o valor atual da
 *         nota mais o valor passado como parametro e a funcao deve retornar true
 */
bool ganharPontoExtra(ALUNOMATRICULADO* a1, int valor) {

	/* COMPLETE/IMPLEMENTE SEU CODIGO AQUI */
	
	return false;
}



/* Funcao para o ALUNOMATRICULADO atual (referenciado por a1) ter sua nota e sua frequencia atualizadas.
   Caso o valor dos parametros nota ou freq sejam negativos ou maiores do que 100,
     a funcao deve retornar false
   Caso contrario, os campos nota e fequencia do aluno a1 devem ser atualizados
     de acordo com o valor dos parametros  e a funcao deve retornar true
 */
bool atualizarNotaEFrequencia(ALUNOMATRICULADO* a1, int nota, int freq) {

	/* COMPLETE/IMPLEMENTE SEU CODIGO AQUI */
	
	return false;
}



/* Funcao para atualizar o status do ALUNOMATRICULADO atual (referenciado por a1) de acordo com sua nota e frequencia.
   Ha cinco situacoes:
    1a) Caso a nota seja menor do que 50 e a frequencia seja menor do que 70
        o status deve ser atualizado para E (reprovado por nota E frequencia);
    2a) Caso a nota seja menor do que 30 e a frequencia maior ou igual do
        que 70, o status deve ser atualizado para N (reprovado por Nota);
    3a) Caso a nota seja maior ou igual a 50 e a frequencia menor do que 70,
        o status deve ser atualizado para F (reprovado por Faltas);
    4a) Caso a nota seja maior ou igual a 30 e menor do que 50 e a frequencia
        seja maior ou igual a 70, o status deve ser atualizado para R (aluno
        em Recuperacao);
    5a) Caso a nota seja maior ou igual a 50 e a frequencia seja maior ou igual
        a 70, o status deve ser atualizado para A (aluno Aprovado)
 */
void atualizarStatus(ALUNOMATRICULADO* a1) {

	/* COMPLETE/IMPLEMENTE SEU CODIGO AQUI */
	
}




/********************** FUNCOES DOS MINISTRANTES *********************************/


/* Funcao para adicionar um ALUNOMATRICULADO no arranjo de alunos do ministrante referenciado por min1.
 * Caso o numero de alunos seja igual a 20, nao deve adicionar e deve retornar false.
 * Caso contrario, ha duas situacoes: 
 *   1a: o ALUNOMATRICULADO ja consta no arranjo de alunos (verifique isso usando o valor do nusp),
 *       neste caso o ALUNOMATRICULADO nao deve ser reinserido e a funcao deve retornar false; 
 *   2a: o ALUNOMATRICULADO passado como parametro nao consta no arranjo de alunos: o ALUNOMATRICULADO 
 *       deve ser adicionado na posicao numAlunos, o campo numAlunos deve ser 
 *       incrementado em 1 e a funcao deve retornar true. 
 */
bool adicionarAluno(MINISTRANTE* min1, ALUNOMATRICULADO* aluno) {
	if (min1->numAlunos == 20) return false;
	int x;
	for (x=0;x<min1->numAlunos;x++){
		if (min1->alunos[x]->pessoa.nusp == aluno->pessoa.nusp) return false;
	}
	min1->alunos[min1->numAlunos] = aluno;
	min1->numAlunos++;
	return true;
}



/* Funcao para dar um ponto extra (10 pontos no esquema de notas adotado) para toda a turma,
   desde que o aluno nao esteja reprovado por faltas.
   Para cada um dos alunos presentes no arranjo alunos, esta funcao deve:
   - nao fazer nada para o ALUNOMATRICULADO, caso sua frequencia seja menor que 70
   - caso contrario, chamar a funcao ganharPontoExtra passando, como 
     parametros, o endereco do ALUNOMATRICULADO atual e o valor 10
 */
void darPontoParaATurma(MINISTRANTE min1) {
	ALUNOMATRICULADO* atual;
	int c;
	for (c=0; c < min1.numAlunos; c++){
		atual = min1.alunos[c];
		if (atual->frequencia >= 70) ganharPontoExtra(atual,10);
	}
}



/* Funcao para arredondar a nota de todos os alunos presentes no arranjo de alunos do ministrante, de acordo com a seguinte regra:
   - nao fazer nada para o ALUNOMATRICULADO, caso sua frequencia seja menor que 70
   - caso contrario, ha duas possibilidades:
     1a) se a nota do aluno atual for maior ou igual a 50 ou menor do que valor minimo, nao faca nada.
     2a) caso contrario, atualize a nota do aluno atual para 50
 */
void arredondarParaCinco(MINISTRANTE min1, int valorMinimo) {

	/* COMPLETE/IMPLEMENTE SEU CODIGO AQUI */
	
}



/* Funcao para imprimir informacoes sobre os alunos minenciados por min1 */
void imprimirAlunos(MINISTRANTE min1){
	ALUNOMATRICULADO* atual;
	int c;
	printf("\tNumero de alunos: %i\n", min1.numAlunos);
	for (int c=0; c < min1.numAlunos; c++){
		atual = min1.alunos[c];
		printf("%4i %s\t%11i %8i %8i %c\n", c+1, atual->pessoa.nome, atual->pessoa.nusp, atual->nota, atual->frequencia, atual->status);
	}
}




/********************** FUNCOES DOS CURSOS ***********************************/

/* Funcao para adicionar um ministrante no arranjo de ministrantes do curso referenciado por a1.
 * Caso o numero de ministrantes seja igual a 10, nao deve adicionar e deve retornar false.
 * Caso contrario, ha duas situacoes: 
 *   1a: o ministrante ja consta no arranjo de ministrantes (verifique isso usando o numero do nusp),
 *       neste caso o ministrante nao deve ser reinserido e a funcao deve retornar false; 
 *   2a: o ministrante passado como parametro nao consta no arranjo de ministrantes: o ministrante 
 *       deve ser adicionado na posicao numMinistrantes, o campo numMinistrantes deve ser 
 *       incrementado em 1 e a funcao deve retornar true. 
 */
bool adicionarMinistrante(CURSO* c1, MINISTRANTE* min1){

	/* COMPLETE/IMPLEMENTE SEU CODIGO AQUI */
	
	return false;

}

/* Funcao para atualizar o status de todos os alunos do curso.
   Para cada um dos alunos das turmas de cada ministrante, esta funcao deve invocar
   a funcao atualizarStatus, passando o endereco do aluno como parametro.
 */
void atualizarStatusDoCurso(CURSO c1) {
	int c;
	MINISTRANTE* min;
	ALUNOMATRICULADO* atual;
	for (int g=0; g < c1.numMinistrantes; g++){
		min = c1.ministrantes[g];
		for (c=0; c < min->numAlunos; c++){
			atual = min->alunos[c];
			atualizarStatus(atual);
		}
	}
}

/* Funcao para imprimir informacoes minais sobre o curso a1 (passado como parametro) */
void imprimirDadosCurso(CURSO c1){
	printf("#########################################################################\n");
	printf("Imprimindo informacoes do curso.\n");
	printf("Ha %i ministrante(s) neste curso.\n",c1.numMinistrantes);
	MINISTRANTE* min;
	for (int g=0; g < c1.numMinistrantes; g++){
		min = c1.ministrantes[g];
		printf("Ministrante: %s\tnusp: %i\n", min->pessoa.nome, min->pessoa.nusp);
		imprimirAlunos(*min);
	}
	printf("#########################################################################\n");
}



int main(){
	
	printf("ATENCAO: Nem todas as caracteristicas do enunciado sao testadas neste exemplo.\n");
	printf("         Cabe a cada aluno(a) testar cuidadosamente seu EP.\n\n");
	
	printf("*** Criando alunos **************************************\n");
	ALUNOMATRICULADO a1 = novoAluno("Aluno A\0", 22222);
	ALUNOMATRICULADO a2 = novoAluno("Aluno B\0", 33333);
	ALUNOMATRICULADO a3 = novoAluno("Aluno C\0", 44444);
	ALUNOMATRICULADO a4 = novoAluno("Aluno D\0", 55555);
	ALUNOMATRICULADO a5 = novoAluno("Aluno C\0", 44444);
	ALUNOMATRICULADO a6 = novoAluno("Aluno E\0", 66666);


	printf("*** Criando Ministrantes **************************************\n");
	MINISTRANTE min1 = novoMinistrante("Ministrante 1\0", 12345);
	MINISTRANTE min2 = novoMinistrante("Ministrante 2\0", 12121);



	printf("*** Criando um Curso **************************************\n");
	CURSO meuCurso = novoCurso();
	
	

	printf("*** Adicionando alunos ao Ministrante 1 **************************\n");
	
	if (adicionarAluno(&min1, &a1)) printf("Aluno '%s' adicionado corretamente.\n", a1.pessoa.nome);
	else printf("Aluno '%s' nao pode ser adicionado.\n", a1.pessoa.nome);
	
	if (adicionarAluno(&min1, &a2)) printf("Aluno '%s' adicionado corretamente.\n", a2.pessoa.nome);
	else printf("Aluno '%s' nao pode ser adicionado.\n", a2.pessoa.nome);
	
	if (adicionarAluno(&min1, &a2)) printf("Aluno '%s' adicionado corretamente.\n", a2.pessoa.nome);
	else printf("Aluno '%s' nao pode ser adicionado.\n", a2.pessoa.nome);
	
	if (adicionarAluno(&min1, &a3)) printf("Aluno '%s' adicionado corretamente.\n", a3.pessoa.nome);
	else printf("Aluno '%s' nao pode ser adicionado.\n", a3.pessoa.nome);
	
	if (adicionarAluno(&min1, &a6)) printf("Aluno '%s' adicionado corretamente.\n", a6.pessoa.nome);
	else printf("Aluno '%s' nao pode ser adicionado.\n", a6.pessoa.nome);

	printf("*** Adicionando alunos ao Ministrante 2 **************************\n");
	
	if (adicionarAluno(&min2, &a5)) printf("Aluno '%s' adicionado corretamente.\n", a5.pessoa.nome);
	else printf("Aluno '%s' nao pode ser adicionado.\n", a5.pessoa.nome);
	
	if (adicionarAluno(&min2, &a4)) printf("Aluno '%s' adicionado corretamente.\n", a4.pessoa.nome);
	else printf("Aluno '%s' nao pode ser adicionado.\n", a4.pessoa.nome);
	
	printf("*** Adicionando Ministrantes ao Curso ******************************\n");
	
	adicionarMinistrante(&meuCurso,&min1);
	adicionarMinistrante(&meuCurso,&min2);
	
	imprimirDadosCurso(meuCurso);


	printf("*** Testando a funcao atualizarNotaEFrequencia **************************\n");
	
	if (atualizarNotaEFrequencia(&a4, 50, 25))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a4.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a4.pessoa.nome);

	if (atualizarNotaEFrequencia(&a6, 20, 80))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a6.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a6.pessoa.nome);
	

	if (atualizarNotaEFrequencia(&a4, -1, -1))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a4.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a4.pessoa.nome);

	
	if (atualizarNotaEFrequencia(&a2, 50, 50))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);


	if (atualizarNotaEFrequencia(&a2, 45, 70))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);

	imprimirDadosCurso(meuCurso);

	printf("*** Testando a funcao atualizarNotaEFrequencia ****************************\n");
	
	if (atualizarNotaEFrequencia(&a2, 150, 90))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);

	if (atualizarNotaEFrequencia(&a2, 48, 75))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);

	if (atualizarNotaEFrequencia(&a1, 100, 95))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a1.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a1.pessoa.nome);


	if (atualizarNotaEFrequencia(&a1, 100, 101))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a1.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a1.pessoa.nome);

	
	imprimirDadosCurso(meuCurso);
	

	printf("*** Testando a funcao ganharPontoExtra **************************\n");
	if (ganharPontoExtra(&a1, 10))  printf("Aluno '%s' ganhou ponto extra.\n", a1.pessoa.nome);
	else  printf("Aluno '%s' nao ganhou ponto extra.\n", a1.pessoa.nome);

	if (ganharPontoExtra(&a2, -10))  printf("Aluno '%s' ganhou ponto extra.\n", a2.pessoa.nome);
	else  printf("Aluno '%s' nao ganhou ponto extra.\n", a2.pessoa.nome);
	
	if (ganharPontoExtra(&a3, 5))  printf("Aluno '%s' ganhou ponto extra.\n", a3.pessoa.nome);
	else  printf("Aluno '%s' nao ganhou ponto extra.\n", a3.pessoa.nome);

	if (ganharPontoExtra(&a4, 20))  printf("Aluno '%s' ganhou ponto extra.\n", a4.pessoa.nome);
	else  printf("Aluno '%s' nao ganhou ponto extra.\n", a4.pessoa.nome);

	
	imprimirDadosCurso(meuCurso);
	
	printf("*** Testando a funcao darPontoParaATurma *******************\n");

	if (atualizarNotaEFrequencia(&a2, 38, 75))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a2.pessoa.nome);
	
	darPontoParaATurma(min1);
	imprimirDadosCurso(meuCurso);

	arredondarParaCinco(min1, 47);
	imprimirDadosCurso(meuCurso);

	if (atualizarNotaEFrequencia(&a5, 38, 75))  printf("Aluno '%s' teve a nota e a frequencia atualizadas.\n", a5.pessoa.nome);
	else  printf("Aluno '%s' nao teve a nota e a frequencia atualizadas.\n", a5.pessoa.nome);
	
	darPontoParaATurma(min2);
	imprimirDadosCurso(meuCurso);
	atualizarStatusDoCurso(meuCurso);
	imprimirDadosCurso(meuCurso);
	
	printf("\nATENCAO: Nem todas as caracteristicas do enunciado sao testadas neste exemplo.\n");
	printf("         Cabe a cada aluno testar cuidadosamente seu EP.\n\n");

	return 0;	
}
