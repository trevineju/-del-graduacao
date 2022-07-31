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

/* Função para a criação de novo registro */
Registro novo(int id, float media){
    Registro res;
    res.id = id;
    res.media = media;
    return res;
} /* novo */

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

/* Inserção de elemento na primeira posição da lista */
void insere(Lista* l, Registro reg) {
  No* novo = (No*) malloc(sizeof(No));
  novo->reg = reg;
  novo->prox = l->inicio;
  l->inicio = novo;
  l->elementos++;
} /* insere */



int main() {
  Lista l1;
  inicializa(&l1);
  exibe(&l1);
  insere(&l1,novo(4, 8.5));
  insere(&l1,novo(7, 6.5));
  insere(&l1,novo(9, 7.5));
  exibe(&l1);
  printf("Encontrado: %i\n",buscaSeq(&l1,7));

  No* n = l1.inicio;
  while (n != NULL){
    printf("%i\n", n->reg.id);
    n = n->prox;
  }

  return 0;
}


/* SAIDA
Lista: " "
Lista: " 9 7 4 "
Encontrado: 1
9
7
4
*/