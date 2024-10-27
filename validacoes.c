#include "validacoes.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int validaMatricula(int matricula) {
    if (matricula <= 0) {
        printf("Matrícula inválida\n");
        return false;
    }

    return true;
}

int validaCodigo(int codigo) {
    if (codigo <= 0) {
        printf("Código inválido\n");
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
        printf("CPF inválido");
        return false;
    }

    return true;
}