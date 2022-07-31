
public class ExecutaBanco {
	public static void main(String[] args){

		System.out.println("ATENCAO: Nem todas as caracteristicas do enunciado sao testadas neste exemplo.");
		System.out.println("         Cabe a cada aluno testar cuidadosamente seu EP.\n");

		System.out.println("*** Instanciando Clientes **************************************");
		Cliente c1 = new Cliente("Cliente A", 22222, 10000);
		Cliente c2 = new ClienteEspecial("Cliente B", 33333, 2000);
		Cliente c3 = new Cliente("Cliente C", 44444, 30000);
		Cliente c4 = new Cliente("Cliente D", 55555, 10);

		System.out.println("*** Instanciando Gerentes **************************************");
		Gerente ger1 = new Gerente("Gerente 1", 12345);
		Gerente ger2 = new Gerente("Gerente 2", 12121);

		System.out.println("*** Instanciando um Banco **************************************");
		Banco meuBanco = new Banco();



		System.out.println("*** Adicionando Clientes ao Gerente 1 **************************");

		if (ger1.adicionarCliente(c1)) System.out.println("Cliente '"  +c1.nome + "' adicionado corretamente.");
		else System.out.println("Cliente '"  + c1.nome + "' nao pode ser adicionado.");

		if (ger1.adicionarCliente(c2)) System.out.println("Cliente '"  +c2.nome + "' adicionado corretamente.");
		else System.out.println("Cliente '"  + c2.nome + "' nao pode ser adicionado.");

		if (ger1.adicionarCliente(c2)) System.out.println("Cliente '"  +c2.nome + "' adicionado corretamente.");
		else System.out.println("Cliente '"  + c2.nome + "' nao pode ser adicionado.");

		if (ger1.adicionarCliente(c3)) System.out.println("Cliente '"  + c3.nome + "' adicionado corretamente.");
		else System.out.println("Cliente '"  + c3.nome + "' nao pode ser adicionado.");

		System.out.println("*** Adicionando Clientes ao Gerente 2 **************************");

		if (ger2.adicionarCliente(c3)) System.out.println("Cliente '"  + c3.nome + "' adicionado corretamente.");
		else System.out.println("Cliente '"  + c3.nome + "' nao pode ser adicionado.");

		if (ger2.adicionarCliente(c4)) System.out.println("Cliente '"  + c4.nome + "' adicionado corretamente.");
		else System.out.println("Cliente '"  + c4.nome + "' nao pode ser adicionado.");

		System.out.println("*** Adicionando Gerentes ao Banco ******************************");

		meuBanco.adicionarGerente(ger1);
		meuBanco.adicionarGerente(ger2);

		meuBanco.imprimir();


		System.out.println("*** Testando o metodo obterEmprestimo **************************");

		if (c4.obterEmprestimo(20000))  System.out.println("Cliente '"  + c4.nome + "' obteve o emprestimo solicitado.");
		else  System.out.println("Cliente '"  + c4.nome + "' nao obteve o emprestimo solicitado.");


		if (c4.obterEmprestimo(20000))  System.out.println("Cliente '"  + c4.nome + "' obteve o emprestimo solicitado.");
		else  System.out.println("Cliente '"  + c4.nome + "' nao obteve o emprestimo solicitado.");


		if (c2.obterEmprestimo(20000))  System.out.println("Cliente '"  + c2.nome + "' obteve o emprestimo solicitado.");
		else  System.out.println("Cliente '"  + c2.nome + "' nao obteve o emprestimo solicitado.");


		if (c2.obterEmprestimo(20000))  System.out.println("Cliente '"  + c2.nome + "' obteve o emprestimo solicitado.");
		else  System.out.println("Cliente '"  + c2.nome + "' nao obteve o emprestimo solicitado.");


		meuBanco.imprimir();

		System.out.println("*** Testando o metodo realizarSaque ****************************");

		if (c2.realizarSaque(12345))  System.out.println("Cliente '"  + c2.nome + "' realizou saque solicitado.");
		else  System.out.println("Cliente '"  + c2.nome + "' nao pode realizar o saque solicitado.");

		if (c2.realizarSaque(12345))  System.out.println("Cliente '"  + c2.nome + "' realizou saque solicitado.");
		else  System.out.println("Cliente '"  + c2.nome + "' nao pode realizar o saque solicitado.");

		if (c1.realizarSaque(10000))  System.out.println("Cliente '"  + c1.nome + "' realizou saque solicitado.");
		else  System.out.println("Cliente '"  + c1.nome + "' nao pode realizar o saque solicitado.");


		if (c1.realizarSaque(1))  System.out.println("Cliente '"  + c1.nome + "' realizou saque solicitado.");
		else  System.out.println("Cliente '"  + c1.nome + "' nao pode realizar o saque solicitado.");


		meuBanco.imprimir();



		System.out.println("*** Testando o metodo pagarEmprestimo **************************");
		if (c1.pagarEmprestimo(100))  System.out.println("Cliente '"  + c1.nome + "' pagou (parte de) sua divida.");
		else  System.out.println("Cliente '"  + c1.nome + "' nao pode pagar (parte de) sua divida.");


		if (c2.pagarEmprestimo(100))  System.out.println("Cliente '"  + c2.nome + "' pagou (parte de) sua divida.");
		else  System.out.println("Cliente '"  + c2.nome + "' nao pode pagar (parte de) sua divida.");

		if (c3.pagarEmprestimo(100))  System.out.println("Cliente '"  + c3.nome + "' pagou (parte de) sua divida.");
		else  System.out.println("Cliente '"  + c3.nome + "' nao pode pagar (parte de) sua divida.");

		if (c4.pagarEmprestimo(100))  System.out.println("Cliente '"  + c4.nome + "' pagou (parte de) sua divida.");
		else  System.out.println("Cliente '"  + c4.nome + "' nao pode pagar (parte de) sua divida.");



		meuBanco.imprimir();

		System.out.println("*** Testando o metodo cobrarTodosEmprestimos *******************");

		ger1.cobrarTodosEmprestimos();
		meuBanco.imprimir();

		ger2.cobrarTodosEmprestimos();
		meuBanco.imprimir();


		System.out.println("\nATENCAO: Nem todas as caracteristicas do enunciado sao testadas neste exemplo.");
		System.out.println("         Cabe a cada aluno testar cuidadosamente seu EP.\n");


		System.out.println("TESTE O CLIENTE ESPECIAL");
		if (c2.obterEmprestimo(27310))  System.out.println("Cliente '"  + c2.nome + "' obteve o emprestimo solicitado.");
		else  System.out.println("Cliente '"  + c2.nome + "' nao obteve o emprestimo solicitado.");
		meuBanco.imprimir();

	}
}
