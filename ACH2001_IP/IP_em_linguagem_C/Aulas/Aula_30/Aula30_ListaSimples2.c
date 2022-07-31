/*
 Este programa gerencia listas lineares ligadas (implementacao dinamica).
 As listas gerenciadas podem ter um numero arbitrario de elementos.
*/
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;

typedef struct {
  int id;
  float media;
} Registro;


typedef struct aux{
  Registro reg;
  struct aux* prox;
} No;

typedef struct {
  No* inicio;
  int elementos;
} Lista;

/* Inicialização da lista ligada (a lista jah esta criada e eh apontada 
pelo endereco em l) */
void inicializa(Lista* l){
  l->inicio = NULL;
  l->elementos = 0;
} /* inicializa */

/* Exibição da lista sequencial */
void exibe(Lista* l){
  No* end = l->inicio;
  printf("Lista: \" ");
  while (end != NULL){
    printf("%i ", end->reg.id);
    end = end->prox;
  }
  printf("\"\n");
} /* exibe */ 

/* Retornar o tamanho da lista (numero de elementos) */
int tamanho(Lista* l) {
  return l->elementos;
} /* tamanho */

/* Busca sequencial (lista ordenada ou nao) */
int buscaSeq(Lista* l, int id){
  No* end = l->inicio;
  int pos = 0;
  while (end != NULL){
    if (end->reg.id == id) return pos;
    pos++;
    end = end->prox;
  }
  return -1;
} /* buscaSeq */

/* Exclusão do elemento da posição indicada */
bool exclui(Lista* l, int pos){
  if (pos<0 || pos>l->elementos-1) return false;
  int i;
  No* p;
  No* apagar;
  if (pos == 0){
    apagar = l->inicio;
    l->inicio = apagar->prox;
  }else{
    p = l->inicio;
    for (i=0;i<pos-1;i++) p = p->prox;
    apagar = p->prox;
    p->prox = apagar->prox;
  }
  free(apagar);
  l->elementos--;
  return true;
} /* excluirElemLista */

/* Inserção de elemento na posição indicada da lista */
bool insere(Lista* l, Registro reg, int pos) {
  if (pos<0 || pos>l->elementos) return false;
  No* novo = (No*) malloc(sizeof(No));
  novo->reg = reg;
  int i;
  No* p;
  if (pos == 0){
    novo->prox = l->inicio;
	l->inicio = novo;
  }else{
    p = l->inicio;
    for (i=0;i<pos-1;i++) p = p->prox;
    novo->prox = p->prox;
    p->prox = novo;
  }
  l->elementos++;
  return true;
} /* insere */

Registro novo(int id, float media){
    Registro res;
    res.id = id;
    res.media = media;
    return res;
}

int main() {
  Lista l1;
  inicializa(&l1);
  exibe(&l1);
  insere(&l1,novo(4, 8.5), 0);
  insere(&l1,novo(7, 6.5), 1);
  insere(&l1,novo(9, 7.5), 0);
  exibe(&l1);
  printf("Encontrado: %i\n",buscaSeq(&l1,7));


  Registro cadastro[2];
  cadastro[0] = novo(4, 8.5);
  cadastro[1] = novo(7, 6.5);
  
  Registro maior[3];
  maior[0] = cadastro[0];
  maior[1] = cadastro[1];
  maior[2] = novo(9, 7.5);

  return 0;
}


/* SAIDA
Lista: " "
Lista: " 9 4 7 "
Encontrado: 2
*/