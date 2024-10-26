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
    }

    printf("Código da disciplina: ");
    scanf("%d", &codigo);

    if (codigo < 0) {
        printf("Código inválido!");
        return FALSO;
    }

    if (encontraCodigoDisciplina(qtdDisciplinas, disciplinas, codigo) != -1) {
        printf("Código já cadastrado!\n");
        return FALSO;
    }

    disciplinas[qtdDisciplinas].codigo = codigo;

    printf("Digite o nome da disciplina: ");
    fgetc(stdin);
    fgets(disciplinas[qtdDisciplinas].nomeDisciplina, MAXNOME, stdin);
    disciplinas[qtdDisciplinas].nomeDisciplina[strlen(disciplinas[qtdDisciplinas].nomeDisciplina) - 1] = 0;
    

    if (encontraDisciplinaProfessor(qtdDisciplinas, disciplinas, nomeDisciplina) != -1) {
        printf("Disciplina já cadastrada!\n");
        return FALSO;
    }

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

int excluirDisciplina (int qtdDisciplinas, Disciplina disciplinas[]) {
    int codigo;
    int posicaoDisciplina;

    printf("Código da disciplina: ");
    scanf("%d", &codigo);

    if (codigo <= 0) {
        printf("Código inválido!\n");
        return FALSO;
    }

    posicaoDisciplina = encontraCodigoDisciplina(qtdDisciplinas, disciplinas, codigo);

    if (posicaoDisciplina == -1) {
        printf("Disciplina não encontrada!\n");
        return FALSO;
    }
    else
    {
        disciplinas[posicaoDisciplina].ativo = FALSO;

        for (int i = posicaoDisciplina; i < qtdDisciplinas; i++) {
            disciplinas[i] = disciplinas[i + 1];
        };

        return VERDADEIRO;
    }
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

int encontraDisciplinaProfessor (int qtdDisciplinas, Disciplina disciplinas[], char nomeDisciplina[]) {
    int posicaoDisciplina = -1;

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].nomeDisciplina == nomeDisciplina && disciplinas[i].ativo)
            posicaoDisciplina = i;
    }
    
    return posicaoDisciplina;
}