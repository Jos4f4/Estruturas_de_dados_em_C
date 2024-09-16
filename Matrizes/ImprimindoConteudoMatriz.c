#include <stdio.h>

int main(){
	
	int i, j,mat1[3][3];

	char mat5[3][4] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
	
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Digite o valor %d %d: ", i, j);
			scanf("%d", &mat1[i][j]);
		}
	}
	for(i=0; i<3; i++){
		for(j=0;j<3;j++){
			printf("%d ", mat1[i][j]);
		}
		printf("\n");
	}	
	return 0;
}