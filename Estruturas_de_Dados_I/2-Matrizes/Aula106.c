#include <stdio.h>
#include <stdlib.h>

//Aula 106: Como criar uma matriz

int main(){
	//tipo identificador
	int vet[10];
	
	int mat1[3][3] = {1,2,3,4,5,6,7,8,9};
	/*       c0 c1 c2
	linha 0   1  2  3
	linha 1   4  5  6
	linha 2   7  8  9
	*/
	
	int mat2[][3] = {1,2,3,4,5,6,7};
	int mat3[3][3] = {0};
	
	float mat4[4][5];
	char mat5[10][10];
	return 0;
}