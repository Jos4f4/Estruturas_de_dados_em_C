#include <stdio.h>
#include <locale.h>


int main(void){
	setlocale(LC_ALL, "Portuguese");

	int i;
	int num2[10];
	
	for(i = 0; i<10; i++){
		printf("Digite o valor do vetor %d: ", i);
		scanf("%d", &num2[i]);
	}
	
	//Alterando o conteúdo
	for(i = 0; i<10; i++){
		num2[i] = num2[i]*3;
	}
	
	printf("\n\n");
	for(i = 0; i<10; i++){
		printf("%d ", &num2[i]);
	}
	
	printf("\n\n");
	return 0;
}