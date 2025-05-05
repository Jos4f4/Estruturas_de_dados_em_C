#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void preenche(int vet[], int max);
void imprime(int vet[]);
void quicksort(int vet[], int left, int right);
void troca(int *x, int *y);
int partition(int vet[], int left, int right);
int buscaBinaria(int vet[],  int key, int left, int right);

int main(){
    int pos;
	int vet[N];

	srand(time(NULL));
	preenche(vet, 20);
	quicksort(vet, 0, N-1);
	imprime(vet);

	pos = buscaBinaria(vet, 10, 0, N-1);
	if(pos<0){
        printf("Valor nao encontrado!\n");
	}
	else{
        printf("Encontrou o valor da posicao %d\n", pos+1);
	}
}

int buscaBinaria(int vet[], int key, int left, int right){
    int mid;
    if(right<left){
        return -1;
    }

    mid=(left+right)/2;
    if(vet[mid]==key){
        return mid;
    }
    else if(key<vet[mid]){
        return buscaBinaria(vet, key, left, mid-1);
    }
    else {
        return buscaBinaria(vet, key, mid+1, right);
    }
}

void imprime(int vet[]){
    int i;
    for(i=0;i<N;i++){
        printf(" [%2d] ", vet[i]);
    }
    printf("\n");
}

void preenche(int vet[], int max){
	int i;
	for(i=0;i<N;i++){
		vet[i] = (rand() % max) + 1;
	}
}

void troca(int *x, int *y){
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}


int partition(int vet[], int left, int right){
	int i, j, pivot;
	pivot=vet[left];
	i=left+1;
	for(j=i;j<=right;j++){
		if(vet[j]<pivot){
			troca(&vet[j], &vet[i]);
			i++;
		}
	}
	troca(&vet[left], &vet[i-1]);
	return i-1;
}


void quicksort(int vet[], int left, int right){
	int pivot;

	if(left>=right){
		return;
	}

	pivot = partition(vet, left, right);
	quicksort(vet, left, pivot-1);
	quicksort(vet, pivot+1, right);
}
