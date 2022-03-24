.data

	usr_msg: .asciiz "Escolha os elementos da matriz de ordem 3X3:\n"
	cant_msg: .asciiz "O determinante e zero.\n"
	question: .asciiz "Posicao "

.text

j main

print_usr_msg:                                         #escreve a mensagem inicial
	li $v0,4                                       #opcao de print para string
	la $a0, usr_msg                                #move o texto para o registrador de saida
	syscall                                        #chamada de sistema

print_parcial_msg:

	lw $t0,($sp)                                   #desempilha numero linha
	add $sp,$sp,4
	lw $t1,($sp)                                   #desempilha numero coluna
	add $sp,$sp,4

	li $v0,4
	la $a0, question
	syscall                                        #printa o texto de leitura

	li $v0,1
	move $a0, $t0
	syscall                                        #print numero da linha

	li $v0,11
	la $a0, ' '
	syscall                                        #printa caractere ' '

	li $v0,1
	move $a0, $t1
	syscall                                        #printa numero da coluna

	li $v0,11
	la $a0, '\n'
	syscall                                        #printa caractere ':'

	li $v0,6
      	syscall                                        #le entrada do usuario

      	swc1 $f0, ($t3)                                 #armazena o valor no espaco reservado

      	add $t3, $t3, 4

	add $t0,$t0,1                                  #adiciona 1 a coluna

	beq $t0, 3, check                               #se a coluna for igual a 3

	sub $sp,$sp,4
	sw  $t1,($sp)                                  #empilha valor da linha
	sub $sp,$sp,4
	sw  $t0,($sp)                                  #empilha valor da coluna
	j print_parcial_msg


check:
	li $t0, 0
	add $t1,$t1,1
	beq $t1, 3, end
	sub $sp,$sp,4
	sw  $t1,($sp)                                  #empilha valor da linha
	sub $sp,$sp,4
	sw  $t0,($sp)
	j print_parcial_msg

end:
	jr $ra



print_matrix:
	move $t4, $t3
	sub $t0, $t4, 36
	li $t2, 0
iterate:
	lwc1 $f12, ($t0)
	li $v0, 2
	syscall                                     #printa valores da matriz


	li $v0,11
	la $a0, ' '
	syscall                                     #printa caractere ' '

	add $t0, $t0, 4                             #avanca para o proximo valor da matriz
	add $t2,$t2,1
	beq $t2 ,3, print_newline
	bne $t3, $t0, iterate


print_newline:
	li $t2, 0
	li $v0,11
	la $a0, '\n'
	syscall
	bne $t3, $t0, iterate
	j end



determ:
	sub $t0, $t3, 36                         #restaura o ponteiro para o inicio da matriz
	lwc1 $f0, ($t0)                          #carrega no reg $f0 o valor da pos (0,0)
    	lwc1 $f1, 4($t0)                         #carrega no reg $f1 o valor da pos (1,0)
    	lwc1 $f2, 8($t0)                         #carrega no reg $f2 o valor da pos (2,0)

   	 lwc1 $f3, 12($t0)                       #carrega no reg $f3 o valor da pos (0,1)
  	  lwc1 $f4, 16($t0)                      #carrega no reg $f4 o valor da pos (1,1)
  	  lwc1 $f5, 20($t0)                      #carrega no reg $f5 o valor da pos (2,1)

  	  lwc1 $f6, 24($t0)                      #carrega no reg $f6 o valor da pos (0,2)
   	 lwc1 $f7, 28($t0)                       #carrega no reg $f7 o valor da pos (1,2)
   	 lwc1 $f8, 32($t0)                       #carrega no reg $f8 o valor da pos (2,2)  

	mul.s $f10, $f0, $f4                       #opera o algoritmo de sarrus diagonal
	mul.s $f10, $f10, $f8

	mul.s $f11, $f1, $f5                       #opera o algoritmo de sarrus
	mul.s $f11, $f11, $f6

	mul.s $f12, $f2, $f3                       #opera o algoritmo de sarrus
	mul.s $f12, $f12, $f7

	mul.s $f13, $f2, $f4                       #opera o algoritmo de sarrus diagona reversa
	mul.s $f13, $f13, $f6

	mul.s $f14, $f1, $f3                       #opera o algoritmo de sarrus
	mul.s $f14, $f14, $f8

	mul.s $f15, $f0, $f7                       #opera o algoritmo de sarrus
	mul.s $f15, $f15, $f5

	add.s $f16, $f10, $f11
	add.s $f16, $f16, $f12

	add.s $f17, $f13, $f14
	add.s $f17, $f17, $f15

	sub.s $f12, $f16, $f17


	j end

