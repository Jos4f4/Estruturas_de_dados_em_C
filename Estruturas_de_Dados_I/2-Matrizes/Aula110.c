#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 110: Como gerar numeros aleatorios para preencher uma matriz

int main(){
	
	int i, j, mat1[3][3] = {11,12,13,14,15,16,17,18,19};
	
	srand(time(NULL));
	
	for(i=0; i<3;i++){
		for(j=0;j<3;j++){
			mat1[i][j] = rand();
		}
	}
	
	printf("\n");
	
	for(i=0; i<3;i++){
		for(j=0;j<3;j++){
			printf("%5d ", mat1[i][j]);
		}
		
		printf("\n");
		
	}
	
	return 0;
}