#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aula 121: Exercício 11 | Faça um programa que imprima a diagonal principal de uma matriz 5 x 5

int main() {
    int tam = 5;
    int l, c, mat[tam][tam];

    srand(time(NULL));

    for(l = 0; l < tam; l++){
        for(c = 0;  c< tam; c++){
            mat[l][c] = rand() % 100;
        }
    }

    for(l = 0; l < tam; l++){
        for(c = 0;  c< tam; c++){
            printf("%d ", mat[l][c]);
        }
        printf("\n");
    }

    printf("\n\n");
    for(l = 0; l < tam; l++){
        printf("%d ", mat[l][l]); // diagonal principal onde linha e coluna são iguais
    }

    return 0;
}