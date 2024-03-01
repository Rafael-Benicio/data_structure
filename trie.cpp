#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIPORET bool
#define N_ALPH 26

typedef struct aux {
  TIPORET fim;
  struct aux *filhos[N_ALPH];
} NO;

typedef NO *PONT;

PONT criaNo() {
  PONT p = NULL;
  p = (PONT)malloc(sizeof(NO));
  if (p) {
    p->fim = false;
    int i;
    for (i = 0; i < N_ALPH; i++) {
      p->filhos[i] = NULL;
    }
  }
  return p;
}

PONT inicializa() { return criaNo(); }

int mapearIndice(char c) { return ((int)c - (int)'a'); }

void insert(PONT raiz, char *chave) {
  int nivel;
  int compr = strlen(chave);
  int i;

  PONT p = raiz;
  for (nivel = 0; nivel < compr; nivel++) {
    i = mapearIndice(chave[nivel]);
    if (!p->filhos[i]) {
      p->filhos[i] = criaNo();
    }
    p = p->filhos[i];
  }
  p->fim = true;
}

bool busca(PONT raiz, char *chave) {
  int nivel;
  int compr = strlen(chave);
  int i;
  PONT p = raiz;

  for (nivel = 0; nivel < compr; nivel++) {
    i = mapearIndice(chave[nivel]);
    if (!p->filhos[i])
      return false;
    p = p->filhos[i];
  }
  return p->fim;
}

int main() {
  PONT my_trie = inicializa();

  char meu[] = "meu";
  char ovo[] = "mau";

  insert(my_trie, meu);
  if (busca(my_trie, meu)) {
    printf("Achou\n");
  }

  if (!busca(my_trie, ovo)) {
    printf("Não achou\n");
  }
  return 0;
}