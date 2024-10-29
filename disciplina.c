#include "disciplina.h"
#include "interface.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Funções para manipulção de informações na disciplina
int obtemOpcaoDisciplina (){
    int opcao;

    printf("\nOpções Disciplina:\n");
    printf("0: voltar\n");
    printf("1: cadastrar disciplina\n");
    printf("2: listar disciplinas\n");
    printf("3: atualizar disciplina\n");
    printf("4: excluir disciplina\n");
    printf("5: matrículas\n");

    scanf("%d", &opcao);

    return opcao;
}

int cadastrarDisciplina(int qtdDisciplinas, Disciplina disciplinas[], int maxDisciplinas, Professor professores[], int qtdProfessores) {

    if (qtdDisciplinas == maxDisciplinas) {
        printf("Máximo de disciplinas atingido!\n");
        return false;
    }

    int codigo = obtemCodigo();

    if (encontraCodigoDisciplina(codigo, qtdDisciplinas, disciplinas) != -1) {
        printf("Código já cadastrado!\n");
        return false;
    }

    disciplinas[qtdDisciplinas].codigo = codigo;
    strcpy(disciplinas[qtdDisciplinas].nome, obtemNome(MAXNOMEDISCIPLINA));
    disciplinas[qtdDisciplinas].semestreAtual = obtemSemestre();

    // Cadastro do professor responsável pela disciplina
    printf("\nProfessor responsável:\n");
    int matricula = obtemMatricula();
    int posicaoProfessor = encontraMatriculaProfessor (qtdProfessores, professores, matricula);

    if (posicaoProfessor == -1) {
        printf("Professor não encontrado!\n");
        return false;
    }

    // Associando o professor encontrado
    disciplinas[qtdDisciplinas].professorResponsavel = professores[posicaoProfessor];

    disciplinas[qtdDisciplinas].qtdAlunosMatriculados = 0;
    disciplinas[qtdDisciplinas].ativo = true;

    return true;
}

void listarDisciplinas (int qtdDisciplinas, Disciplina disciplinas[]) {
    if (qtdDisciplinas == 0)
        printf("\nNão há disciplinas cadastrados!\n");
    else {
        for (int i = 0; i < qtdDisciplinas; i++) {
            if (disciplinas[i].ativo) {
                printf("\nCódigo da disciplina: %d\n", disciplinas[i].codigo);
                printf("Nome: %s\n", disciplinas[i].nome);
                printf("Semestre atual: %d.%d\n", disciplinas[i].semestreAtual.ano, disciplinas[i].semestreAtual.periodo);
                printf("Professor responsável: %s\n", disciplinas[i].professorResponsavel.nome);
                printf("\n");
            }
        }
    }
}

int excluirDisciplina(int qtdDisciplinas, Disciplina disciplinas[]) {
    int codigo;
    int posicaoDisciplina;

    printf("\nCódigo da disciplina: ");
    scanf("%d", &codigo);

    if (codigo <= 0) {
        printf("\nCódigo inválido!\n");
        return false;
    }

    posicaoDisciplina = encontraCodigoDisciplina(codigo, qtdDisciplinas, disciplinas);

    if (posicaoDisciplina == -1) {
        printf("Disciplina não encontrada!\n");
        return false;
    } else {
        disciplinas[posicaoDisciplina].ativo = false;

        for (int i = posicaoDisciplina; i < qtdDisciplinas - 1; i++) {
            disciplinas[i] = disciplinas[i + 1];
        }

        qtdDisciplinas--;
        return true;
    }
}

int atualizarDisciplina(int qtdDisciplinas, Disciplina disciplinas[], int qtdProfessores, Professor professores []) {
    int codigo = obtemCodigo();

    int posicaoDisciplina = encontraCodigoDisciplina(codigo, qtdDisciplinas, disciplinas);
        if (posicaoDisciplina == -1) {
        printf("Disciplina não encontrada!\n");
        return false;
        }

    strcpy(disciplinas[posicaoDisciplina].nome, obtemNome(MAXNOMEDISCIPLINA));
    atualizaSemestre(&disciplinas[posicaoDisciplina].semestreAtual);

    printf("Professor responsável:\n");
    int matricula = obtemMatricula();
    int posicaoProfessor = encontraMatriculaProfessor (qtdProfessores, professores, matricula);

    if (posicaoProfessor == -1) {
        printf("Professor não encontrado!\n");
        return false;
    }

    disciplinas[posicaoDisciplina].professorResponsavel = professores[posicaoProfessor];

    return true;
}

//Funções para matrículas
int obtemOpcaoMatriculados (){
    int opcao;

    printf("\nOpções Matrículas:\n");
    printf("0: voltar\n");
    printf("1: matricular aluno\n");
    printf("2: excluir aluno\n");
    printf("3: listar matriculados\n");

    scanf("%d", &opcao);

    return opcao;  
}

int obtemOpcaoListarMatriculados (){
    int opcaoListar;

    printf("\nOpções Listar Matriculados:\n");
    printf("0: voltar\n");
    printf("1: listar uma disciplina\n");
    printf("2: lista de alunos matriculados em menos de 3 disciplinas\n");
    printf("3: lista de Disciplinas, com nome do professor, que extrapolam 40 vagas\n");

    scanf("%d", &opcaoListar);

    return opcaoListar;  
}

