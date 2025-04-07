#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
	int head, tail;
	int data[N];
} queue;

queue *newQueue();
void enqueue(queue *q, int value);
int dequeue(queue *p);
int isQueueEmpty(queue *q);
int isQueueFull(queue *q);
void showQueue(queue *q);

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
	q->head=0;
	q->tail=0;
}

//Insere novo valor na fila
void enqueue(queue *q, int value){
	if(isQueueFull(q)){
		printf("Fila cheia, nao eh possivel inserir um novo valor");
		return;
	}
	q->data[q->tail]=value;
	q->tail++;
}

//remove um valor da fila
int dequeue(queue *q){
	if(isQueueEmpty(q)){
		printf("Fila vazia, nao eh possivel remover um valor\n");
		return -1;
	}
	return q->data[q->head++];
}

//Verifica se a fila está vazia
int isQueueEmpty(queue *q){
	return q->head==q->tail;
}

//Verifica se a fila está cheia
int isQueueFull(queue *q){
	return q->tail==N;
}

//Imprimir fila
void showQueue(queue *q){
	int i ;
	if(isQueueEmpty(q)){
		printf("Fila vazia\n");
	}
	else {
		printf("Fila: \n");
	}
	for(i=q->head;i<q->tail; i++){
		printf(" [%2d] ", q->data[i]);
	}
	
	printf("\n");
}