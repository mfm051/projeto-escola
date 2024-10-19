#include "aluno.h"
#include <stdio.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0

int cadastrarAluno(int qtdAlunos, Aluno alunos[], int maxAlunos) {
    int matricula;
    char nome[MAXNOME];
    char sexo;
    int dia, mes, ano;
    char cpf[MAXCPF];

    if (qtdAlunos == maxAlunos) {
        printf("Máximo de alunos atingido\n");
        return FALSO;
    }

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

    printf("Nome do aluno: ");
    fgetc(stdin);
    fgets(alunos[qtdAlunos].nome, MAXNOME, stdin);
    alunos[qtdAlunos].nome[strlen(alunos[qtdAlunos].nome) - 1] = 0;

    printf("Sexo do aluno: ");
    scanf("%c", &alunos[qtdAlunos].sexo);

    printf("Data de nascimento (dia/mês/ano): ");
    scanf("%d/%d/%d", &alunos[qtdAlunos].data_nascimento.dia, &alunos[qtdAlunos].data_nascimento.mes, &alunos[qtdAlunos].data_nascimento.ano);

    printf("CPF: ");
    fgetc(stdin);
    fgets(alunos[qtdAlunos].cpf, MAXCPF, stdin);
    alunos[qtdAlunos].cpf[strlen(alunos[qtdAlunos].cpf) - 1] = 0;

    alunos[qtdAlunos].ativo = VERDADEIRO;

    return VERDADEIRO;
}

void listarAlunos(int qtdAlunos, Aluno alunos[]) {
    if (qtdAlunos == 0) {
        printf("Não há alunos cadastrados\n");
    } else {
        for (int i = 0; i < qtdAlunos; i++) {
            if (alunos[i].ativo) {
                printf("Matrícula: %d\n", alunos[i].matricula);
                printf("Nome: %s\n", alunos[i].nome);
                printf("Sexo: %c\n", alunos[i].sexo);
                printf("Data de nascimento: %d/%d/%d\n", alunos[i].data_nascimento.dia, alunos[i].data_nascimento.mes, alunos[i].data_nascimento.ano);
                printf("CPF: %s\n", alunos[i].cpf);
            }
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