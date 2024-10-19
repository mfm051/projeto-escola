#include "aluno.h"
#include <stdio.h>

#define VERDADEIRO 1
#define FALSO 0

int cadastrarAluno(int qtdAlunos, Aluno alunos[], int maxAlunos) {
    if (qtdAlunos == maxAlunos) {
        printf("Máximo de alunos atingido\n");
        return FALSO;
    }

    int matricula;
    printf("Matrícula do aluno: ");
    scanf("%d", &matricula);

    if (matricula <= 0) {
        printf("Matrícula inválida\n");
        return FALSO;
    }

    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].matricula == matricula && alunos[i].ativo) {
            printf("Aluno já cadastrado no sistema\n");
            return FALSO;
        }
    }

    alunos[qtdAlunos].matricula = matricula;
    alunos[qtdAlunos].ativo = VERDADEIRO;

    return VERDADEIRO;
}

void listarAlunos(int qtdAlunos, Aluno alunos[]) {
    if (qtdAlunos == 0) {
        printf("Não há alunos cadastrados\n");
    } else {
        for (int i = 0; i < qtdAlunos; i++) {
            if (alunos[i].ativo)
                printf("Matrícula: %d\n", alunos[i].matricula);
        }
    }
}

int atualizarAluno(int qtdAlunos, Aluno alunos[]) {
    int matricula;
    int matricula_encontrada = FALSO;

    printf("Matrícula do aluno: ");
    scanf("%d", &matricula);

    if (matricula <= 0) {
        printf("Matrícula inválida\n");
        return FALSO;
    }
    else
    {
        for (int i = 0; i < qtdAlunos; i++) {
            if (alunos[i].matricula == matricula && alunos[i].ativo) {
                int nova_matricula;
                printf("Nova matrícula: ");
                scanf("%d", &nova_matricula);

                if (nova_matricula <= 0) {
                    printf("Matrícula inválida\n");
                    return FALSO;
                }
                else
                {
                    alunos[i].matricula = nova_matricula;
                    return VERDADEIRO;
                }
            }
        }

        printf("Matrícula não encontrada\n");
        return FALSO;
    }
}

int excluirAluno(int qtdAlunos, Aluno alunos[]) {
    int matricula;
    int matricula_encontrada = FALSO;

    printf("Matrícula do aluno: ");
    scanf("%d", &matricula);

    if (matricula <= 0) {
        printf("Matrícula inválida\n");
        return FALSO;
    }
    else
    {
        for (int i = 0; i < qtdAlunos; i++) {
            if (alunos[i].matricula == matricula) {
                matricula_encontrada = VERDADEIRO;
                alunos[i].ativo = FALSO;

                for (int j = i; j < qtdAlunos; j++) {
                    alunos[j] = alunos[j + 1];
                };

                return VERDADEIRO;
            }
        }

        printf("Matrícula não encontrada\n");
        return FALSO;
    }
}

int obtemOpcaoAluno() {
    int opcao;

    printf("\nOpções Aluno:\n");
    printf("0: voltar\n");
    printf("1: cadastrar aluno\n");
    printf("2: listar alunos\n");
    printf("3: atualizar aluno\n");
    printf("4: excluir aluno\n");

    scanf("%d", &opcao);
    return opcao;
}