#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_PILHA 20

//guardar a nossa pilha
typedef struct {
	
	int vetor[TAMANHO_PILHA]; //tamanho da pilha
	int topo;
	
} Pilha;

//prototipos
void empilha(int valor, Pilha *pilha);
void empilha(Pilha *pilha);
int isCheia(Pilha *pilha);
int isVazia(Pilha *pilha);

//declaracao da funcao
void empilha(int valor, Pilha *pilha){
	//testar se tem espaco
	if(pilha->topo < TAMANHO_PILHA){
		//empilhar
		pilha->vetor[pilha->topo] = valor;
		pilha->topo++;
	}
	else{
		//pilha cheia
		printf("Nao ha mais espaco na pilha.\n");
	}
}

void desempilha(Pilha *pilha){
	//testar se a pilha nao estar vazia
	if(pilha->topo > 0){
		//desempilhar
		pilha->topo--;
		printf("Elemento retirado: %d\n", pilha->vetor[pilha->topo]);
	}
	else{
		//pilha vazia
		printf("A pilha esta vazia.\n");
	}
}

int isCheia(Pilha *pilha){
	if(pilha->topo >= TAMANHO_PILHA){
		return 1;
	}
	else{
		return 0;
	}
}

int isVazia(Pilha *pilha){
	if(pilha->topo == 0){
		return 1;
	}
	else{
		return 0;
	}
}

void imprimiPilha(Pilha *pilha){
	int i;
	for(i=(pilha->topo); i--; i>=0){
		printf("%02d\n", pilha->vetor[i]);
	}	
}

int main(int argc, char *argv[]){
	//declara uma pilha
	Pilha p;
	
	p.topo = 0;
	
	//empilhar elementos 
	//obs: REFERE-SE JUSTAMENTE A QUANTIDADE DE ELEMENTOS QUE CONTEM A PILHA
	empilha(5, &p);  //elemento 1
	empilha(2, &p);  //elemento 2
	empilha(6, &p);  //elemento 3
	empilha(9, &p);  //elemento 4
	empilha(50, &p);  //elemento 5

	imprimiPilha(&p);
	/*
	//empilha o numero 45
	p.vetor[p.topo] = 45;
	p.topo++;
	
	//desempilha o última número
	p.topo--;
	printf("Elemento retirado da pilha: %d\n", p.vetor[p.topo]);*/

	return 0;
}