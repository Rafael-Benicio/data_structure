#include <stdio.h>
#include <stdlib.h>

typedef int KEY_TYPE;

typedef struct adjacencia {
  int vertice;
  KEY_TYPE peso;
  struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice {
  ADJACENCIA *cap;
} VERTICE;

typedef struct grafo {
  int vertices;
  int arestas;
  VERTICE *adj;
} GRAFO;

GRAFO *criandoGrapo(int v) {
  GRAFO *g = (GRAFO *)malloc(sizeof(GRAFO));
  g->vertices = v;
  g->arestas = 0;
  g->adj = (VERTICE *)malloc(v * sizeof(VERTICE));
  int i;
  for (i = 0; i < v; i++)
    g->adj[i].cap = NULL;
  return (g);
}

ADJACENCIA *criaAdj(int v, int peso) {
  ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
  temp->vertice = v;
  temp->peso = peso;
  temp->prox = NULL;
  return temp;
}

bool criaAresta(GRAFO *gr, int vi, int vf, KEY_TYPE p) {
  if (!gr)
    return false;
  if ((vf < 0) || (vf >= gr->vertices))
    return false;
  if ((vi < 0) || (vi >= gr->vertices))
    return false;
  ADJACENCIA *novo = criaAdj(vf, p);
  novo->prox = gr->adj[vi].cap;
  gr->adj[vi].cap = novo;
  gr->arestas++;
  return true;
}

void imprime(GRAFO *gr) {
  printf("Vertices: %d. Arestas: %d.\n", gr->vertices, gr->arestas);
  int i;
  for (i = 0; i < gr->vertices; i++) {
    printf("v%d: ", i);
    ADJACENCIA *ad = gr->adj[i].cap;
    while (ad) {
      printf("v%d(%d)", ad->vertice, ad->peso);
      ad = ad->prox;
    }
    printf("\n");
  }
}

int main() {
  GRAFO *gr = criandoGrapo(5);
  criaAresta(gr, 0, 1, 2);
  criaAresta(gr, 1, 2, 4);
  criaAresta(gr, 2, 0, 12);
  criaAresta(gr, 2, 4, 40);
  criaAresta(gr, 3, 1, 3);
  criaAresta(gr, 4, 3, 8);
  imprime(gr);

  return 0;
}