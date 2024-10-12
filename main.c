#include <stdio.h>
#define MAX 3

typedef struct {
    int matricula;
} Aluno;

int main()
{
    Aluno alunos[MAX];
    int qtdAlunos = 0;

    printf("Projeto escola\n\n");

    int opcao;
    int sair = 0; // falso

    while (!sair) {
        printf("Opções:\n\n");
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

                int opcaoAluno;
                int sairAluno = 0; // falso

                while (!sairAluno) {
                    printf("Opções Aluno:\n\n");
                    printf("0: voltar\n");
                    printf("1: cadastrar aluno\n");

                    scanf("%d", &opcaoAluno);

                    switch (opcaoAluno) {
                        case 0: {
                            sairAluno = 1;
                            break;
                        }
                        case 1: {
                            
                            if (qtdAlunos == MAX) {
                                printf("Máximo de alunos atingido\n");
                                break;
                            }

                            printf("Cadastro de aluno:\n\n");
                            printf("Matrícula: ");
                            scanf("%d", &alunos[qtdAlunos].matricula);
                            
                            qtdAlunos++;
                            break;
                        }
                    }
                }
                break;
            }
            default:
                printf("Opção inválida");
        }
    }
}