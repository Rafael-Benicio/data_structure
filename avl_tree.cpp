#include <malloc.h>
#include <stdio.h>

#define KEY_TYPE int

typedef struct aux {
  KEY_TYPE key;
  struct aux *esq;
  struct aux *dir;
  int h;
} NO;

typedef NO *PONT;

PONT criaNo(KEY_TYPE value) {
  PONT novo_no = (PONT)malloc(sizeof(NO));
  novo_no->key = value;
  novo_no->esq = NULL;
  novo_no->dir = NULL;
  novo_no->h = 0;
  return novo_no;
}

PONT inicializa() { return NULL; }

int max(int a, int b) { return (a > b) ? a : b; }

int altura(PONT r) { return (!r) ? -1 : r->h; }

PONT direita(PONT r) {
  PONT aux;
  aux = r->esq;
  r->esq = aux->dir;
  aux->dir = r;

  r->h = max(altura(r->dir), altura(r->esq)) + 1;
  aux->h = max(altura(aux->esq), r->h) + 1;

  return aux;
}

PONT esquerda(PONT r) {
  PONT aux;
  aux = r->dir;
  r->dir = aux->esq;
  aux->esq = r;

  r->h = max(altura(r->dir), altura(r->esq)) + 1;
  aux->h = max(altura(aux->esq), r->h) + 1;

  return aux;
}

PONT rotacaoDubplaDireita(PONT r) {
  r->esq = esquerda(r->esq);
  return direita(r);
}
PONT rotacaoDubplaEsquerda(PONT r) {
  r->dir = direita(r->dir);
  return esquerda(r);
}

PONT insert(PONT raiz, KEY_TYPE ch) {
  if (!raiz)
    return criaNo(ch);
  if (ch < raiz->key) {
    raiz->esq = insert(raiz->esq, ch);
    if ((altura(raiz->esq)) - altura(raiz->dir) == 2)
      if (ch < raiz->esq->key)
        raiz = direita(raiz);
      else
        raiz = rotacaoDubplaDireita(raiz);
  } else if (ch > raiz->key) {
    raiz->dir = insert(raiz->dir, ch);
    if (altura(raiz->dir) - altura(raiz->esq) == 2)
      if (ch > raiz->dir->key)
        raiz = esquerda(raiz);
      else
        raiz = rotacaoDubplaEsquerda(raiz);
  }
  raiz->h = max(altura(raiz->esq), altura(raiz->dir)) + 1;
  return raiz;
}

int main() {
  PONT my_avl = inicializa();

  return 0;
}
