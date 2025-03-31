#include <stdio.h>
#include <string.h>

void linha(int qtd, char simbolo);
void centraliza(char texto[], int qtd);
float porcentagem(float valor, float total);

int main(){
	linha(40, '-');
	centraliza("Ola Mundo!", 80);
	linha(40, '-');
	
	printf("Teste: %.0f%%: 	%.0f%%\n", porcentagem (20, 100)), porcentagem (5, porcentagem(20, 100));
	return 0;
}

float porcentagem(float valor, float total){
	return (valor / total)*100;	
}

void centraliza(char texto[], int qtd){
	int i, espaco;
	espaco = (qtd / 2) - (strlen(texto)/2);
	for(i=0; i<espaco; i++){
		printf(" ");
	}
	printf("%s\n", texto);
}

void linha(int qtd, char simbolo){
	int i;
	for(i=0; i<qtd; i++){
		printf("%c", simbolo);
		printf("\n");
	}
}