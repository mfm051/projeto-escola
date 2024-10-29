#include "aluno.h"
#include "data.h"
#include "interface.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Funções para manipular as informações dos alunos
int cadastrarAluno(int qtdAlunos, Aluno alunos[], int maxAlunos) {
    if (qtdAlunos == maxAlunos) {
        printf("Máximo de alunos atingido!\n");
        return false;
    }

    int matricula = obtemMatricula();

    if (encontraMatriculaAluno(qtdAlunos, alunos, matricula) != -1) {
        printf("Matrícula já cadastrada!\n");
        return false;
    }

    alunos[qtdAlunos].matricula = matricula;
    strcpy(alunos[qtdAlunos].nome, obtemNome(MAXNOMEPESSOA));
    alunos[qtdAlunos].sexo = obtemSexo();
    atualizaData(&alunos[qtdAlunos].data_nascimento);
    strcpy(alunos[qtdAlunos].cpf, obtemCPF());
    alunos[qtdAlunos].ativo = true;

    return true;
}

void listarAlunos(int qtdAlunos, Aluno alunos[]) {
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

void listarAlunosPorSexo(char sexo, int qtdAlunos, Aluno alunos[]) {
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].ativo && alunos[i].sexo == sexo) {
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("Data de nascimento: %d/%d/%d\n", alunos[i].data_nascimento.dia, alunos[i].data_nascimento.mes, alunos[i].data_nascimento.ano);
            printf("CPF: %s\n", alunos[i].cpf);
            printf("\n");
        }
    }
}

void listarAlunosPorBuscaNome(char busca[], int qtdAlunos, Aluno alunos[]) {
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].ativo && strstr(alunos[i].nome, busca) != NULL) {
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("Data de nascimento: %d/%d/%d\n", alunos[i].data_nascimento.dia, alunos[i].data_nascimento.mes, alunos[i].data_nascimento.ano);
            printf("CPF: %s\n", alunos[i].cpf);
            printf("\n");
        }
    }
}

void listarAlunosAlfabeticamente(int qtdAlunos, Aluno alunos[]) {
    Aluno copiaAlunos[qtdAlunos];
    for (int i = 0; i < qtdAlunos; i++)
        copiaAlunos[i] = alunos[i];

    Aluno temp;
    for (int i = 0; i < qtdAlunos; i++) {
        for (int j = 0; j < qtdAlunos - 1 - i; j++) {

            if (strcmp(copiaAlunos[j].nome, copiaAlunos[j + 1].nome) > 0) {
                temp = copiaAlunos[j];
                copiaAlunos[j] = copiaAlunos[j + 1];
                copiaAlunos[j + 1] = temp;
            }
        }
    }

    listarAlunos(qtdAlunos, copiaAlunos);
}

void listarAlunosPorNascimento(int qtdAlunos, Aluno alunos[]) {
    Aluno copiaAlunos[qtdAlunos];
    for (int i = 0; i < qtdAlunos; i++)
        copiaAlunos[i] = alunos[i];

    Aluno temp;
    for (int i = 0; i < qtdAlunos; i++) {
        for (int j = 0; j < qtdAlunos - 1 - i; j++) {

            if (comparaData(copiaAlunos[j].data_nascimento, copiaAlunos[j + 1].data_nascimento) > 0) {
                temp = copiaAlunos[j];
                copiaAlunos[j] = copiaAlunos[j + 1];
                copiaAlunos[j + 1] = temp;
            }
        }
    }

    listarAlunos(qtdAlunos, copiaAlunos);
}

void listarAlunosAniversariantes(int mes, int qtdAlunos, Aluno alunos[]) {
    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].ativo && checarAniversariante(alunos[i].data_nascimento, mes)) {
            printf("Matrícula: %d\n", alunos[i].matricula);
            printf("Nome: %s\n", alunos[i].nome);
            printf("Sexo: %c\n", alunos[i].sexo);
            printf("Data de nascimento: %d/%d/%d\n", alunos[i].data_nascimento.dia, alunos[i].data_nascimento.mes, alunos[i].data_nascimento.ano);
            printf("CPF: %s\n", alunos[i].cpf);
            printf("\n");
        }
    }
}

int atualizarAluno(int qtdAlunos, Aluno alunos[]) {
    int matricula = obtemMatricula();

    int posicaoAluno = encontraMatriculaAluno(qtdAlunos, alunos, matricula);
    if (posicaoAluno == -1) {
        printf("Matrícula não encontrada!\n");
        return false;
    }

    strcpy(alunos[posicaoAluno].nome, obtemNome(MAXNOMEPESSOA));
    alunos[posicaoAluno].sexo = obtemSexo();
    atualizaData(&alunos[posicaoAluno].data_nascimento);
    strcpy(alunos[posicaoAluno].cpf, obtemCPF());

    return true;
}

int excluirAluno(int qtdAlunos, Aluno alunos[]) {
    int matricula = obtemMatricula();
    int posicaoAluno = encontraMatriculaAluno(qtdAlunos, alunos, matricula);

    if (posicaoAluno == -1) {
        printf("Matrícula não encontrada!\n");
        return false;
    }

    alunos[posicaoAluno].ativo = false;

    for (int i = posicaoAluno; i < qtdAlunos; i++)
        alunos[i] = alunos[i + 1];

    return true;
}

//Funções auxiliares de busca
int encontraMatriculaAluno(int qtdAlunos, Aluno alunos[], int matricula) {
    int posicaoAluno = -1;

    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].matricula == matricula && alunos[i].ativo) {
            posicaoAluno = i;
            break;
        }
    }

    return posicaoAluno;
}