#include "interface.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int obtemMatricula() {
    int matricula;

    do {
        printf("Matrícula: ");
        scanf("%d", &matricula);
    } while (validaMatricula(matricula) == false);

    return matricula;
}

char obtemSexo() {
    char sexo;

    do {
        printf("Sexo [M/F]: ");
        scanf("%c", &sexo);
    } while (validaSexo(sexo) == false);

    return sexo;
}

char *obtemNome() {
    char *nome;
    nome = (char *) malloc ((MAXNOME + 1) * sizeof(char));

    printf("Nome: ");
    fgetc(stdin);
    fgets(nome, MAXNOME, stdin);
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