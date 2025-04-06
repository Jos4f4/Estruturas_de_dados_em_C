#include <stdio.h>
#include <stdlib.h>

//Estrutura do nó
typedef struct nodeitem {
	int info;
	struct nodeitem *next;
} node;

typedef struct {
	node top;
} stack;

node *newMode(int info);
stack *newStack();
void push(stack *s, int value);
int pop(stack *s);
int top(stack *s);
int isStackEmpty(stack *s);
int isStackFull(stack *s);

int main(){
	stack *p;
	p = newStack();
	
	push(p, 15);
	push(p, 10);
	
	printf("Topo: %d\n", top(p));
	printf("Valor removido: %d\n", pop(p));
	printf("Topo: %d\n", top(p));
	
	if(isStackEmpty(p)){
		printf("\nPilha se encontra vazia!\n");
	}
	
	//depreciado
	if(!isStackFull(p)){
		printf("\nPilha nao se encontra cheia!\n");
	}
	return 0;
}

//Aloca e inicializa a pilha propriamente dita
stack *newStack(){
	stack *p = (stack *)malloc(sizeof(stack));
	p->top = NULL;
	return p;
}

//Alocação de memória de um novo nó
node *newMode(int info){
	node *n = (node *)malloc(sizeof(node));
	n->info=info;
	n->next=NULL;
	return n;
}

//Insere valores na pilha
void push(stack *s, int value){
	node *n = newMode(value);
	n->next=s->top;
	s->top=n;
}

//Remove um elemento da pilha
int pop(stack *s){
	node *n;
	int aux;
	
	if(isStackEmpty(s)){
		printf("Stack underflow!!!\n");
		return;
	}
	
	n=s->top;
	aux=n->info;
	s->top=n->next;
	free(n);
	
	return aux;
	
}

//Verifica o topo da pilha
int top(stack *s){
	if(isStackEmpty(s)){
		printf("Stack underflow!!!\n");
		return;
	}
	return s->top->info;
}

/*
//Verifica se a pilha está cheia - tornar-se depreciada quando uma pilha é dinâmica
int isStackFull(stack *s){
	return 0;
}

//Verifica se a pilha está vazia
int isStackEmpty(stack *s){
	return s->top==NULL;
}*/