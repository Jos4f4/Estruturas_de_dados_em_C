#include <stdio.h>
#include <stdlib.h>

//Aula 108: Como ler uma matriz do teclado

int main(){
	
	int i, j, mat1[3][3] = {1,2,3,4,5,6,7,8,9};
	char mat5[3][4] = {'a','b','c','d','e','f','g','h','i','j','k','l'};
	
	for(i=0; i<3;i++){
		for(j=0;j<3;j++){
			printf("Digite um valor %d %d: \n", i, j);
			scanf("%d", &mat1[i][j]);
		}
	}
	
	printf("\n");
	
	for(i=0; i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ", mat1[i][j]);
		}
		
		printf("\n");
		
	}
	
	return 0;
}