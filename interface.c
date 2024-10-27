#include "interface.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int obtemMatricula() {
    int matricula;

    do {
        printf("Matrícula: ");
        scanf("%d", &matricula);
    } while (validaMatricula(matricula) == false);

    return matricula;
}

int obtemCodigo() {
    int codigo;

    do {
        printf("Código: ");
        scanf("%d", &codigo);
    } while (validaCodigo(codigo) == false);

    return codigo;
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

    printf("Nome: ");
    fgetc(stdin);
    fgets(nome, maxChars, stdin);
    nome[strlen(nome) - 1] = 0;

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