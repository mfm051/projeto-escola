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
int cadastrarDisciplina (int qtdDisciplinas, Disciplina disciplinas[], int maxDisciplinas);
void listarDisciplinas(int qtdDisciplinas, Disciplina disciplinas[]);
int excluirDisciplina (int qtdDisciplinas, Disciplina disciplinas[]);
int atualizarDisciplina(int qtdDisciplinas, Disciplina disciplinas[]);
int obtemOpcaoDisciplina ();

// Funções auxiliares de busca
int encontraCodigoDisciplina(int codigo, int qtdDisciplinas, Disciplina disciplinas[]);

// Funções para cadastro de Alunos/Professores nas disciplinas

#endif