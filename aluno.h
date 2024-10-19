#include "data.h"

#define MAXNOME 15

typedef struct
{
    int ativo;
    int matricula;
    char nome[MAXNOME];
    char sexo; // M: masculino, F: feminino
    Data data_nascimento;
    int cpf[11];
} Aluno;

int cadastrarAluno(int qtdAlunos, Aluno alunos[], int maxAlunos);
void listarAlunos(int qtdAlunos, Aluno alunos[]);
int atualizarAluno(int qtdAlunos, Aluno alunos[]);
int excluirAluno(int qtdAlunos, Aluno alunos[]);
int obtemOpcaoAluno();