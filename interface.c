#include "interface.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int obtemModulo() {
    int opcao;

    printf("\nOpções:\n");
    printf("0: sair\n");
    printf("1: aluno\n");
    printf("2: professor\n");
    printf("3: disciplina\n");
    printf("4: aniversariantes\n");
    printf("5: busca\n");

    scanf("%d", &opcao);

    return opcao;
}

int obtemOpcaoModulo(){
    int opcao;

    printf("\nOpções :\n");
    printf("0: voltar\n");
    printf("1: cadastrar\n");
    printf("2: listar\n");
    printf("3: atualizar\n");
    printf("4: excluir \n");

    scanf("%d", &opcao);

    return opcao;
}

int obtemOpcaoListagem() {
    int opcao;

    printf("\nOpções :\n");
    printf("0: Cancelar\n");
    printf("1: Listagem geral\n");
    printf("2: Listagem sexo feminino\n");
    printf("3: Listagem sexo masculino\n");
    printf("4: Listagem por ordem alfabética\n");
    printf("5: Listagem por ordem de nascimento\n");

    scanf("%d", &opcao);

    return opcao;
}

int obtemMatricula() {
    char entrada[10];

    do {
        printf("Matrícula: ");
        scanf("%9s", entrada);  // Lê a entrada como uma string com limite de 9 caracteres
    } while (validaMatricula(entrada) == false);

    return atoi(entrada);
}

int obtemCodigo() {
    char entrada[10];

    do {
        printf("Código: ");
        scanf("%9s", entrada); // Lê a entrada como uma string com limite de 9 caracteres
    } while (validaCodigo(entrada) == false);

    return atoi(entrada);
}

char obtemSexo() {
    char sexo;

    do {
        printf("Sexo [M/F]: ");
        scanf("%c", &sexo);
    } while (validaSexo(sexo) == false);

    return sexo;
}

char *obtemNome(int maxChars) {
    char *nome;
    nome = (char *) malloc ((maxChars + 1) * sizeof(char));

    do {
        printf("Nome: ");
        fgetc(stdin);
        fgets(nome, maxChars, stdin);
        nome[strlen(nome) - 1] = 0;
    } while (validaNome(nome) == false);

    return nome;
}

void atualizaData(Data* data) {
    int dia, mes, ano;

    do {
        printf("Data de nascimento (dia/mês/ano): ");
        scanf("%d/%d/%d", &dia, &mes, &ano);
    } while (validaData(dia, mes, ano) == false);

    (*data).dia = dia;
    (*data).mes = mes;
    (*data).ano = ano;
}

char *obtemCPF() {
    char *cpf;
    cpf = (char *) malloc ((MAXCPF + 2) * sizeof(char));

    do {
        printf("CPF: ");
        scanf("%s", cpf);
    } while (validaCPF(cpf) == false);

    return cpf;
}

int obtemMesAniversario() {
    int mes;

    do {
        printf("Mês (1: jan.. 12: dez): ");
        scanf("%d", &mes);
    } while (mes < 1 || mes > 12);

    return mes;
}

void atualizaSemestre (Semestre *semestreAtual) {
    int ano, periodo;

    do {
        printf("Semestre atual (ano.período): ");
        scanf("%d.%d", &ano, &periodo);
    } while (validaSemestre(ano, periodo) == false);

    (*semestreAtual).ano = ano;
    (*semestreAtual).periodo = periodo;
}