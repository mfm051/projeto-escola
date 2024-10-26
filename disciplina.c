#include <stdio.h>
#include <string.h>
#include "disciplina.h"
#include "professor.h"
#include "semestre.h"

#define VERDADEIRO 1
#define FALSO 0

int cadastrarDisciplina(int qtdDisciplinas, Disciplina disciplinas[], int maxDisciplinas) {

    char nomeDisciplina[MAXNOME];
    int codigo;
    Semestre periodoAtual;
    Professor dadosProfessor;

    if (qtdDisciplinas == maxDisciplinas) {
        printf("Máximo de disciplinas atingido!\n");
        return FALSO;
    }//pronto

    printf("Código da disciplina: ");
    scanf("%d", &codigo);

    if (codigo < 0) {
        printf("Código inválido!");
        return FALSO;
    }//pronto

    if (encontraCodigoDisciplina(qtdDisciplinas, disciplinas, codigo) != -1) {
        printf("Código já cadastrado!\n");
        return FALSO;
    }//pronto

    disciplinas[qtdDisciplinas].codigo = codigo;//pronto

    printf("Digite o nome da disciplina: ");
    fgetc(stdin);
    fgets(disciplinas[qtdDisciplinas].nomeDisciplina, MAXNOME, stdin);
    disciplinas[qtdDisciplinas].nomeDisciplina[strlen(disciplinas[qtdDisciplinas].nomeDisciplina) - 1] = 0;
    //pronto

    if (encontraDisciplinaProfessor(qtdDisciplinas, disciplinas, nomeDisciplina) != -1) {
        printf("Disciplina já cadastrada\n");
        return FALSO;
    }//pronto

    printf("Digite o semestre da disciplina: ");
    scanf("%d %d", &periodoAtual.ano, &periodoAtual.periodo);


    printf("Digite o nome do professor responsável: ");
    scanf("%c", &dadosProfessor.nome);

    Professor* professor = buscarProfessorPorNome(dadosProfessor.nome);
    
    if (professor == NULL) {
        printf("Professor com o nome %c não encontrado. Cadastro cancelado.\n", dadosProfessor.nome);
        return;
    }

    return VERDADEIRO;
}

