#include <stdio.h>

// Função para trocar dois elementos de posição
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para "ajustar" o heap (heapify)
// Garante que a subárvore com raiz em 'i' obedeça a propriedade de max-heap
void heapify(int vetor[], int n, int i) {
    int maior = i;          // Inicializa o maior como a raiz
    int esquerda = 2 * i + 1; // Filho da esquerda
    int direita = 2 * i + 2;  // Filho da direita

    // Se o filho da esquerda é maior que a raiz
    if (esquerda < n && vetor[esquerda] > vetor[maior])
        maior = esquerda;

    // Se o filho da direita é maior que o maior até agora
    if (direita < n && vetor[direita] > vetor[maior])
        maior = direita;

    // Se o maior não for a raiz
    if (maior != i) {
        trocar(&vetor[i], &vetor[maior]);

        // Recursivamente heapifica a subárvore afetada
        heapify(vetor, n, maior);
    }
}

// Função principal para executar o Heap Sort
void heapSort(int vetor[], int n) {
    // Constrói um heap máximo (max-heap)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vetor, n, i);

    // Extrai os elementos um por um do heap
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual (maior elemento) para o final
        trocar(&vetor[0], &vetor[i]);

        // Chama heapify no heap reduzido
        heapify(vetor, i, 0);
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", vetor[i]);
    printf("\n");
}

// Função principal (main)
int main() {
    int vetor[] = {12, 11, 13, 5, 6, 7};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    heapSort(vetor, tamanho);

    printf("Vetor ordenado com Heap Sort:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
