#include <stdio.h>
#include <stdlib.h>

#define KEY_TYPE int

typedef struct aux {
  KEY_TYPE chave;
  struct aux *primeiroFilho;
  struct aux *ProximoIrmão;
} NO;

typedef NO *PONT;

PONT buscaNo(KEY_TYPE ch, PONT raiz) {
  if (raiz == NULL)
    return NULL;
  if (raiz->chave == ch)
    return raiz;
  PONT p = raiz->primeiroFilho;
  while (p) {
    PONT resp = buscaNo(ch, p);
    if (resp)
      return resp;
    p = p->ProximoIrmão;
  }
  return NULL;
}

PONT criaNo(KEY_TYPE value) {
  PONT novo_no = (PONT)malloc(sizeof(NO));
  novo_no->chave = value;
  novo_no->primeiroFilho = NULL;
  novo_no->ProximoIrmão  = NULL;
  return novo_no;
}

bool adiciona(PONT raiz, KEY_TYPE novaChave, KEY_TYPE chavaPai) {
  PONT pai = buscaNo(chavaPai, raiz);
  if (!pai)
    return false;
  PONT filho = criaNo(novaChave);
  PONT p = pai->primeiroFilho;
  if (!p)
    pai->primeiroFilho = filho;
  else {
    while (p->ProximoIrmão)
      p = p->ProximoIrmão;
    p->ProximoIrmão = filho;
  }
  return true;
}

PONT inicializa(KEY_TYPE ch) { return criaNo(ch); }

void showTree(PONT r) {
  if (r == NULL)
    return;
  printf("%i(", r->chave);
  PONT p = r->primeiroFilho;
  while (p) {
    showTree(p);
    p = p->ProximoIrmão;
    printf(" | ");
  }
  printf(")");
}

int main() {
  PONT my_tree = inicializa(8);
  adiciona(my_tree, 23,8);
  adiciona(my_tree, 2,23);
  adiciona(my_tree, 53,8);
  adiciona(my_tree, 73,53);
  adiciona(my_tree, 13,2);
  adiciona(my_tree, 1,2);
  showTree(my_tree);
  return 0;
}