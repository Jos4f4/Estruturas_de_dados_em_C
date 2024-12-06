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

void excluirAluno(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb"); // Abre o arquivo original para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    FILE *arquivoTemp = fopen("temp.bin", "wb"); // Arquivo temporário para escrita
    if (arquivoTemp == NULL) {
        printf("Erro ao criar o arquivo temporário!\n");
        fclose(arquivo);
        return;
    }

    int id;
    printf("Digite o ID do aluno que deseja excluir: ");
    scanf("%d", &id);

    Aluno aluno;
    int encontrado = 0;

    while (fread(&aluno, sizeof(Aluno), 1, arquivo) == 1) {
        if (aluno.id == id) {
            encontrado = 1; // Marca que o aluno foi encontrado
        } else {
            fwrite(&aluno, sizeof(Aluno), 1, arquivoTemp); // Escreve no arquivo temporário os alunos restantes
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    if (encontrado) {
        remove(nomeArquivo);                 // Remove o arquivo original
        rename("temp.bin", nomeArquivo);    // Renomeia o arquivo temporário como o original
        printf("Aluno com ID %d excluído com sucesso!\n", id);
    } else {
        remove("temp.bin"); // Exclui o arquivo temporário se o aluno não foi encontrado
        printf("Aluno com ID %d não encontrado!\n", id);
    }
}

int main() {
    int opcao;
    const char *nomeArquivo = "alunos.bin";

    do {
        printf("1. Adicionar Aluno\n");
        printf("2. Listar Alunos\n");
        printf("3. Excluir Aluno\n");
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
                excluirAluno(nomeArquivo);
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
