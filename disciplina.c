#include "disciplina.h"
#include "interface.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int cadastrarDisciplina(int qtdDisciplinas, Disciplina disciplinas[], int maxDisciplinas) {

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

                printf("Alunos matriculados:\n");
                if (disciplinas[i].qtdAlunosMatriculados > 0) {
                    for (int j = 0; j < disciplinas[i].qtdAlunosMatriculados; j++) {
                        printf("- %s\n", disciplinas[i].alunosMatriculados[j].nome);
                    }
                } else {
                    printf("Nenhum aluno matriculado.\n");
                }
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
    int codigo;
    printf("Digite o código da disciplina a ser atualizada: ");
    scanf("%d", &codigo);
    int indice = encontraCodigoDisciplina(codigo, qtdDisciplinas, disciplinas);
    if (indice != -1) {
        printf("Digite o novo nome da disciplina: ");
        scanf("%s", disciplinas[indice].nome);
        return 1;
    }
    return 0;
}

int obtemOpcaoDisciplina (){
    int opcao;

    printf("\nOpções Disciplina:\n");
    printf("0: voltar\n");
    printf("1: cadastrar disciplina\n");
    printf("2: listar disciplinas\n");
    printf("3: atualizar disciplina\n");
    printf("4: excluir disciplina\n");

    scanf("%d", &opcao);

    return opcao;  
}

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