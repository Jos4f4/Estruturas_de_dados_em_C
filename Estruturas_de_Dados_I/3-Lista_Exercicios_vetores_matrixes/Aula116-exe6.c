#include <stdio.h>
#include <stdlib.h>

//Aula 116: Imprimindo um vetor na ordem inversa
int main() {

    int i, opcao;
    float vetor[10];

    for(i = 0; i < 10; i++){
        printf("Digite o valor da posicao %d: ", i);
        scanf("%f", &vetor[i]);
    }

    do{
        printf("\n0 - Fizalizar\n1 - Imprimir vetor\n2 - Imp. vetor invertido\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 0:
            printf("Finalizando...\n");
            break;
        case 1:
            for(i = 0; i < 10; i++){
                printf("%.2f ", vetor[i]);
            }
            printf("\n");
            break;
        case 2:
            for(i = 9; i >= 0; i--){
                printf("%.2f ", vetor[i]);
            }
            printf("\n");
            break;
        default:
            printf("Opcao invaalida!\n");
        }

    }while(opcao != 0);

    return 0;
}