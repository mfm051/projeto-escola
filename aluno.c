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

    if (matricula < 0) {
        printf("Matrícula inválida");
        return FALSO;
    }

    if (encontraMatricula(qtdAlunos, alunos, matricula) != -1) {
        printf("Matrícula já cadastrada\n");
        return FALSO;
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
    int posicaoAluno;

    printf("Matrícula do aluno: ");
    scanf("%d", &matricula);

    if (matricula <= 0) {
        printf("Matrícula inválida\n");
        return FALSO;
    }

    posicaoAluno = encontraMatricula(qtdAlunos, alunos, matricula);

    if (posicaoAluno == -1) {
        printf("Matrícula não encontrada");
        return FALSO;
    }
    else {
        printf("Novo nome: ");
        fgetc(stdin);
        fgets(alunos[posicaoAluno].nome, MAXNOME, stdin);
        alunos[posicaoAluno].nome[strlen(alunos[posicaoAluno].nome) - 1] = 0;

        printf("Novo sexo: ");
        scanf("%c", &alunos[posicaoAluno].sexo);

        printf("Nova data de nascimento (dia/mês/ano): ");
        scanf("%d/%d/%d", &alunos[posicaoAluno].data_nascimento.dia, &alunos[posicaoAluno].data_nascimento.mes, &alunos[posicaoAluno].data_nascimento.ano);

        printf("Novo CPF: ");
        fgetc(stdin);
        fgets(alunos[posicaoAluno].cpf, MAXCPF, stdin);
        alunos[posicaoAluno].cpf[strlen(alunos[posicaoAluno].cpf) - 1] = 0;

        return VERDADEIRO;
    }
}

int excluirAluno(int qtdAlunos, Aluno alunos[]) {
    int matricula;
    int posicaoAluno;

    printf("Matrícula do aluno: ");
    scanf("%d", &matricula);

    if (matricula <= 0) {
        printf("Matrícula inválida\n");
        return FALSO;
    }

    posicaoAluno = encontraMatricula(qtdAlunos, alunos, matricula);

    if (posicaoAluno == -1) {
        printf("Matrícula não encontrada\n");
        return FALSO;
    }
    else
    {
        alunos[posicaoAluno].ativo = FALSO;

        for (int i = posicaoAluno; i < qtdAlunos; i++) {
            alunos[i] = alunos[i + 1];
        };

        return VERDADEIRO;
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

int encontraMatricula(int qtdAlunos, Aluno alunos[], int matricula) {
    int posicaoAluno = -1;

    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].matricula == matricula && alunos[i].ativo)
            posicaoAluno = i;
    }

    return posicaoAluno;
}