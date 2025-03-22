#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 102: Como gerar números aleatorios para dentro de um intervalo determinado

int main(){
	
	int i;
	int num2[40];
	
	srand(time(NULL));
	
	for(i=0; i<40; i++){
		num2[i] = 1 + rand() % 99; //Entre 1 e 99 
	}
	
	printf("\n");
	for(i=0; i<40; i++){
		printf("%d ", num2[i]);
	}
	printf("\n");
	
	return 0;
}
