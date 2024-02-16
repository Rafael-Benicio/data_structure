#include <malloc.h>
#include <stdio.h>

#define KEY_TYPE int

typedef struct aux {
  KEY_TYPE key;
  struct aux *esq;
  struct aux *dir;
} NO;

typedef NO *PONT;

// typedef struct{
//   NO *root;
// }Tree;

PONT inicializa() { return (NULL); }

PONT adiciona(PONT raiz, PONT no) {
  if (raiz == NULL)
    return no;
  if (no->key < raiz->key) {
    raiz->esq=adiciona(raiz->esq, no);
  } else {
    raiz->dir=adiciona(raiz->dir, no);
  }
  return raiz;
}

PONT criaNo(KEY_TYPE value){
  PONT novo_no=(PONT) malloc(sizeof(NO));
  novo_no->key=value;
  novo_no->esq=NULL;
  novo_no->dir=NULL;
  return novo_no;
}

int main() {
  PONT my_tree = inicializa();
  PONT novo_no1=criaNo(23);
  my_tree=adiciona(my_tree,novo_no1);
  PONT novo_no2=criaNo(2);
  my_tree=adiciona(my_tree,novo_no2);
  PONT novo_no3=criaNo(53);
  my_tree=adiciona(my_tree,novo_no3);
  PONT novo_no4=criaNo(73);
  my_tree=adiciona(my_tree,novo_no4);
  PONT novo_no5=criaNo(13);
  my_tree=adiciona(my_tree,novo_no5);
  return 0;
}