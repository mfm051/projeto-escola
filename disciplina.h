#include "semestre.h"
#include "professor.h"

#define MAXNOME 100

#ifndef DISCIPLINA_H
#define DISCIPLINA_H

typedef struct 
{
    int ativo;
    char nomeDisciplina[MAXNOME];
    int codigo;
    Semestre periodo;
    Professor dadosProfessor;
} Disciplina;

int cadastrarDisciplina(int qtdDisciplinas, Disciplina disciplinas[], int maxDisciplinas);
void listarDisciplinas(int qtdDisciplinas, Disciplina disciplinas[]);
int excluirDisciplina(int qtdDisciplinas, Disciplina disciplinas[]);
int atualizarDisciplina(int qtdDisciplinas, Disciplina disciplinas[]);
int obtemOpcaoDisciplina();
int encontraDisciplinaProfessor(int qtdDisciplinas, Disciplina disciplinas[], char nomeDisciplina[]);
int encontraCodigoDisciplina(int qtdDisciplinas, Disciplina disciplinas[], int codigo);

#endif