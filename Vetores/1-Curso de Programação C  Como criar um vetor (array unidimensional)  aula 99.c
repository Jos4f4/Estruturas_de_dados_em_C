#include <stdio.h>
#include <locale.h>

// Como criar um vetor

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	int i;
	int idade;
	char sexo;
	float n1;
	
	int num[10];
	int num2[] = {1, 5, 9, 15, 43};
	int num3[5] = {4, 7, 5}; //Vetores menores que a tamanho sempre serão preenchidos com zeros
	int num4[5] = {1, 2, 3, 4, 5, 6};
	int num5[5] = {0};
	
	char letras[100];
	char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
	
	float notas[3] =  {7.5, 8.3, 9.5};
	
	for(i=0; i<3; i++){
		printf("%.1f", notas[i]);	
	}

	
	return 0;
}