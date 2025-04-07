#include <stdio.h>
#include <stdlib.h>

//criar o no
typedef struct NodeItem{
	int info;
	struct NodeItem *next;
} node;

typedef struct {
	node *head, *tail;
} queue;

queue *newQueue();
void enqueue(queue *q, int value);
int dequeue(queue *p);
int isQueueEmpty(queue *q);
//int isQueueFull(queue *q); deprecated, a fila nunca terá um valor maximo quando dinamica
void showQueue(queue *q);
node *newNode(int info);

int main(){
	queue *fila = newQueue();
	enqueue(fila, 5);
	enqueue(fila, 15);
	enqueue(fila, 22);
	enqueue(fila, 7);
	showQueue(fila);
	dequeue(fila);
	showQueue(fila);
}
//Aloca memoria pra fila
queue *newQueue(){
	queue *q = (queue *)malloc(sizeof(queue));
	q->head=NULL;
	q->tail=NULL;
}

//Aloca memoria pro nó
node *newNode(int info){
	node *n = (node *)malloc(sizeof(node));
	n->info=info;
	n->next=NULL;
	return n;
}

//Insere novo valor na fila
void enqueue(queue *q, int value){
	node *n = newNode(value);
	if(isQueueEmpty(q)){
		q->head=n;
		q->tail=n;
	}
	else{
		q->tail->next=n;
		q->tail = n;
	}
}

//remove um valor da fila
int dequeue(queue *q){
	node *n;
	int aux;
	if(isQueueEmpty(q)){
		printf("Fila vazia, nao eh possivel remover um valor\n");
		return -1;
	}
	n=q->head;
	aux=n->info;
	q->head=n->next;
	if(q->head == NULL){
		q->	tail=NULL;
	}
	free(n);
	return aux;
}

//Verifica se a fila está vazia
int isQueueEmpty(queue *q){
	return q->head==NULL;
}

//Verifica se a fila está cheia
/*int isQueueFull(queue *q){
	return q->tail==N;
}*/

//Imprimir fila
void showQueue(queue *q){
	node *n;
	if(isQueueEmpty(q)){
		printf("Fila vazia\n");
	}
	else {
		printf("Fila: \n");
	}
	n=q->head;
	while(n != NULL){
		printf(" [%2d] ", n->info);
		n=n->next;
	}
	
	printf("\n");
}