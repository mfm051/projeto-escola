#include "validacoes.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int validaMatricula(const char *entrada) {
    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            printf("A matrícula deve conter apenas números!\n");
            return false;
        }
    }

    if (atoi(entrada) == 0) {
        printf("Matrícula não pode ser nula!\n");
        return false;
    }

    return true;
}

int validaCodigo(const char *entrada) {
    for (int i = 0; i < strlen(entrada); i++) {
        if (!isdigit(entrada[i])) {
            printf("O código deve conter apenas números!\n");
            return false;
        }
    }

    if (atoi(entrada) == 0) {
        printf("Código não pode ser nulo!\n");
        return false;
    }

    return true;
}

int validaSexo(char sexo) {
    if (sexo != 'M' && sexo != 'F') {
        printf("Sexo inválido\n");
        return false;
    }

    return true;
}

int validaData(int dia, int mes, int ano) {
    if ((dia >= 1 && dia <= 31) && 
        (mes >= 1 && mes <= 12) && 
        (ano >= 1900 && ano <= 3000))
        return true;

    printf("Data inválida\n");
    return false;
}

int validaCPF(char cpf[]) {
    if (strlen(cpf) != 11)
    {
        printf("CPF inválido\n");
        return false;
    }

    return true;
}

int validaSemestre(int ano, int periodo){

    if (ano <= 0) {
        printf("Semestre inválido!\n");
        return false;
    }

    if (periodo <= 0) {
        printf("Semestre inválido!\n");
        return false;
    }

    if ((periodo < 1) || (periodo > 2)) {
        printf("Semestre inválido!\n");
        return false;
    }


    return true;
}