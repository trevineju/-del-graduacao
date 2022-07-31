/*********************************************************************/
/**   ACH2001 - Introdução à Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2020                          **/
/**   Matutino - Luciano D                                          **/
/**                                                                 **/
/**   Segundo Exercício-Programa                                    **/
/**                                                                 **/
/**   Juliana Bastos Trevine              10819311                  **/
/**                                                                 **/
/**   21/04/2020                                                    **/
/*********************************************************************/

/*
	Cálculo para raiz quadrada utilizando o Método de Newton
*/
public class Raiz {
	/*
		Calcula a raiz quadrada de um valor, com uma determinada
		precisão. Retorna esse valor, ou -1 quando:
		* a <= 0
		* epsilon <= 0
		* epsilon >= 1


		Parâmetro:
			a - valor cuja raiz quadrada será calculada
			epsilon - precisão do cálculo
	*/
	static boolean checaPrecisao(double valor_anterior, double valor_atual, double epsilon){
		/*
		Este metodo calcula se a precisao desejada foi alcancada.
		Ela retorna True caso não foi (para indicar que é preciso seguir operando um laço)
		e False para caso sim
		*/
		double aproximacao = valor_atual - valor_anterior;
		if (aproximacao < 0) aproximacao*=-1; //modulo de número negativo, caso necessario

		//descomente o código abaixo para gerar a tabela de exemplo presente no enunciado do EP2
		//System.out.println(valor_anterior + " | " + valor_atual + " | " + aproximacao);

		if (aproximacao >= epsilon) return true;
		return false;
	}

static double raizQuadrada(double a, double epsilon) {
		/*
		Este método calcula a raiz quadrada de um número com determinada precisao pelo método de Newton

		Parametros:
		a - valor cuja raiz quer ser descoberta
		epsilon - precisão
		*/

		double v_anterior = a/2;
		double v_atual = (v_anterior + (a/v_anterior))/2;  //garante funcionamento para o caso do 4, onde a raiz == metade

		if(a<0 || epsilon<=0 || epsilon>=1) return -1;  //retorna valor de erro
		if (a==0) return 0;
		while (checaPrecisao(v_anterior, v_atual, epsilon)){
			v_anterior = v_atual; //atualiza a variavel anterior antes de proceder com a atulizacao da atual
			v_atual = (v_anterior + (a/v_anterior))/2; //atualiza variavel de acordo com a formula do método de Newton pro novo teste
		}
		return v_atual;
	}

	/*
		Apenas para seus testes. ISSO SERÁ IGNORADO NA CORREÇÃO
	*/
	public static void main(String[] args) {
		//testes
		System.out.println("TESTES DE ERROS: retorno esperado -1.0");
		System.out.println(raizQuadrada(-3, 0.0001));
		System.out.println(raizQuadrada(0, 0.0001));
		System.out.println(raizQuadrada(32, -4));
		System.out.println(raizQuadrada(32, 0));
		System.out.println(raizQuadrada(32, 1));
		System.out.println(raizQuadrada(32, 5));

		System.out.println("TESTES DIVERSOS:");
		double precisao = 0.001;
		double testes[] = {3,4,6,9,12,15,20,25,28,32,36,40,63,70,132,1537,1379,15268,19703,153688};

		for (double valor : testes){
				System.out.println("Raiz de " + valor + " =\n" + raizQuadrada(valor,precisao) + "\n" + Math.sqrt(valor));
		}
	}
}
