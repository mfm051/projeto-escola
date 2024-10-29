#include "aluno.h"
#include "professor.h"
#include "data.h"

#include <stdio.h>

#ifndef ESCOLA_H
#define ESCOLA_H

void listarAniversariantes(int mes, int qtdAlunos, Aluno alunos[], int qtdProfessores, Professor professores[]) {
    int qtdAniversariantes = 0;

    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].ativo && checarAniversariante(alunos[i].data_nascimento, mes)) {
            qtdAniversariantes++;
            printf("%s (aluno)\n", alunos[i].nome);
        }
    }

    for (int i = 0; i < qtdProfessores; i++) {
        if (professores[i].ativo && checarAniversariante(professores[i].data_nascimento, mes)) {
            qtdAniversariantes++;
            printf("%s (professor)\n", professores[i].nome);
        }
    }

    if (qtdAniversariantes == 0)
        printf("Sem aniversariantes no mês\n");
}

#endif