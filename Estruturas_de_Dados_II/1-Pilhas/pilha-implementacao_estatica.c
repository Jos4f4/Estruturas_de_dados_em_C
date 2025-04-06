#include <stdio.h>
#include <stdlib.h>

#define N 30

typedef struct {
	int top;
	int data[N];
} stack;

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
	if(!isStackFull(p)){
		printf("\nPilha nao se encontra cheia!\n");
	}
	return 0;
}

//Aloca e inicializa a pilha propriamente dita
stack *newStack(){
	stack *p = (stack *)malloc(sizeof(stack));
	p->top = 0;
	return p;
}

//Insere valores na pilha
void push(stack *s, int value){
	if(isStackFull(s)){
		printf("Stack Overflow!!!");
		return;
	}	
	s->data[s->top]=value;
	s->top++;
}

//Remove um elemento da pilha
int pop(stack *s){
	if(isStackEmpty(s)){
		printf("Stack underflow!!!\n");
		return;
	}
	s->top=s->top-1;
	return s->data[s->top];
}

//Verifica o topo da pilha
int top(stack *s){
	if(isStackEmpty(s)){
		printf("Stack underflow!!!\n");
		return;
	}
	return s->data[s->top-1];
}
//Verifica se a pilha está cheia
int isStackFull(stack *s){
	return s->top==N;
}
//Verifica se a pilha está vazia
int isStackEmpty(stack *s){
	return s->top==0;
}