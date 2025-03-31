#include <stdio.h>
#include <stdlib.h>

/*  Aula 111: Exercicio01
	1)Faca um programa que preencha um vetor de inteiros de tamanho 10 pedindo valores
	ao usuario. Em seguida, calcule e salve num segundo vetor o quadrado de cada elemento
	do primeiro vetor. Por fim, imprima os dois vetores. */

int main(){
	int i, vete1[10], vete2[10];
	
	for(i=0; i<10;i++){
		printf("Digite o valor da posicao %d: ", i);
		scanf("%d", &vete1[i]);
	}
	
	for(i=0; i<10;i++){
		vete2[i] = vete1[i] * vete1[i];
	}
	
	printf("Vetor 1: ");
	for(i=0; i<10;i++){
		printf("%d ", vete1[i]);
	}
	
	printf("\nVetor 2: ");
	for(i=0; i<10;i++){
		printf("%d ", vete2[i]);	
	}
	
	return 0;
}