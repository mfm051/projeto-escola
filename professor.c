#include "professor.h"
#include "interface.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
    strcpy(professores[qtdProfessores].nome, obtemNome());
    professores[qtdProfessores].sexo = obtemSexo();
    atualizaData(&professores[qtdProfessores].data_nascimento);
    strcpy(professores[qtdProfessores].cpf, obtemCPF());
    professores[qtdProfessores].ativo = true;

    return true;
}

void listarProfessores(int qtdProfessores, Professor professores[]) {
    if (qtdProfessores == 0) {
        printf("Não há professores cadastrados!\n");
    } else {
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
}

int atualizarProfessor(int qtdProfessores, Professor professores[]) {
    int matricula = obtemMatricula();

    int posicaoProfessor = encontraMatriculaProfessor(qtdProfessores, professores, matricula);

    if (posicaoProfessor == -1) {
        printf("Matrícula não encontrada!\n");
        return false;
    }

    strcpy(professores[posicaoProfessor].nome, obtemNome());
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

int encontraMatriculaProfessor(int qtdProfessores, Professor professores[], int matricula) {
    int posicaoProfessor = -1;

    for (int i = 0; i < qtdProfessores; i++) {
        if (professores[i].matricula == matricula && professores[i].ativo)
            posicaoProfessor = i;
    }

    return posicaoProfessor;
}

int buscarProfessorPorMatricula(int matricula, Professor professores[], int qtdProfessores) {
    for (int i = 0; i < qtdProfessores; i++) {
        if (professores[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

