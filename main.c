#include <stdio.h>
#define MAX 3
#define VERDADEIRO 1
#define FALSO 0

typedef struct {
    int matricula;
    int ativo;
} Aluno;

// Protótipos
int obtemOpcaoGeral();
int obtemOpcaoAluno();
int cadastrarAluno(int qtdAlunos, Aluno alunos[]);
void listarAlunos(int qtdAlunos, Aluno alunos[]);
int atualizarAluno(int qtdAlunos, Aluno alunos[]);

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
                        case 0 /* Sair */: {
                            sairAluno = VERDADEIRO;
                            break;
                        }
                        case 1 /* Cadastrar */: {
                            int cadastroRealizado = cadastrarAluno(qtdAlunos, alunos);

                            if (cadastroRealizado) {
                                qtdAlunos++;
                                printf("Aluno cadastrado com sucesso\n");
                            }
                            else
                                printf("Matrícula não realizada\n");

                            break;
                        }
                        case 2 /* Listar */: {
                            listarAlunos(qtdAlunos, alunos);
                            break;
                        }
                        case 3 /* Atualizar */: {
                            int atualizado = atualizarAluno(qtdAlunos, alunos);

                            if (atualizado)
                                printf("Aluno atualizado com sucesso\n");
                            else
                                printf("Atualização não realizada\n");

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
    printf("3: atualizar aluno\n");
    printf("4: excluir aluno\n");

    scanf("%d", &opcao);
    return opcao;
}

int cadastrarAluno(int qtdAlunos, Aluno alunos[]) {
    if (qtdAlunos == MAX) {
        printf("Máximo de alunos atingido\n");
        return FALSO;
    }

    int matricula;
    printf("Nova matrícula de aluno: ");
    scanf("%d", &matricula);

    if (matricula <= 0) {
        printf("Matrícula inválida\n");
        return FALSO;
    }
    else
    {
        alunos[qtdAlunos].matricula = matricula;
        alunos[qtdAlunos].ativo = VERDADEIRO;
        return VERDADEIRO;
    }
}

void listarAlunos(int qtdAlunos, Aluno alunos[]) {
    if (qtdAlunos == 0) {
        printf("Não há alunos cadastrados\n");
    } else {
        for (int i = 0; i < qtdAlunos; i++) {
            if (alunos[i].ativo)
                printf("Matrícula: %d\n", alunos[i].matricula);
        }
    }
}

int atualizarAluno(int qtdAlunos, Aluno alunos[]) {
    int matricula;
    int matricula_encontrada = FALSO;

    printf("Matrícula do aluno a ser atualizado: ");
    scanf("%d", &matricula);

    if (matricula <= 0) {
        printf("Matrícula inválida\n");
        return FALSO;
    }
    else
    {
        for (int i = 0; i < qtdAlunos; i++) {
            if (alunos[i].matricula == matricula && alunos[i].ativo) {
                int nova_matricula;
                printf("Nova matrícula: ");
                scanf("%d", &nova_matricula);

                if (nova_matricula <= 0) {
                    printf("Matrícula inválida\n");
                    return FALSO;
                }
                else
                {
                    alunos[i].matricula = nova_matricula;
                    return VERDADEIRO;
                }
            }
        }

        printf("Matrícula não encontrada\n");
        return FALSO;
    }
}