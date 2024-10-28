#include "disciplina.h"
#include "interface.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int obtemOpcaoDisciplina (){
    int opcao;

    printf("\nOpções Disciplina:\n");
    printf("0: voltar\n");
    printf("1: cadastrar disciplina\n");
    printf("2: listar disciplinas\n");
    printf("3: atualizar disciplina\n");
    printf("4: excluir disciplina\n");
    printf("5: matriculados\n");

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
    printf("Professor responsável:\n");
    int matricula = obtemMatricula();
    int indiceProfessor = encontraMatriculaProfessor (qtdProfessores, professores, matricula);

    if (indiceProfessor == -1) {
        printf("Professor não encontrado! Cadastre o professor antes de associá-lo à disciplina.\n");
        return false;
    }

    // Associando o professor encontrado
    disciplinas[qtdDisciplinas].professorResponsavel = professores[indiceProfessor];

    disciplinas[qtdDisciplinas].qtdAlunosMatriculados = 0;
    disciplinas[qtdDisciplinas].ativo = true;

    return true;
}

void listarDisciplinas (int qtdDisciplinas, Disciplina disciplinas[]) {
    if (qtdDisciplinas == 0)
        printf("Não há disciplinas cadastrados!\n");
    else {
        for (int i = 0; i < qtdDisciplinas; i++) {
            if (disciplinas[i].ativo) {
                printf("Código: %d\n", disciplinas[i].codigo);
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

    printf("Código da disciplina: ");
    scanf("%d", &codigo);

    if (codigo <= 0) {
        printf("Código inválido!\n");
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

int atualizarDisciplina(int qtdDisciplinas, Disciplina disciplinas[]) {
    int codigo = obtemCodigo();

    int posicaoDisciplina = encontraCodigoDisciplina(codigo, qtdDisciplinas, disciplinas);
        if (posicaoDisciplina == -1) {
        printf("Disciplina não encontrada!\n");
        return false;
        }

    strcpy(disciplinas[posicaoDisciplina].nome, obtemNome(MAXNOMEDISCIPLINA));
    atualizaSemestre(&disciplinas[posicaoDisciplina].semestreAtual);

    return true;
}

int obtemOpcaoMatriculados (){
    int opcao;

    printf("\nOpções Matriculados:\n");
    printf("0: voltar\n");
    printf("1: matricular aluno\n");
    printf("2: excluir aluno\n");
    printf("3: listar matriculados\n");

    scanf("%d", &opcao);

    return opcao;  
}

int matricularAlunoDisciplina (Disciplina disciplinas [], int qtdDisciplinas, Aluno alunos[], int qtdAlunos, int qtdAlunosMatriculados){

    printf("Disciplina:\n");
    int codigo = obtemCodigo();

    int posicaoDisciplina = encontraCodigoDisciplina (codigo, qtdDisciplinas, disciplinas);
    if (posicaoDisciplina == -1) {
        printf("Disciplina não encontrada!.\n");
        return false;
    }

    printf("Aluno que deseja matricular:\n");
    int matricula = obtemMatricula();
    int posicaoAluno = encontraMatriculaAluno (qtdAlunos, alunos, matricula);

    if (posicaoAluno == -1) {
        printf("Aluno não encontrado!\n");
        return false;
    }

    if (disciplinas[posicaoDisciplina].qtdAlunosMatriculados < MAXALUNOS) {

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


//Funções auxiliares

int encontraNomeDisciplina(int qtdDisciplinas, Disciplina disciplinas[], char nome[]) {
    for (int i = 0; i < qtdDisciplinas; i++) {
        if (strcmp(disciplinas[i].nome, nome) == 0 && disciplinas[i].ativo) {
            return i;
        }
    }
    return -1;
}

int encontraCodigoDisciplina(int codigo, int qtdDisciplinas, Disciplina disciplinas[]) {

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}
