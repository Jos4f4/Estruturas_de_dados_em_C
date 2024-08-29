#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");

	int i;
	int num2[10];
	
	//Gerando números pseualeatórios
	srand(time(NULL));
	
	for(i = 0; i<10; i++){
		num2[i] = 1 + rand() % 100;
	}
	

	printf("\n\n");
	for(i = 0; i<10; i++){
		printf("%d ", &num2[i]);
	}
	
	printf("\n\n");
	return 0;
}