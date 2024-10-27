#include "validacoes.h"
#include "constantes.h"
#include "data.h"

#ifndef INTERFACE_H
#define INTERFACE_H

int obtemOpcaoModulo();
int obtemMatricula();
char obtemSexo();
char *obtemNome();
void atualizaData(Data *data);
char *obtemCPF();

#endif