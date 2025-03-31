#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 124: Exercício 14 | Imprima apenas os valores abaixo da diagonal principal de uma matriz N x N

int main() {
    int tam = 10;
    int l, c, mat[tam][tam];

    srand(time(NULL));

    for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++)
            mat[l][c] = rand() % 100;
    }

    printf("\n\nMatriz gerada:\n");
    for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++)
            printf("%2d ", mat[l][c]);
        printf("\n");
    }

    printf("\n\nAbaixo da diagonal principal:\n");
    for(l = 0; l < tam; l++){
        for(c = 0; c < tam; c++){
            if(l > c)
                printf("%2d ", mat[l][c]);
            else
                printf("   ");
        }
        printf("\n");
    }
    printf("\n\n");

    return 0;
}