int matricularAlunoDisciplina (Disciplina disciplinas [], int qtdDisciplinas, Aluno alunos[], int qtdAlunos, int qtdAlunosMatriculados){

    printf("\nDisciplina:\n");
    int codigo = obtemCodigo();

    int posicaoDisciplina = encontraCodigoDisciplina (codigo, qtdDisciplinas, disciplinas);
    if (posicaoDisciplina == -1) {
        printf("Disciplina não encontrada!\n");
        return false;
    }

    printf("\nAluno que deseja matricular:\n");
    int matricula = obtemMatricula();
    int posicaoAluno = encontraMatriculaAluno (qtdAlunos, alunos, matricula);

    if (posicaoAluno == -1) {
        printf("Aluno não encontrado!\n");
        return false;
    }

    for (int i = 0; i < disciplinas[posicaoDisciplina].qtdAlunosMatriculados; i++) {
        if (disciplinas[posicaoDisciplina].alunosMatriculados[i].matricula == matricula && 
            disciplinas[posicaoDisciplina].alunosMatriculados[i].ativo) {
            printf("Aluno já está matriculado nesta disciplina!\n");
            return false;
        }
    }

    if (disciplinas[posicaoDisciplina].qtdAlunosMatriculados < MAXALUNOSDISCIPLINAS) {
        disciplinas[posicaoDisciplina].alunosMatriculados[disciplinas[posicaoDisciplina].qtdAlunosMatriculados] = alunos[posicaoAluno];
        disciplinas[posicaoDisciplina].qtdAlunosMatriculados++;
        disciplinas[posicaoDisciplina].ativo = true;

        return true;

    } else {
        printf("Não há vagas disponíveis nesta disciplina.\n");
        return false;
    }

    return true;
}

int excluirAlunoDisciplina (Disciplina disciplinas [], int qtdDisciplinas, Aluno alunos [], int qtdAlunos, int qtdAlunosMatriculados){
    printf("\nDisciplina:\n");
    int codigo = obtemCodigo();

    int posicaoDisciplina = encontraCodigoDisciplina (codigo, qtdDisciplinas, disciplinas);
    if (posicaoDisciplina == -1) {
        printf("\nDisciplina não encontrada!\n");
        return false;
    }

    printf("\nMatrícula do aluno que deseja excluir:\n");   
    int matricula = obtemMatricula();
    
    int posicaoAlunoMatriculado = -1;
    for (int i = 0; i < disciplinas[posicaoDisciplina].qtdAlunosMatriculados; i++) {
        if (disciplinas[posicaoDisciplina].alunosMatriculados[i].matricula == matricula) {
            posicaoAlunoMatriculado = i;
            break;
        }
    }

    if (posicaoAlunoMatriculado == -1) {
        printf("Aluno não está matriculado na disciplina!\n");
        return false;
    }
    
    disciplinas[posicaoDisciplina].alunosMatriculados[posicaoAlunoMatriculado].ativo = false;
    disciplinas[posicaoDisciplina].qtdAlunosMatriculados--;

    return true;
}

void listarDisciplinaAlunos (int qtdDisciplinas, Disciplina disciplinas[]){

    if (qtdDisciplinas == 0){
        printf("Não há disciplinas cadastradas!\n");
        return;
    }

    printf("\nDisciplina:\n");
    int codigo = obtemCodigo();

    int posicaoDisciplina = encontraCodigoDisciplina (codigo, qtdDisciplinas, disciplinas);
    if (posicaoDisciplina == -1) {
        printf("Disciplina não encontrada!\n");
        return;
    }

    if (disciplinas[posicaoDisciplina].ativo) {
        printf("\nCódigo da disciplina: %d\n", disciplinas[posicaoDisciplina].codigo);
        printf("Nome: %s\n", disciplinas[posicaoDisciplina].nome);
        printf("Semestre atual: %d.%d\n", disciplinas[posicaoDisciplina].semestreAtual.ano, disciplinas[posicaoDisciplina].semestreAtual.periodo);
        printf("Professor responsável: %s\n", disciplinas[posicaoDisciplina].professorResponsavel.nome);
        printf("\n");

        printf("Alunos matriculados:\n");
        
        int alunosAtivos = false;

        for (int j = 0; j < disciplinas[posicaoDisciplina].qtdAlunosMatriculados; j++) {
            if (disciplinas[posicaoDisciplina].alunosMatriculados[j].ativo) {
                printf("- %s\n", disciplinas[posicaoDisciplina].alunosMatriculados[j].nome);
                alunosAtivos = true;
            } 
        }
        if (alunosAtivos == false) {
        printf("Nenhum aluno matriculado.\n");
        }
    }
}
  
void listarAlunosMenosDeTresDisciplinas(int qtdDisciplinas, Disciplina disciplinas[], Aluno alunos[], int qtdAlunos){

    if (qtdDisciplinas == 0) {
        printf("Não há disciplinas cadastradas!\n");
        return;
    }

    int contagem[MAXALUNOSDISCIPLINAS] = {0};
    int matricula;

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].ativo) {
            for (int j = 0; j < disciplinas[i].qtdAlunosMatriculados; j++) {
                if (disciplinas[i].alunosMatriculados[j].ativo) {
                    matricula = disciplinas[i].alunosMatriculados[j].matricula;
                    contagem[matricula]++;
                }
            }
        }
    }

    printf("\nAlunos matriculados em menos de 3 disciplinas:\n");
    for (int i = 0; i < qtdAlunos; i++) { 
        if (alunos[i].ativo && contagem[alunos[i].matricula] > 0 && contagem[alunos[i].matricula] < 3) {
            printf("- %s: Matriculado em %d disciplinas\n", alunos[i].nome, contagem[alunos[i].matricula]);
        }
    }
}

//Funções auxiliares
int encontraCodigoDisciplina(int codigo, int qtdDisciplinas, Disciplina disciplinas[]){

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}
