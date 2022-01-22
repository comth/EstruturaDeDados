#include <stdlib.h>
#include <stdio.h>

typedef struct list{ // conjunto de estruturas de dados (isso aqui é a estrutura menor)
	int data;
	struct list *prox;
} List;

typedef struct pilha{ // estrutura com referência para o conjunto de estruturas de dados (aqui é a estrutura maior)
	List *topo;
} Pilha;

Pilha *p =(Pilha*)malloc(sizeof(Pilha));
List *l = NULL;

void push(int value) {
	if(p->topo==NULL) { // condição inicial para pilha vazia
		l = (List*)malloc(sizeof(List)); // crio uma nova estrutura na memória (principal)
		l->data = value; // atribuo valor para a primeira estrutura da pilha (que bem na real é uma lista)
		l->prox = NULL; // primeiro elemento da lista aponta sempre para null (ele tá embaixo)
		p->topo = l; // topo aponta para o novo 
	} else {
		List *block = (List*)malloc(sizeof(List)); // crio uma nova estrutura na memória
		block->data = value; // atribuo valor que foi passado pra função à nova estrutura
		block->prox = p->topo; // digo que a nova estrutura aponta para o elemento anterior onde era o topo da pilha
		p->topo = block; // atualizo o topo da pilha para o novo elemento que está sendo criado.
	}
}

int pop() {
	if(p->topo==NULL){
		printf("Lista Vazia ");
		return -1;
	} else {
		List *aux = p->topo;
		int valAux = aux->data;
		p->topo = p->topo->prox;
		free(aux); 
		return valAux;
	}
}

int main(){
	p->topo = NULL;
	push(10);
	push(55);
	push(82);
	push(22);
	push(73);
	
	printf("O que ja foi removido da pilha\n");
	for(int i=0; i<11; i++) {
		printf("%d\n" ,pop());
	}
	
	printf("\n\nO que ainda existe da pilha\n");
	for(List *aux = p->topo; aux!=NULL; aux = aux->prox) {
		printf("%d\n", aux->data);
	}
	return 0;
}