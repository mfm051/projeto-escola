#include "data.h"

#define MAXNOME 100
#define MAXCPF 11
#define MAXDISCPILINA 100

typedef struct {
  int ativo;
  int matriculaProfessor;
  char disciplina[MAXDISCPILINA];
  char nome[MAXNOME];
  char sexo;
  Data data_nascimento;
  char cpf[MAXCPF];
} Professor;

int cadastrarProfessor(int qtdProfessores, Professor professores[], int maxProfessores);
void listarProfessores(int qtdProfessores, Professor professores[]);
int atualizarProfessor(int qtdProfessores, Professor professores[]);
int excluirProfessor(int qtdProfessores, Professor professores[]);
int obtemOpcaoProfessor();
int encontrarMatricula(int qtdProfessores, Professor professores[], int matriculaProfessor);
int encontrarDisciplina(int qtdProfessores, Professor professores[], char disciplina);