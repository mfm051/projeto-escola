#include "professor.h"
#include "data.h"
#include "interface.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

//Funções para manipular as informações dos professores
int cadastrarProfessor (int qtdProfessores, Professor professores[], int maxProfessores) {
    if (qtdProfessores == maxProfessores) {
        printf("Máximo de professores atingido!\n");
        return false;
    }

    int matricula = obtemMatricula();

    if (encontraMatriculaProfessor(qtdProfessores, professores, matricula) != -1) {
        printf("Matrícula já cadastrada!\n");
        return false;
    }

    professores[qtdProfessores].matricula = matricula;
    strcpy(professores[qtdProfessores].nome, obtemNome(MAXNOMEPESSOA));
    professores[qtdProfessores].sexo = obtemSexo();
    atualizaData(&professores[qtdProfessores].data_nascimento);
    strcpy(professores[qtdProfessores].cpf, obtemCPF());
    professores[qtdProfessores].ativo = true;

    return true;
}

void listarProfessores(int qtdProfessores, Professor professores[]) {
    for (int i = 0; i < qtdProfessores; i++) {
        if (professores[i].ativo) {
            printf("Matrícula: %d\n", professores[i].matricula);
            printf("Nome: %s\n", professores[i].nome);
            printf("Sexo: %c\n", professores[i].sexo);
            printf("Data de nascimento: %d/%d/%d\n", professores[i].data_nascimento.dia, professores[i].data_nascimento.mes, professores[i].data_nascimento.ano);
            printf("CPF: %s\n", professores[i].cpf);
            printf("\n");
        }
    }
}

void listarProfessoresPorSexo (char sexo, int qtdProfessores, Professor professores[]) {
    for (int i = 0; i < qtdProfessores; i++) {
        if (professores[i].ativo && professores[i].sexo == sexo) {
            printf("Matrícula: %d\n", professores[i].matricula);
            printf("Nome: %s\n", professores[i].nome);
            printf("Sexo: %c\n", professores[i].sexo);
            printf("Data de nascimento: %d/%d/%d\n", professores[i].data_nascimento.dia, professores[i].data_nascimento.mes, professores[i].data_nascimento.ano);
            printf("CPF: %s\n", professores[i].cpf);
            printf("\n");
        }
    }
}

void listarProfessoresAlfabeticamente(int qtdProfessores, Professor professores[]) {
    Professor copiaProfessores[qtdProfessores];
    for (int i = 0; i < qtdProfessores; i++)
        copiaProfessores[i] = professores[i];

    Professor temp;
    for (int i = 0; i < qtdProfessores; i++) {
        for (int j = 0; j < qtdProfessores - 1 - i; j++) {

            if (strcmp(copiaProfessores[j].nome, copiaProfessores[j + 1].nome) > 0) {
                temp = copiaProfessores[j];
                copiaProfessores[j] = copiaProfessores[j + 1];
                copiaProfessores[j + 1] = temp;
            }
        }
    }

    listarProfessores(qtdProfessores, copiaProfessores);
}

void listarProfessoresPorNascimento(int qtdProfessores, Professor professores[]) {
    Professor copiaProfessores[qtdProfessores];
    for (int i = 0; i < qtdProfessores; i++)
        copiaProfessores[i] = professores[i];

    Professor temp;
    for (int i = 0; i < qtdProfessores; i++) {
        for (int j = 0; j < qtdProfessores - 1 - i; j++) {

            if (comparaData(copiaProfessores[j].data_nascimento, copiaProfessores[j + 1].data_nascimento) > 0) {
                temp = copiaProfessores[j];
                copiaProfessores[j] = copiaProfessores[j + 1];
                copiaProfessores[j + 1] = temp;
            }
        }
    }

    listarProfessores(qtdProfessores, copiaProfessores);
}

void listarProfessoresPorBuscaNome(char busca[], int qtdProfessores, Professor professores[]) {
    for (int i = 0; i < qtdProfessores; i++) {
        if (professores[i].ativo && strstr(professores[i].nome, busca) != NULL) {
            printf("Matrícula: %d\n", professores[i].matricula);
            printf("Nome: %s\n", professores[i].nome);
            printf("Sexo: %c\n", professores[i].sexo);
            printf("Data de nascimento: %d/%d/%d\n", professores[i].data_nascimento.dia, professores[i].data_nascimento.mes, professores[i].data_nascimento.ano);
            printf("CPF: %s\n", professores[i].cpf);
            printf("\n");
        }
    }
}

int atualizarProfessor(int qtdProfessores, Professor professores[]) {
    int matricula = obtemMatricula();

    int posicaoProfessor = encontraMatriculaProfessor(qtdProfessores, professores, matricula);

    if (posicaoProfessor == -1) {
        printf("Matrícula não encontrada!\n");
        return false;
    }

    strcpy(professores[posicaoProfessor].nome, obtemNome(MAXNOMEPESSOA));
    professores[posicaoProfessor].sexo = obtemSexo();
    atualizaData(&professores[posicaoProfessor].data_nascimento);
    strcpy(professores[posicaoProfessor].cpf, obtemCPF());

    return true;
}

int excluirProfessor(int qtdProfessores, Professor professores[]) {
    int matricula = obtemMatricula();
    int posicaoProfessor = encontraMatriculaProfessor(qtdProfessores, professores, matricula);

    if (posicaoProfessor == -1) {
        printf("Matrícula não encontrada!\n");
        return false;
    }

    professores[posicaoProfessor].ativo = false;

    for (int i = posicaoProfessor; i < qtdProfessores; i++)
        professores[i] = professores[i + 1];

    return true;
}

//Funções auxiliares de busca
int encontraMatriculaProfessor(int qtdProfessores, Professor professores[], int matricula) {
    int posicaoProfessor = -1;

    for (int i = 0; i < qtdProfessores; i++) {
        if (professores[i].matricula == matricula && professores[i].ativo) {
            posicaoProfessor = i;
            break;
        }
    }

    return posicaoProfessor;
}
