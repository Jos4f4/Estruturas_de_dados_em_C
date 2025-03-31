#include <stdio.h>
#include <string.h>

typedef struct{
	int codigo;
	char nome[30];
	int qtd;
	float valor;
} produto;

int main(){
	produto p1, p2;
	float t1, t2;
	
	p1.codigo = 1;
	strcpy(p1.nome, "Tijolo_6_furos");
	p1.qtd = 10000;
	p1.valor = 0.25;
	
	p2.codigo = 2;
	printf("Informe o nome do produto: ");
	scanf("%s", p2.nome);
	printf("Informe o valor unitario: ");
	scanf("%f", &p2.valor);
	printf("Informe a quantidade em estoque: ");
	scanf("%d", &p2.qtd);
	
	t1 = p1.qtd * p1.valor;
	t2 = p2.qtd * p2.valor;
	
	printf("\nValor em estoque: \n");
	if(t1<t2){
		printf("%s : R$ %.2f\n", p1.nome, t1);
		printf("%s : R$ %.2f\n", p2.nome, t2);
	}
	else{
		printf("%s : R$ %.2f\n", p2.nome, t2);
		printf("%s : R$ %.2f\n", p1.nome, t1);
	}
	return 0;
}