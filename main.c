#include <stdio.h>

int main() {
    printf("Projeto escola\n\n");

    int opcao;
    int sair = 0; // falso

    while (!sair) {
        printf("Opções:\n");
        printf("0: sair\n");
        printf("1: aluno\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 0: {
                sair = 1;
                break;
            }
            case 1: {
                printf("Módulo Aluno\n\n");
                break;
            }
            default:
                printf("Opção inválida");
        }
    }
}