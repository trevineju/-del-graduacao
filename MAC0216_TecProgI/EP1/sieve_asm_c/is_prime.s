global is_prime

is_prime:
  push ebp
  mov ebp, esp
  mov eax, [ebp + 8]

initial_check:
  cmp eax, 0      ;testa para 0
  je not_prime

  cmp eax, 1      ;testa para 1
  je yes_prime

  cmp eax, 2      ;testa para 2
  je yes_prime

testa_pares:
  mov edx, 0      ;zera edx
  mov ecx, 2
  div ecx         ;eax recebe o resultado e edx o resto
  cmp edx, 0      ;checa o resto da divisao
  je not_prime    ;dividiu, entao nao eh primo

  mov ecx, 3      ;inicializa o contador com 3
  mov edx, 0      ;zera edx

loop_impares:
  mov eax, [ebp + 8]  ;restaura o numero sendo analisado
  cmp eax, ecx        ;checa se o contador chegou no numero sendo analisado
  je yes_prime        ;chegou, entao eh primo

  div ecx             ;eax recebe o resultado e edx o resto
  cmp edx, 0          ;checa o resto da divisao
  je not_prime        ;dividiu, entao nao eh primo

  add ecx, 2          ;não dividiu, entao incrementa o contador
  jmp loop_impares    ;chama a label de novo

yes_prime:
  mov eax, 1
  jmp finish

not_prime:
  mov eax, 0
  jmp finish

finish:
  pop ebp
  ret
