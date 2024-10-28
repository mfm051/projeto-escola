#include "data.h"
#include "semestre.h"
#include "constantes.h"

#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct 
{
    int ativo;
    int matricula;
    char nome[MAXNOMEPESSOA];
    char sexo;
    Data data_nascimento;
    char cpf[MAXCPF];
} Professor;

int cadastrarProfessor (int qtdProfessores, Professor professores[], int maxProfessores);
void listarProfessores (int qtdProfessores, Professor professores[]);
int atualizarProfessor (int qtdProfessores, Professor professores[]);
int excluirProfessor (int qtdProfessores, Professor professores[]);
int obtemOpcaoProfessor ();
int encontraMatriculaProfessor (int qtdProfessores, Professor professores[], int matricula);

#endif