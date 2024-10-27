#include "aluno.h"
#include "validacoes.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int cadastrarAluno(int qtdAlunos, Aluno alunos[], int maxAlunos) {
    int matricula;
    char nome[MAXNOME];
    char sexo;
    int dia, mes, ano;
    char cpf[MAXCPF + 5];

    if (qtdAlunos == maxAlunos) {
        printf("Máximo de alunos atingido!\n");
        return false;
    }

    printf("Matrícula do aluno: ");
    scanf("%d", &matricula);

    if (validaMatricula(matricula) == false)
        return false;

    if (encontraMatricula(qtdAlunos, alunos, matricula) != -1) {
        printf("Matrícula já cadastrada!\n");
        return false;
    }

    alunos[qtdAlunos].matricula = matricula;

    printf("Nome do aluno: ");
    fgetc(stdin);
    fgets(alunos[qtdAlunos].nome, MAXNOME, stdin);
    alunos[qtdAlunos].nome[strlen(alunos[qtdAlunos].nome) - 1] = 0;

    do {
        printf("Sexo do aluno: ");
        scanf("%c", &sexo);
    } while (validaSexo(sexo) == false);

    alunos[qtdAlunos].sexo = sexo;


    do {
        printf("Data de nascimento (dia/mês/ano): ");
        scanf("%d/%d/%d", &dia, &mes, &ano);
    } while (validaData(dia, mes, ano) == false);

    alunos[qtdAlunos].data_nascimento.dia = dia;
    alunos[qtdAlunos].data_nascimento.mes = mes;
    alunos[qtdAlunos].data_nascimento.ano = ano;

    do {
        printf("CPF: ");
        scanf("%s", &cpf);
        cpf[MAXCPF] = 0;
    } while (validaCPF(cpf) == false);
    strcpy(alunos[qtdAlunos].cpf, cpf);

    alunos[qtdAlunos].ativo = true;

    return true;
}

void listarAlunos(int qtdAlunos, Aluno alunos[]) {
    if (qtdAlunos == 0)
        printf("Não há alunos cadastrados!\n");
    else {
        for (int i = 0; i < qtdAlunos; i++) {
            if (alunos[i].ativo) {
                printf("Matrícula: %d\n", alunos[i].matricula);
                printf("Nome: %s\n", alunos[i].nome);
                printf("Sexo: %c\n", alunos[i].sexo);
                printf("Data de nascimento: %d/%d/%d\n", alunos[i].data_nascimento.dia, alunos[i].data_nascimento.mes, alunos[i].data_nascimento.ano);
                printf("CPF: %s\n", alunos[i].cpf);
                printf("\n");
            }
        }
    }
}

int atualizarAluno(int qtdAlunos, Aluno alunos[]) {
    int matricula;
    int posicaoAluno;

    printf("Matrícula do aluno: ");
    scanf("%d", &matricula);

    if (validaMatricula(matricula) == false)
        return false;

    posicaoAluno = encontraMatricula(qtdAlunos, alunos, matricula);

    if (posicaoAluno == -1) {
        printf("Matrícula não encontrada!\n");
        return false;
    }
    else {
        printf("Novo nome: ");
        fgetc(stdin);
        fgets(alunos[posicaoAluno].nome, MAXNOME, stdin);
        alunos[posicaoAluno].nome[strlen(alunos[posicaoAluno].nome) - 1] = 0;

        char sexo;
        do {
            printf("Sexo do aluno: ");
            scanf("%c", &sexo);
        } while (validaSexo(sexo) == false);
        
        alunos[posicaoAluno].sexo = sexo;

        int dia, mes, ano;
        do {
            printf("Data de nascimento (dia/mês/ano): ");
            scanf("%d/%d/%d", &dia, &mes, &ano);
        } while (validaData(dia, mes, ano) == false);

        alunos[posicaoAluno].data_nascimento.dia = dia;
        alunos[posicaoAluno].data_nascimento.mes = mes;
        alunos[posicaoAluno].data_nascimento.ano = ano;

        char cpf[MAXCPF + 5];
        do {
            printf("CPF: ");
            scanf("%s", &cpf);
            cpf[MAXCPF] = 0;
        } while (validaCPF(cpf) == false);

        strcpy(alunos[posicaoAluno].cpf, cpf);

        return true;
    }
}

int excluirAluno(int qtdAlunos, Aluno alunos[]) {
    int matricula;
    int posicaoAluno;

    printf("Matrícula do aluno: ");
    scanf("%d", &matricula);

    if (validaMatricula(matricula) == false)
        return false;

    posicaoAluno = encontraMatricula(qtdAlunos, alunos, matricula);

    if (posicaoAluno == -1) {
        printf("Matrícula não encontrada!\n");
        return false;
    }
    else
    {
        alunos[posicaoAluno].ativo = false;

        for (int i = posicaoAluno; i < qtdAlunos; i++) {
            alunos[i] = alunos[i + 1];
        };

        return true;
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