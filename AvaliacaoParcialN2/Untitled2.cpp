#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float nota;
} Aluno;

void exibirAluno(Aluno aluno) {
    printf("ID: %d\nNome: %s\nNota: %.2f\n\n", aluno.id, aluno.nome, aluno.nota);
}

void adicionarAluno(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "ab"); // Abre para adicionar em binário
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    Aluno aluno;
    printf("ID: ");
    scanf("%d", &aluno.id);
    printf("Nome: ");
    scanf(" %[^\n]", aluno.nome); // Lê até a nova linha
    printf("Nota: ");
    scanf("%f", &aluno.nota);
    fwrite(&aluno, sizeof(Aluno), 1, arquivo);
    fclose(arquivo);
    printf("Aluno adicionado com sucesso!\n");
}

void listarAlunos(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb"); // Abre para leitura binária
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    Aluno aluno;
    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        exibirAluno(aluno);
    }
    fclose(arquivo);
}

void atualizarNota(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb+"); // Abre para leitura e escrita em binário
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para atualização!\n");
        return;
    }

    int id;
    printf("Digite o ID do aluno cuja nota deseja atualizar: ");
    scanf("%d", &id);

    Aluno aluno;
    int encontrado = 0;

    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        if (aluno.id == id) {
            encontrado = 1;
            printf("Aluno encontrado:\n");
            exibirAluno(aluno);

            printf("Digite a nova nota: ");
            scanf("%f", &aluno.nota);

            // Volta o ponteiro para regravar os dados do aluno
            fseek(arquivo, -sizeof(Aluno), SEEK_CUR);
            fwrite(&aluno, sizeof(Aluno), 1, arquivo);
            printf("Nota atualizada com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno com ID %d não encontrado!\n", id);
    }

    fclose(arquivo);
}

int main() {
    int opcao;
    const char *nomeArquivo = "alunos.bin";

    do {
        printf("1. Adicionar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Atualizar Nota\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAluno(nomeArquivo);
                break;
            case 2:
                listarAlunos(nomeArquivo);
                break;
            case 3:
                atualizarNota(nomeArquivo);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
