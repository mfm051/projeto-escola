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

//Funções para manipular as informações dos professores
int cadastrarProfessor (int qtdProfessores, Professor professores[], int maxProfessores);
void listarProfessores (int qtdProfessores, Professor professores[]);
void listarProfessoresPorSexo (char sexo, int qtdProfessores, Professor professores[]);
void listarProfessoresAlfabeticamente(int qtdProfessores, Professor professores[]);
void listarProfessoresPorNascimento(int qtdProfessores, Professor professores[]);
void listarProfessoresAniversariantes(int mes, int qtdProfessores, Professor professores[]);
void listarProfessoresPorBuscaNome(char busca[], int qtdProfessores, Professor professores[]);
int atualizarProfessor (int qtdProfessores, Professor professores[]);
int excluirProfessor (int qtdProfessores, Professor professores[]);

//Funções auxiliares de busca
int encontraMatriculaProfessor (int qtdProfessores, Professor professores[], int matricula);

#endif