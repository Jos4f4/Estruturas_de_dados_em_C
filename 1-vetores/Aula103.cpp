#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 102: Como gerar números aleatorios para preencher um vetor

int main(){
	
	int i;
	int num2[10];
	
	srand(time(NULL));
	
	for(i=0; i<10; i++){
		num2[i] = rand();
	}
	
	printf("\n");
	for(i=0; i<10; i++){
		printf("%d ", num2[i]);
	}
	printf("\n");
	
	return 0;
}
