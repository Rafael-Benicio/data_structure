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
    raiz->esq = adiciona(raiz->esq, no);
  } else {
    raiz->dir = adiciona(raiz->dir, no);
  }
  return raiz;
}

PONT criaNo(KEY_TYPE value) {
  PONT novo_no = (PONT)malloc(sizeof(NO));
  novo_no->key = value;
  novo_no->esq = NULL;
  novo_no->dir = NULL;
  return novo_no;
}

int numeroNos(PONT r) {
  if (!r)
    return 0;
  return numeroNos(r->esq) + 1 + numeroNos(r->dir);
}

void showTree(PONT r) {
  if (r != NULL) {
    printf("%i", r->key);
    printf("(");
    showTree(r->esq);
    printf(" | ");
    showTree(r->dir);
    printf(")");
  }
}

PONT buscaNo(PONT raiz, KEY_TYPE ch, PONT *pai) {
  PONT atual = raiz;
  *pai = NULL;
  while (atual) {
    if (atual->key == ch)
      return atual;
    *pai = atual;
    if (ch < atual->key)
      atual = atual->esq;
    else
      atual = atual->dir;
  }
  return NULL;
}

PONT removeNo(PONT raiz, KEY_TYPE ch) {
  PONT pai, no, p, q;
  no = buscaNo(raiz, ch, &pai);
  if (no == NULL)
    return raiz;
  if (!no->esq || !no->dir) {
    if (!no->esq)
      q = no->dir;
    else
      q = no->esq;
  } else {
    p = no;
    q = no->esq;
    while (q->dir) {
      p = q;
      q = q->dir;
    }
    if (p != no) {
      p->dir = q->esq;
      q->esq = no->esq;
    }
    q->dir = no->dir;
  }
  if (!pai) {
    free(no);
    return q;
  }
  if (ch < pai->key)
    pai->esq = q;
  else
    pai->dir = q;
  free(no);
  return raiz;
}

int main() {
  PONT my_tree = inicializa();
  PONT novo_no1 = criaNo(23);
  my_tree = adiciona(my_tree, novo_no1);
  PONT novo_no2 = criaNo(2);
  my_tree = adiciona(my_tree, novo_no2);
  PONT novo_no3 = criaNo(53);
  my_tree = adiciona(my_tree, novo_no3);
  PONT novo_no4 = criaNo(73);
  my_tree = adiciona(my_tree, novo_no4);
  PONT novo_no5 = criaNo(13);
  my_tree = adiciona(my_tree, novo_no5);
  PONT novo_no6 = criaNo(1);
  my_tree = adiciona(my_tree, novo_no6);
  printf("Numeor de nos : %i\n", numeroNos(my_tree));
  showTree(my_tree);
  return 0;
}