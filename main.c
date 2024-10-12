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
        printf("\n\nOpções:\n\n");
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
                    printf("\n\nOpções Aluno:\n\n");
                    printf("0: voltar\n");
                    printf("1: cadastrar aluno\n");
                    printf("2: listar alunos\n");

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

                            int matricula;
                            printf("Matrícula: ");
                            scanf("%d", &matricula);

                            if (matricula <= 0) {
                                printf("Matrícula inválida\n");
                            } else {
                                alunos[qtdAlunos].matricula = matricula;
                                qtdAlunos++;
                                printf("Aluno cadastrado com sucesso\n");
                            }
                            break;
                        }
                        case 2: {
                            if (qtdAlunos == 0) {
                                printf("Não há alunos cadastrados\n");
                            } else {
                                for (int i = 0; i < qtdAlunos; i++) {
                                    printf("Matrícula: %d\n", alunos[i].matricula);
                                }
                            }

                            break;
                        }
                        default:
                            printf("Opção inválida");
                    }
                }
                break;
            }
            default:
                printf("Opção inválida");
        }
    }
}