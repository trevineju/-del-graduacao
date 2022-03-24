.data #area para dados da memoria principal
	msg: 
		#Mensagem a ser exibida pelo usuario no inicio da aplicacao
		.asciiz "Escolha os elementos da matriz de ordem 3X3:"#mensagem a ser exibida para o usuario - printf("Escolha os elementos da matriz de ordem 3X3:");
	posicao: 
		#Mensagem que indicara a posicao a qual o elemento sera atribuido
		.asciiz "Posicao "
	matriz:	
		# float matriz[3][3]; 
		# Matriz inicial inserida pelo usuario
		 .float 00 00 00 
		 .float 00 00 00
		 .float 00 00 00
	matriz_a:
		# float matriz[3][3]; 
		# Matriz de adjacencia
		.float 00 00 00
		.float 00 00 00
		.float 00 00 00 
	matriz_inv:
		# float matriz[3][3]; 
		# Matriz transposta -> matriz inversa 
		.float 00 00 00 
		.float 00 00 00 
		.float 00 00 00
	f_det_pos: 
		#Parte positiva do calculo do determinante (parte da esquerda)
		.float 0.0
	f_det_neg:
	 	#Parte que sera subtraida do calculo do determinante (parte da direita), precedida por um sinal negativo
		.float 0.0	
	det:
		#Determinante
		.float 0.0
	tam_mat:
		#Ordem da matriz do tipo inteiro ou numero de linhas e colunas, como a uma matriz quadrada a quantidade eh a mesma
		.word 3
		
	.eqv TAMANHO_DADO 4 #Defino uma constante do tamanho do dado (int ou float), que no caso � 32 bits ou 4 bytes para c�lculo do endere�o dos elementos da matriz	
	zero:
		#Vari�vel constante com valor zero do tipo float (a que j� existe por padr�o no mips � do tipo inteiro)
		.float 0.0
	enter: 
		#Vari�vel a ser utilizada para quando precisar pular de linha
		.asciiz "\n"	
	espaco: 
		#Vari�vel a ser utilizada para quando precisar dar espa�o
		.asciiz " "	
	
