#include "data.h"
#include "constantes.h"

#ifndef ALUNO_H
#define ALUNO_H

typedef struct
{
    int ativo;
    int matricula;
    char nome[MAXNOMEPESSOA];
    char sexo; // M: masculino, F: feminino
    Data data_nascimento;
    char cpf[MAXCPF];
} Aluno;

//Funções para manipular as informações dos alunos
int cadastrarAluno (int qtdAlunos, Aluno alunos[], int maxAlunos);
void listarAlunos (int qtdAlunos, Aluno alunos[]);
void listarAlunosPorSexo (char sexo, int qtdAlunos, Aluno alunos[]);
int atualizarAluno (int qtdAlunos, Aluno alunos[]);
int excluirAluno (int qtdAlunos, Aluno alunos[]);

//Funções auxiliares de busca
int encontraMatriculaAluno (int qtdAlunos, Aluno alunos[], int matricula);

#endif