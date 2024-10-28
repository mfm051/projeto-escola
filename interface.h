#include "validacoes.h"
#include "constantes.h"
#include "data.h"
#include "semestre.h"

#ifndef INTERFACE_H
#define INTERFACE_H

int obtemOpcaoModulo();
int obtemMatricula();
int obtemCodigo();
char obtemSexo();
char *obtemNome(int maxChars);
void atualizaData(Data *data);
char *obtemCPF();
Semestre obtemSemestre();

#endif