failure:
	li $v0,4                                       #opcao de print de string
	la $a0, cant_msg                               #move o texto para o reg de saida

	syscall
	j end_main                                     #desvia para a label end_main

adjunt:
	sub.s $f9, $f9, $f9                        #zerando registrador
	mul.s $f18, $f4, $f8
	mul.s $f19, $f5, $f7
	sub.s $f18, $f18,$f19                         #cofator(0,0)

	mul.s $f19, $f3, $f8
	mul.s $f20, $f5, $f6
	sub.s $f19, $f19,$f20
	sub.s $f19, $f9, $f19                        #cofator(0,1)

	mul.s $f20, $f3, $f7
	mul.s $f21, $f4, $f6
	sub.s $f20, $f20,$f21                        #cofator(0,2)

	mul.s $f21, $f1, $f8
	mul.s $f22, $f2, $f7
	sub.s $f21, $f21,$f22
	sub.s $f21, $f9,$f21                         #cofator(1,0)

	mul.s $f22, $f0, $f8
	mul.s $f23, $f2, $f6
	sub.s $f22, $f22,$f23                        #cofator(1,1)

	mul.s $f23, $f0, $f7
	mul.s $f24, $f1, $f6
	sub.s $f23, $f23, $f24
	sub.s $f23, $f9,$f23                         #cofator(1,2)

	mul.s $f24, $f1, $f5
	mul.s $f25, $f2, $f4
	sub.s $f24, $f24,$f25                        #cofator(2,0)

	mul.s $f25, $f0, $f5
	mul.s $f26, $f2, $f3
	sub.s $f25, $f25,$f26
	sub.s $f25, $f9,$f25                         #cofator(2,1)

	mul.s $f26, $f0, $f4
	mul.s $f27, $f1, $f3
	sub.s $f26, $f26,$f27                        #cofator(2,2)

	mov.s $f0, $f18
	mov.s $f1, $f19
	mov.s $f2, $f20

	mov.s $f3, $f21
	mov.s $f4, $f22
	mov.s $f5, $f23

	mov.s $f6, $f24
	mov.s $f7, $f25
	mov.s $f8, $f26

	j end

transpose:
	mov.s $f9, $f1
	mov.s $f1, $f3
	mov.s $f3, $f9                     #transpoe(0,1) com (1,0)

	mov.s $f9, $f2
	mov.s $f2, $f6
	mov.s $f6, $f9                    #transpoe(0,2) com (2,0)

	mov.s $f9, $f5
	mov.s $f5, $f7
	mov.s $f7, $f9                    #transpoe(1,2) com (2,1)


	j end

inverse:

	div.s $f0, $f0, $f12                #M(0,0)/det
        div.s $f1, $f1, $f12                #M(1,0)/det
        div.s $f2, $f2, $f12                #M(2,0)/det
        div.s $f3, $f3, $f12                #M(0,1)/det
        div.s $f4, $f4, $f12                #M(1,1)/det
        div.s $f5, $f5, $f12                #M(2,1)/det
        div.s $f6, $f6, $f12                #M(0,2)/det
        div.s $f7, $f7, $f12                #M(1,2)/det
        div.s $f8, $f8, $f12                #M(2,2)/det


	sub $t0, $t3, 36

	swc1 $f0, ($t0)
	swc1 $f1, 4($t0)
	swc1 $f2, 8($t0)

	swc1 $f3, 12($t0)
	swc1 $f4, 16($t0)
	swc1 $f5, 20($t0)

	swc1 $f6, 24($t0)
	swc1 $f7, 28($t0)
	swc1 $f8, 32($t0)

	j end

main:
	sub $sp, $sp, 36                                     #cria offset de 9 words no stack pointer
	la $t3, ($sp)                                        #salva o endereço de $sp em $t3 
	la $t4, ($sp)                                        #salva o endereço de $sp em $t4
	sub $sp,$sp,4                                        #cria um offset para uma variavel ‘linha’
	sw $zero,($sp)                                       #zera o conteudo apontado por $sp
	sub $sp,$sp,4                                        #cria um offset para uma variavel ‘coluna’
	sw $zero,($sp)                                       #zera o conteudo apontado por $sp

	jal print_usr_msg                                    #direciona para a label print_usr_msg
	jal determ                                           #direciona para a label determ
	mtc1 $zero, $f31                                     #move zero para $f31
	c.eq.s $f12,$f31                                     #compara $31 com $f12
	bc1t failure                                        #se igual vai para failure
	jal adjunt                                          #direciona para a label adjunt
	jal transpose                                       #direciona para a label transpose
	jal inverse                                         #direciona para a label inverse
	jal print_matrix                                    #direciona para a print_matrix

end_main:                                                  