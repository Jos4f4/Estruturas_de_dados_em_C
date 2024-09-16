#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Gerando números aleatórios para uma matriz
int main(){
	
	int i, j;
	int mat1[3][3] = {11,12,13,14,15,16,17,18,19};
	
	
	srand(time(NULL));
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			//mat1[i][j] = mat1[i][j]*2;
			mat1[i][j] = rand();
		}
	}
	for(i=0; i<3; i++){
		for(j=0;j<3;j++){
			printf("%5d ", mat1[i][j]);
		}
		printf("\n");
	}	
	return 0;
}