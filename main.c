#include <stdio.h>
#define MAX 3
#define VERDADEIRO 1
#define FALSO 0

// Protótipos
int obtemOpcaoGeral();
int obtemOpcaoAluno();

typedef struct {
    int matricula;
    int ativo;
} Aluno;

int main()
{
    Aluno alunos[MAX];
    int qtdAlunos = 0;

    printf("Projeto escola\n\n");

    int opcao;
    int sair = FALSO;

    while (!sair) {
        opcao = obtemOpcaoGeral();

        switch (opcao) {
            case 0: {
                sair = VERDADEIRO;
                break;
            }
            case 1: {
                printf("Módulo Aluno\n\n");

                int opcaoAluno;
                int sairAluno = FALSO;

                while (!sairAluno) {
                    opcaoAluno = obtemOpcaoAluno();

                    switch (opcaoAluno) {
                        case 0: {
                            sairAluno = VERDADEIRO;
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
                                alunos[qtdAlunos].ativo = VERDADEIRO;
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
                                    if (alunos[i].ativo)
                                        printf("Matrícula: %d\n", alunos[i].matricula);
                                }
                            }

                            break;
                        }
                        case 3: {
                            int matricula;
                            int matricula_encontrada = FALSO;
                            printf("Matrícula: ");
                            scanf("%d", &matricula);

                            if (matricula <= 0) {
                                printf("Matrícula inválida\n");
                            } else {
                                for (int i = 0; i < qtdAlunos; i++) {
                                    if (alunos[i].matricula == matricula) {
                                        matricula_encontrada = 1;
                                        alunos[i].ativo = FALSO;

                                        for (int j = i; j < qtdAlunos; j++) {
                                            alunos[j] = alunos[j + 1];
                                        };

                                        qtdAlunos--;
                                        break;
                                    }
                                }

                                if (matricula_encontrada)
                                    printf("Aluno excluído com sucesso\n");
                                else
                                    printf("Matrícula não encontrada\n");
                            }

                            break;
                        }
                        case 4: {
                            int matricula;
                            int matricula_encontrada = FALSO;
                            printf("Matrícula: ");
                            scanf("%d", &matricula);

                            if (matricula <= 0) {
                                printf("Matrícula inválida\n");
                            } else {
                                for (int i = 0; i < qtdAlunos; i++) {
                                    if (alunos[i].matricula == matricula && alunos[i].ativo) {
                                        matricula_encontrada = VERDADEIRO;

                                        int nova_matricula;
                                        printf("Nova matrícula: ");
                                        scanf("%d", &nova_matricula);

                                        if (nova_matricula <= 0)
                                            printf("Matrícula inválida\n");
                                        else {
                                            alunos[i].matricula = nova_matricula;
                                            printf("Matrícula atualizada com sucesso\n");
                                        }
                                        break;
                                    }
                                }

                                if (!matricula_encontrada)
                                    printf("Matrícula não encontrada\n");
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

// Funções

int obtemOpcaoGeral() {
    int opcao;

    printf("\n\nOpções:\n\n");
    printf("0: sair\n");
    printf("1: aluno\n");

    scanf("%d", &opcao);
    return opcao;
}

int obtemOpcaoAluno() {
    int opcao;

    printf("\n\nOpções Aluno:\n\n");
    printf("0: voltar\n");
    printf("1: cadastrar aluno\n");
    printf("2: listar alunos\n");
    printf("3: excluir aluno\n");
    printf("4: atualizar aluno\n");

    scanf("%d", &opcao);
    return opcao;
}