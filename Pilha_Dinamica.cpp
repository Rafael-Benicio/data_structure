#include <stdio.h>
#include <malloc.h>

#define TIPOCHAVE int

typedef struct{
	TIPOCHAVE chave;
}REGISTRO;

typedef struct aux{
	REGISTRO reg;
	struct aux* prox;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
	PONT topo;
}PILHA;

void inicializaPilha(PILHA *p){
	p->topo=NULL;
};

int tamanho(PILHA*p){
	PONT end=p->topo;
	int tam =0;
	while (end!=NULL){
		tam++;
		end=end->prox;
	}
	return tam;

};

bool estaVazia(PILHA* p){
	return (p->topo==NULL) ? true: false;
};

bool inerirElementoPilha(PILHA* p,REGISTRO reg){
	PONT novo=(PONT) malloc(sizeof(ELEMENTO));
	novo->reg=reg;
	novo->prox=p->topo;
	p->topo=novo;
	return true;
}

bool excluiElementoPilha(PILHA *p,REGISTRO *reg){
	if (p->topo==NULL) return false;
	*reg=p->topo->reg;
	PONT apagar=p->topo;
	free(apagar)
	return true;
}

bool reinicializa(PILHA *p){
	PONT apagar;
	PONT posicao=p->topo;
	while (posicao!=NULL){
		apagar=posicao;
		posicao=posicao->prox;
		free(apagar);
	}
	p->topo=NULL;
	return true;
}

int main(){
	printf("oi mundo\n");
	return 0;
}