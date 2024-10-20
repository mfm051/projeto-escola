#include <stdio.h>
#include "professor.h"

int obtemOpcaoProfessor(){
  
    int opcao;

    printf("\nOpções Professor:\n");
    printf("0: voltar\n");
    printf("1: cadastrar professor\n");
    printf("2: listar professores\n");
    printf("3: atualizar professor\n");
    printf("4: excluir professor\n");

    scanf("%d", &opcao);
    return opcao;  

}