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
		printf("%d\n", pilha->vetor[i]);
	}	
}

int main(int argc, char *argv[]){
	
	int c, d; //guarda o caracter (opcao) do usuario
	
	//declara uma pilha
	Pilha p;
	int n;
	
	p.topo = 0;
	
	printf("Digite 1 para entrar no looping\n");
	scanf("%d", &c);
	while(c == !0){	//se o usuario pressionar 'x', encerra o laco do menu
		printf("Digite '2' para empilhar\nDigite '3' para desempilhar\nDigite '4' para imprimir a pilha\n");
		//c = (char)getchar(); //captura caractere presssionado
		scanf("%d", &d);
		
		if(d==2){ //empilhar
			printf("Digite um numero para empilhar:\n");
			scanf("%d", &n);
			empilha(n, &p);	
		}
		
		if(d==3){ //desempilhar
			desempilha(&p);
		}
		
		if(d==4){ //imprimir a pilha
			printf("\n");
			imprimiPilha(&p);
		}
	 	
		printf("Continuar o fluxo? 1 continua e 0 fechar\n");
	 	scanf("%d", &c);
	}  

	return 0;
}