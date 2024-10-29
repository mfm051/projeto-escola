#ifndef VALIDACOES_H
#define VALIDACOES_H

int validaMatricula(const char *entrada);
int validaCodigo(int codigo);
int validaSexo(char sexo);
int validaData(int dia, int mes, int ano);
int validaCPF(char cpf[]);
int validaSemestre(int ano, int periodo);

#endif