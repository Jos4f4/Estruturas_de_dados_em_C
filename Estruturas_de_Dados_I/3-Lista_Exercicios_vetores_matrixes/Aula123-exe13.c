#include <stdio.h>
#include <stdlib.h>

//Aula 123: Exercício 13 | Faça um programa para calcular a transposta de uma matriz 5 x 4

int main() {
    int tamL = 5, tamC = 4;
    int l, c, mat[tamL][tamC], trans[tamC][tamL];

    srand(time(NULL));

    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            mat[l][c] = rand() % 500;
        }
    }

    printf("\nMatriz original:\n");
    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            printf("%3d ", mat[l][c]);
        }
        printf("\n");
    }

    for(l = 0; l < tamL; l++){
        for(c = 0; c < tamC; c++){
            trans[c][l] = mat[l][c];
        }
    }

    printf("\nMatriz transposta:\n");
    for(l = 0; l < tamC; l++){
        for(c = 0; c < tamL; c++){
            printf("%3d ", trans[l][c]);
        }
        printf("\n");
    }

    return 0;
}