.text #area para instru��es do programa
	main:	#fun��o main
		li $v0, 4 #instru��o para impress�o de string
		la $a0, msg #indica o endere�o da vari�vel a ser impressa, no caso msg
		syscall #"fa�a" imprime o que est� em $a0, nos pontos flutuantes � outro registrador ($f12)
		
		la $a2, matriz #endere�o da base da matriz est� no $a2
		lw $a1, tam_mat #coloca o valor que est� na vari�vel tam_mat (3) no registrador a1
		li $s0, 0 #coloca zero no registrador s0 - representa a linha ou o que seria i no C 
		
	whilei: #enquanto, aqui come�ar� o "for" que percorrer� as linhas da matriz, come�ando pela linha 0 
		li $s1, 0 #coloca zero no registrador t1 - representa a coluna ou o que seria j no C 
		whilej: #enquanto, aqui come�ar� o "for" que percorrer� as colunas da matriz, come�ando pela coluna 0  
			#endere�o = endere�o base + (linha * ordem + coluna) * tamanho_do_dado
			#esse endere�o foi calculado pensando em uma organiza��o sequencial da matriz
			#o endere�o base � o lugar onde a matriz come�a
			#linha*ordem dar� o in�cio da linha que procuramos
			#+coluna resultar� na coluna que se procura dentro de tal linha
			# tamanho do dado seria a multiplica��o do "sizeof()" no C, dando o tamanho daquilo que ser� lido ou escrito
			#seria parecido ao fseek(ARQUIVO* arq, sizeof(ELEMENTO)*i), SEEK_SET) em C usado para leituras de arquivos organizados sequencialmente 
			mul $s2, $s0, $a1 #indice da linha ($s0) * tamanho da coluna e da linha (*a1) = em qual linha estamos (*s2)
			add $s2, $s2, $s1 # s2 = s2*s1 = �ndice da linha (i) * ordem (k) + (�ndice da coluna) j
			mul $s2, $s2, TAMANHO_DADO #(linha * ordem + coluna) * tamanho_do_dado
			add $s2, $s2, $a2 #adiciono o endere�o base ao que j� foi calculado e coloca em s2
			#agora s2 possui o endere�o daquilo que est� na posi��o 0,0
			li $v0, 4 #instru��o para impress�o de string
			la $a0, posicao #indica endere�o da vari�vel a ser impressa, no caso "posicao"
			syscall #"fa�a" imprime o que est� em $a0
			li $v0, 1 #imprime inteiro
			move $a0, $s0 #coloca o que est� em $s0 (linha) em $a0 para que seja impresso
			syscall #fa�a
			li $v0, 1#imprime inteiro
			la $a0, ($s1)#coloca o que est� em $s1 (coluna) em $a0 para que seja impresso
			syscall #fa�a
			li $v0, 6 #le float -> aquilo que ser� lido ser� armazenado no registrador $f0
			syscall #fa�a
			swc1 $f0, ($s2) #armazena o valor que est� em $f0 no endere�o que est� em $s2 
			addi $s1, $s1, 1 #adiciona 1 a vari�vel da coluna, an�logo a j++
			blt $s1, $a1, whilej #se s1(j) for < do que o que est� em $a1 (3), "continue"
		addi $s0, $s0, 1 #adiciona 1 a vari�vel da linha, an�logo a i++
		blt $s0, $a1, whilei #se s0(i) for < do que o que est� em $a1 (3), "continue"
			
	eh_inversivel: #para calcular se � ou n�o invers�vel
		#F�rmula para calcular a primeira parte do determinante
		#det_pos = (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0])+ (matriz[0][2]*matriz[1][0]*matriz[2][1]);
		#acessar matriz [0][0]
		li $s0, 0 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 0,0
		lwc1 $f3, ($s2) #pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f3)
		#acessar matriz [1][1]
		li $s3, 1 #indice da linha
		li $s4, 1 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 # s5 = s5*s4 = i*k + j
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 #adiciono o endere�o base -> s5 tem o que est� na posi��o 1,1
		lwc1 $f4, ($s5)#pego o que est� nessa posi��o ($s5) e coloco em um registrador para manipular em mem�ria principal ($f4)
		
		# o que no C seria matriz[0][0] * matriz[1][1] 
		mul.s $f5, $f3, $f4 #multiplico $f3 e $f4 e aramzeno o resultado em $f5. O mul.s � usado para o tipo float
		# matriz[2][2]
		li $s0, 2 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 2,2
		lwc1 $f4, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que em C seria matriz[0][0] * matriz[1][1] * matriz[2][2]
		mul.s $f5, $f5, $f4
		
		# (matriz[0][1]*matriz[1][2]*matriz[2][0])
		#acessar a matriz [0][1]
		li $s0, 0 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 0,1
		lwc1 $f3, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f3)
		
		#acessar a matriz [1][2]
		li $s3, 1 #indice da linha
		li $s4, 2 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 # s5 = s5*s4 = i*k + j
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 #adiciono o endere�o base -> s5 tem o que est� na posi��o 1,2 (de baixo para cima)
		lwc1 $f4, ($s5)#pego o que est� nessa posi��o ($s5) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que no C seria matriz[2][1] * matriz[1][2] 
		mul.s $f6, $f3, $f4
		# matriz[2][0]
		li $s0, 2 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 2,0
		lwc1 $f4, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que em C seria (matriz[0][1]*matriz[1][2]*matriz[2][0])
		mul.s $f6, $f6, $f4 #$f6 = $f6 * $f4
		
		# (matriz[0][2]*matriz[1][0]*matriz[2][1])
		#acessar a matriz [0][2]
		li $s0, 0 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 0,2
		lwc1 $f3, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f3)
		#acessar a matriz [1][0] que no assembly �
		li $s3, 1 #indice da linha
		li $s4, 2 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 # s5 = s5*s4 = i*k + j
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 #adiciono o endere�o base -> s5 tem o que est� na posi��o 1,2
		lwc1 $f4, ($s5)#pego o que est� nessa posi��o ($s5) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que no C seria matriz[0][2] * matriz[1][0]
		mul.s $f7, $f3, $f4
		# matriz[2][1] que no assembly �
		li $s0, 2 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 2,1
		lwc1 $f4, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que em C seria (matriz[0][1]*matriz[1][2]*matriz[2][0])
		mul.s $f7, $f7, $f4
		#somando tudo: (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0])+ (matriz[0][2]*matriz[1][0]*matriz[2][1]);
		add.s $f8, $f5, $f6
		add.s $f8, $f8, $f7
		#atribuir a f_det_pos que est� na mem�ria RAM
		swc1 $f8, f_det_pos
		
		#det_neg = (matriz[0][2] * matriz[1][1] * matriz[2][0]) + (matriz[0][1]*matriz[1][0]*matriz[2][2]) + (matriz[0][0]*matriz[1][2]*matriz[2][1]);
		#acessar a matriz [0][2] que no assembly �
		li $s0, 0 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 0,2 
		lwc1 $f3, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f3)
		#acessar a matriz [1][1] que no assembly � [1][1]
		li $s3, 1 #indice da linha
		li $s4, 1 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 # s5 = s5*s4 = i*k + j
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 #adiciono o endere�o base -> t2 tem o que est� na posi��o 1,1
		lwc1 $f4, ($s5)#pego o que est� nessa posi��o ($s5) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que no C seria matriz[0][2] * matriz[1][1] 
		# no assembly
		mul.s $f5, $f3, $f4
		# matriz[2][0]
		li $s0, 2 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 2,0
		lwc1 $f4, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que em C seria matriz[0][0] * matriz[1][1] * matriz[2][2]
		mul.s $f5, $f5, $f4
		
		# (matriz[0][1]*matriz[1][0]*matriz[2][2])
		#acessar a matriz [0][1] que no assembly �
		li $s0, 0 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 0,1
		lwc1 $f3, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f3)
		#acessar a matriz [1][0] que no assembly � 
		li $s3, 1 #indice da linha
		li $s4, 0 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 # s5 = s5*s4 = i*k + j
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 #adiciono o endere�o base -> s5 tem o que est� na posi��o 1,0
		lwc1 $f4, ($s5)#pego o que est� nessa posi��o ($s5) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que no C seria matriz[0][1] * matriz[1][0] 
		# no assembly
		mul.s $f6, $f3, $f4
		# matriz[2][2] que no assembly �
		li $s0, 2 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 2,2
		lwc1 $f4, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que em C seria (matriz[0][1]*matriz[1][0]*matriz[2][2])
		mul.s $f6, $f6, $f4
		
		# (matriz[0][0]*matriz[1][2]*matriz[2][1])
		#acessar a matriz [0][0] que no assembly �
		li $s0, 0 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 0,0
		lwc1 $f3, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f3)
		#acessar a matriz [1][2] que no assembly �
		li $s3, 1 #indice da linha
		li $s4, 2 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 # s5 = s5*s4 = i*k + j
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 #adiciono o endere�o base -> s5 tem o que est� na posi��o 1,2 
		lwc1 $f4, ($s5)#pego o que est� nessa posi��o ($s5) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que no C seria matriz[0][0] * matriz[1][2]
		mul.s $f7, $f3, $f4
		# matriz[2][1] que no assembly �
		li $s0, 2 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # s2 = s2*s1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 #adiciono o endere�o base -> s2 tem o que est� na posi��o 2,1
		lwc1 $f4, ($s2)#pego o que est� nessa posi��o ($s2) e coloco em um registrador para manipular em mem�ria principal ($f4)
		# o que em C seria (matriz[0][0]*matriz[1][2]*matriz[2][1])
		mul.s $f7, $f7, $f4
		#somando tudo: (matriz[0][0] * matriz[1][1] * matriz[2][2]) + (matriz[0][1]*matriz[1][2]*matriz[2][0])+ (matriz[0][2]*matriz[1][0]*matriz[2][1]);
		add.s $f9, $f5, $f6
		add.s $f9, $f9, $f7
		#atribuir a det_neg
		swc1 $f9, f_det_neg
		#fazer a subtra��o do determinante: f_det_pos - f_det_neg
		sub.s $f10, $f8, $f9
		#atribuo � vari�vel det que est� na mem�ria RAM
		swc1 $f10, det
		#pego o valor que est� na vari�vel zero do tipo float
		lwc1 $f11, zero
		#se o valor que est� na vari�vel zero do tipo float (0.0) for igual ao valor que est� no registrador $f10 (det), guarda 1 em $f0
		c.eq.s $f10, $f11
		#move de $f0 para $s0 para que seja poss�vel comparar com beq
		mfc1 $s0, $f0
		#se det == zero, chama n�o � invers�vel que acaba com o programa
		beq $s0, 0, nao_eh_inversivel
		#se det != zero, chama a fun��o matriz_inversa
		la $a3, matriz_a #passo o endere�o da base da matriz_a que estar� em $a3 como par�metro
		bne $s0, 0, matriz_inversa	
		
	nao_eh_inversivel:
		li $v0, 10 #encerra o programa
		syscall	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	
	
	
	matriz_inversa:	
		#matriz_a[0][0] = (((matriz[1][1]*matriz[2][2]) - (matriz[1][2]*matriz[2][1])));		
		
		#(matriz[1][1]*matriz[2][2])
		li $s0, 1 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 2 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		# o que no C seria matriz[1][1] * matriz[2][2]
		mul.s $f5, $f3, $f4
		
		#(matriz[1][2]*matriz[2][1])
		li $s0, 1 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 1 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		# o que no C seria matriz[0][0] * matriz[1][1] 
		mul.s $f6, $f3, $f4
		
		sub.s $f6, $f6, $f5
		neg.s $f6, $f6
		
		#acesso � matriz [0][0]
		li $s0, 0 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # t2 = t2*t1 = i*k + j
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a3 #adiciono o endere�o base -> t2 tem o que est� na posi��o 0,0 (de baixo para cima)
		
		#atribuo o valor calculado � posi��o correspondente na matriz de adjac�ncia
		swc1, $f6, ($s2)
		
		#repito o passo para todas as outras posi��es
		#matriz_a[0][1] = (-1)*(((matriz[1][0]*matriz[2][2]) - (matriz[1][2]*matriz[2][0])));
		
		
		#(matriz[1][0]*matriz[2][2])
		li $s0, 1 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 2 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2
		lwc1 $f4, ($s5)
		# o que no C seria matriz[1][1] * matriz[2][2]
		mul.s $f5, $f3, $f4
		
		#(matriz[1][2]*matriz[2][1])
		li $s0, 1 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 0 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2
		lwc1 $f4, ($s5)
		# o que no C seria matriz[0][0] * matriz[1][1] 
		
		mul.s $f6, $f3, $f4
		
		sub.s $f6, $f6, $f5
		neg.s $f6, $f6
		
		#acesso � matriz [0][0]
		li $s0, 0 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a3
		
		neg.s $f6, $f6
		swc1, $f6, ($s2)
		
		
		#matriz_a[0][2] = (((matriz[1][0]*matriz[2][1]) - (matriz[1][1]*matriz[2][0])));

		
		#(matriz[1][0]*matriz[2][1])
		li $s0, 1 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 1 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 # 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		# o que no C seria matriz[1][0] * matriz[2][1]
		mul.s $f5, $f3, $f4
		
		#(matriz[1][1]*matriz[2][0])
		li $s0, 1 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 # 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 0 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		# o que no C seria matriz[1][2] * matriz[2][0]
		
		mul.s $f6, $f3, $f4
		
		sub.s $f6, $f5, $f6 # f6 = f6 - f5
		neg.s $f6, $f6
		
		#acesso � matriz_a [0][2]
		li $s0, 0 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a3 
		
		swc1, $f6, ($s2)
		
		
		# matriz_a[1][0] = ((-1)*((matriz[0][1]*matriz[2][2]) - (matriz[0][2]*matriz[2][1])));
		
		#(matriz[0][1]*matriz[2][2])
		li $s0, 0 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 2 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		# o que no C seria matriz[1][0] * matriz[2][1]
		mul.s $f5, $f3, $f4
		
		#matriz[0][2]*matriz[2][1])
		li $s0, 0 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 1 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		# o que no C seria matriz[1][2] * matriz[2][0]
		
		mul.s $f6, $f3, $f4
		
		sub.s $f5, $f5, $f6 # f5 = f5-f6
		neg.s $f5, $f5
		
		#acesso � matriz_a [1][0]
		li $s0, 1 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a3 
		
		swc1, $f5, ($s2)
		
		
		# matriz_a[1][1] = (((matriz[0][0]*matriz[2][2]) - (matriz[0][2]*matriz[2][0])));

		
		#(matriz[0][0]*matriz[2][2])
		li $s0, 0 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 2 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		# o que no C seria matriz[1][0] * matriz[2][1]
		mul.s $f5, $f3, $f4
		
		#(matriz[0][2]*matriz[2][0])
		li $s0, 0 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 0 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2
		lwc1 $f4, ($s5)
		
		mul.s $f6, $f3, $f4
		
		sub.s $f6, $f6, $f5 # f5 = f5-f6
		neg.s $f6, $f6
		
		#acesso � matriz_a [1][1]
		li $s0, 1 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a3 
		
		swc1, $f6, ($s2)
		
		
		# matriz_a[1][2] = ((-1)*((matriz[0][0]*matriz[2][1]) - (matriz[0][1]*matriz[2][0])));

		
		#(matriz[0][0]*matriz[2][1])
		li $s0, 0 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 1 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2
		lwc1 $f4, ($s5)
		# o que no C seria matriz[1][0] * matriz[2][1]
		mul.s $f5, $f3, $f4
		
		#(matriz[0][1]*matriz[2][0])
		li $s0, 0 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 2 #indice da linha
		li $s4, 0 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2
		lwc1 $f4, ($s5)
		
		mul.s $f6, $f3, $f4
		
		sub.s $f5, $f5, $f6 # f5 = f5-f6
		neg.s $f5, $f5
		
		#acesso � matriz_a [1][2]
		li $s0, 1 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a3 
		
		swc1, $f5, ($s2)
		
		
		# matriz_a[2][0] = (((matriz[0][1]*matriz[1][2]) - (matriz[0][2]*matriz[1][1])));

		
		#(matriz[0][1]*matriz[1][2])
		li $s0, 0 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 1 #indice da linha
		li $s4, 2 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		mul.s $f5, $f3, $f4
		
		#(matriz[0][2]*matriz[1][1])
		li $s0, 0 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 1 #indice da linha
		li $s4, 1 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		
		mul.s $f6, $f3, $f4
		
		sub.s $f6, $f6, $f5 # f5 = f5-f6
		neg.s $f6, $f6
		
		#acesso � matriz_a [2][0]
		li $s0, 2 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a3
		
		swc1, $f6, ($s2)

		
		# matriz_a[2][1] = ((-1)*(((matriz[0][0]*matriz[1][2]) - (matriz[0][2]*matriz[1][0]))));


		#(matriz[0][0]*matriz[1][2])
		li $s0, 0 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 1 #indice da linha
		li $s4, 2 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		
		mul.s $f5, $f3, $f4
		
		#(matriz[0][2]*matriz[1][0])
		li $s0, 0 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2
		lwc1 $f3, ($s2)
		
		li $s3, 1 #indice da linha
		li $s4, 0 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		
		mul.s $f6, $f3, $f4
		
		sub.s $f5, $f5, $f6 # f5 = f5-f6
		neg.s $f5, $f5
		
		#acesso � matriz_a [2][1]
		li $s0, 2 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a3 
		
		swc1, $f5, ($s2)

		
		# matriz_a[2][2] = ((matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]));


		#(matriz[0][0]*matriz[1][1])
		li $s0, 0 #indice da linha
		li $s1, 0 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 1 #indice da linha
		li $s4, 1 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4 
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		mul.s $f5, $f3, $f4
		
		#(matriz[0][1]*matriz[1][0])
		li $s0, 0 #indice da linha
		li $s1, 1 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1 
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a2 
		lwc1 $f3, ($s2)
		
		li $s3, 1 #indice da linha
		li $s4, 0 #indice da coluna
		mul $s5, $s3, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s5, $s5, $s4
		mul $s5, $s5, TAMANHO_DADO
		add $s5, $s5, $a2 
		lwc1 $f4, ($s5)
		
		mul.s $f6, $f3, $f4
		
		sub.s $f6, $f6, $f5 # f6 = f6-f5
		neg.s $f6, $f6
		
		#acesso � matriz_a [2][2]
		li $s0, 2 #indice da linha
		li $s1, 2 #indice da coluna
		mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos
		add $s2, $s2, $s1
		mul $s2, $s2, TAMANHO_DADO
		add $s2, $s2, $a3
		
		swc1, $f6, ($s2)
		
		la $a2, matriz_inv #endere�o da base da matriz inversa ou transposta da de adjac�ncia est� no $a2
		#loops para percorrer linha  e coluna, como em C que h� dois fors, um dentro do outro
		#an�logo ao loop para formar a matriz inversa de fato e imprimir os valores adicionados
		li $s0, 0 
		loopi: #enquanto
			li $s1, 0 #coloca zero no registrador t1 - representa j
			loopj: 
				mul $s2, $s0, $a1 #indice da linha * tamanho da coluna = em qual linha estamos da matriz_a
				add $s2, $s2, $s1 
				mul $s2, $s2, TAMANHO_DADO
				add $s2, $s2, $a2 
				
				mul $s3, $s1, $a1 #indice da linha * tamanho da coluna = em qual linha estamos da matriz_inv
				add $s3, $s3, $s0
				mul $s3, $s3, TAMANHO_DADO
				add $s3, $s3, $a3 
				lwc1 $f2, ($s3)
				lwc1 $f3, det #pego o valor do determinante que est� na mem�ria RAM
				
				div.s $f2, $f2, $f3 # divido o valor que est� ma matriz_a pelo determinante
				
				swc1 $f2, ($s2) #armazeno na matriz_inv
				
				#movo para $f12 para poder imprimir o float (padr�o para mover dados do tipo float e imprimir) 
				lwc1 $f1, zero
				add.s $f12, $f1, $f2
				
				li $v0, 2 #imprimir float	
				syscall #"fa�a"
				
				li $v0, 4#imprimir string
				la $a0, espaco
				syscall
				
				addi $s1, $s1, 1 #adiciona 1, an�logo a j++
				blt $s1, $a1, loopj #se s0(j) < (3), "continue"
			addi $s0, $s0, 1 #adiciona 1, an�logo a j++
			li $v0, 4#imprimir string
			la $a0, enter
			syscall	
			blt $s0, $a1, loopi #se s0(i) < 3, "continue"
		
		li $v0, 10 #finaliza
		syscall
				
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	
