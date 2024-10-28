#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "interface.h"
#include "constantes.h"

#include <stdio.h>
#include <stdbool.h>

// Protótipos
int obtemOpcaoGeral ();

int main()
{
    Aluno alunos[MAXALUNOS];
    Professor professores[MAXPROFESSORES];
    Disciplina disciplinas[MAXDISCIPLINAS];

    int qtdAlunos = 0;
    int qtdProfessores = 0;
    int qtdDisciplinas = 0;
    int qtdAlunosMatriculados = 0;

    printf("\nPROJETO ESCOLA\n");

    int opcao;
    int sair = false;

    while (!sair) {
        opcao = obtemOpcaoGeral();

        switch (opcao) {
            case 0: {
                sair = true;
                break;
            }
            case 1: {
                printf("\nMódulo Aluno\n");

                int sairAluno = false;

                while (!sairAluno) {
                    switch (obtemOpcaoModulo()) {
                        case 0 /* Sair */: {
                            sairAluno = true;
                            break;
                        }
                        case 1 /* Cadastrar */: {
                            int cadastrado = cadastrarAluno(qtdAlunos, alunos, MAXALUNOS);

                            if (cadastrado) {
                                qtdAlunos++;
                                printf("Aluno cadastrado com sucesso!\n");
                            }
                            else
                                printf("Matrícula não realizada!\n");

                            break;
                        }
                        case 2 /* Listar */: {
                            listarAlunos(qtdAlunos, alunos);
                            break;
                        }
                        case 3 /* Atualizar */: {
                            int atualizado = atualizarAluno(qtdAlunos, alunos);

                            if (atualizado)
                                printf("Aluno atualizado com sucesso!\n");
                            else
                                printf("Atualização não realizada!\n");

                            break;
                        }
                        case 4 /* Excluir */: {
                            int excluido = excluirAluno(qtdAlunos, alunos);

                            if (excluido) {
                                printf("Aluno excluído com sucesso!\n");
                                qtdAlunos--;
                            } else
                                printf("Exclusão não realizada!\n");

                            break;
                        }
                        default:
                            printf("Opção inválida!\n");
                    }
                }
                break;
            }
            case 2: {
                printf("\nMódulo Professor\n");

                int sairProfessor = false;

                while (!sairProfessor) {
                    switch (obtemOpcaoModulo()) {
                        case 0 /* Sair */: {
                            sairProfessor = true;
                            break;
                        }
                        case 1 /* Cadastrar */: {
                            int cadastrado = cadastrarProfessor(qtdProfessores, professores, MAXPROFESSORES);

                            if (cadastrado) {
                                qtdProfessores++;
                                printf("Professor cadastrado com sucesso!\n");
                            }
                            else
                                printf("Matrícula não realizada!\n");

                            break;
                        }
                        case 2 /* Listar */: {
                            listarProfessores(qtdProfessores, professores);
                            break;
                        }
                        case 3 /* Atualizar */: {
                            int atualizado = atualizarProfessor (qtdProfessores, professores);

                            if (atualizado)
                                printf("Professor atualizado com sucesso!\n");
                            else
                                printf("Atualização não realizada!\n");

                            break;
                        }
                        case 4 /* Excluir */: {
                            int excluido = excluirProfessor(qtdProfessores, professores);

                            if (excluido) {
                                printf("Professor excluído com sucesso!\n");
                                qtdProfessores--;
                            } else
                                printf("Exclusão não realizada!\n");
                                break;
                        }
                        default:
                            printf("Opção inválida!\n");
                    }
                }  
                break;
            }
            case 3: {

                printf("\nMódulo Disciplina\n");

                int opcaoDisciplina;
                int sairDisciplina = false;

                while (!sairDisciplina) {
                    opcaoDisciplina = obtemOpcaoDisciplina();

                    switch (opcaoDisciplina) {
                        case 0 /* Sair */: {
                            sairDisciplina = true;
                            break;
                        }

                        case 1 /* Cadastrar */: {
                            int cadastrado = cadastrarDisciplina(qtdDisciplinas, disciplinas, MAXDISCIPLINAS, professores, qtdProfessores);

                            if (cadastrado) {
                                qtdDisciplinas++;
                                printf("Disciplina cadastrada com sucesso!\n");
                            }
                            else
                                printf("Cadastro não realizado!\n");
                            break;
                        }

                        case 2 /* Listar */: {
                            listarDisciplinas(qtdDisciplinas, disciplinas);
                            break;
                        }

                        case 3 /* Atualizar */: {
                            int atualizado = atualizarDisciplina(qtdDisciplinas, disciplinas);

                            if (atualizado)
                                printf("Disciplina atualizada com sucesso!\n");
                            else
                                printf("Atualização não realizada!\n");
                            break;
                        }

                        case 4 /* Excluir */: {
                            int excluido = excluirDisciplina(qtdDisciplinas, disciplinas);

                            if (excluido) {
                                printf("Disciplina excluída com sucesso!\n");
                                qtdDisciplinas--;
                            } else
                                printf("Exclusão não realizada!\n");
                                break;
                        }

                        case 5 /*Matriculados*/: {

                            int opcao;
                            int sairMatriculados = false;

                            while (!sairMatriculados){

                                opcao = obtemOpcaoMatriculados ();

                                switch (opcao){

                                    case 0: {
                                        sairMatriculados = true;
                                        break;
                                    }

                                    case 1: /*Matricular aluno*/{
                                        int matriculado = matricularAlunoDisciplina (disciplinas, qtdDisciplinas, alunos, qtdAlunos, qtdAlunosMatriculados);
                                        if (matriculado) {
                                            qtdAlunosMatriculados++;
                                            printf("Aluno cadastrado com sucesso!\n");
                                        }
                                        else
                                            printf("Cadastro não realizado!\n");
                                        break;
                                    }
                                }
                            }
                        }

                        default:
                            printf("Opção inválida!\n");                       
                    }
                }  
                break;               

            }

            default:
                printf("Opção inválida!\n");
        }
    }
}

// Funções

int obtemOpcaoGeral() {
    int opcao;

    printf("\nOpções:\n");
    printf("0: sair\n");
    printf("1: aluno\n");
    printf("2: professor\n");
    printf("3: disciplina\n");

    scanf("%d", &opcao);
    
    return opcao;
}