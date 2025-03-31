#include <stdio.h>
#include <stdlib.h>

/*	Aula 113: Exercicio 03
	3) Escrever um programa que le um vetor N de tamanho 20 e o imprime na tela.
	Em seguida, troque o 1º elemento com o ultimo, o 2º com o penultimo, ... ate o 
	10º com o 11º. Imprima o vetor N modificado...*/
	
int main(){
	
	int a, fim=19, copia, vetor[20];
	
	for(a=0;a<20;a++){
		printf("digite %d: ", a);
		scanf("%d", &vetor[a]);
	}
	
	printf("\nVetor original: ");
	for(a=0;a<20;a++){
		printf("%2d ", vetor[a]);
	}
	
	for(a=0;a<10;a++){
		copia=vetor[a];
		vetor[a] = vetor[fim];
		vetor[fim] = copia;
		fim--;
	}
	
	printf("\nVetor modificado: ");
	for(a=0;a<20;a++){
		printf("%2d ", vetor[a]);
	}
	
	return 0;
}