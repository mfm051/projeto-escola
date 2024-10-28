#include "constantes.h"

#include "professor.h"
#include "aluno.h"

#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct 
{
    int ativo;
    char nome[MAXNOMEDISCIPLINA];
    int codigo;
    Semestre semestreAtual;
    Professor professorResponsavel;
    Aluno alunosMatriculados[MAXALUNOS];
    int qtdAlunosMatriculados;
} Disciplina;

// Funções para manipulação de disciplinas
int obtemOpcaoDisciplina ();
int cadastrarDisciplina (int qtdDisciplinas, Disciplina disciplinas[], int maxDisciplinas, Professor professores[], int qtdProfessores);
void listarDisciplinas(int qtdDisciplinas, Disciplina disciplinas[]);
int excluirDisciplina (int qtdDisciplinas, Disciplina disciplinas[]);
int atualizarDisciplina(int qtdDisciplinas, Disciplina disciplinas[], int qtdProfessores, Professor professores []);

// Funções auxiliares de busca
int encontraCodigoDisciplina(int codigo, int qtdDisciplinas, Disciplina disciplinas[]);

// Funções para pessoas matriculadas
int obtemOpcaoMatriculados ();
int obtemOpcaoListarMatriculados ();
int cadastrarProfessorDisciplina (Disciplina disciplinas[], Professor professores[], int ativo);
int matricularAlunoDisciplina (Disciplina disciplinas [], int qtdDisciplinas, Aluno alunos[], int qtdAlunos, int qtdAlunosMatriculados);
int excluirAlunoDisciplina (Disciplina disciplinas [], int qtdDisciplinas, Aluno alunos[], int qtdAlunos, int qtdAlunosMatriculados);
void listarPessoasMatriculadas (int qtdAlunos, Aluno alunos[], int qtdProfessores, Professor professores[], int qtdDisciplinas, Disciplina disciplinas[], Professor professorResponsavel, Aluno alunosMatriculados[MAXALUNOS], int qtdAlunosMatriculados);

#endif
