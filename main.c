#include "aluno.h"
#include "professor.h"
#include "disciplina.h"
#include "interface.h"
#include "constantes.h"

#include <stdio.h>
#include <stdbool.h>

int main()
{
    Aluno alunos[MAXALUNOS];
    Professor professores[MAXPROFESSORES];
    Disciplina disciplinas[MAXDISCIPLINAS];

    int qtdAlunos = 0;
    int qtdProfessores = 0;
    int qtdDisciplinas = 0;
    int qtdAlunosMatriculados = 0;
    int alunosMatriculados = 0;
    int professorResponsavel = 0;

    printf("\nPROJETO ESCOLA\n");

    int opcao;
    int sair = false;

    while (!sair) {
        switch (obtemModulo()) {
            case SAIR: {
                sair = true;
                break;
            }
            case ALUNO: {
                printf("\nMódulo Aluno\n");

                int sairAluno = false;

                while (!sairAluno) {
                    switch (obtemOpcaoModulo()) {
                        case SAIR: {
                            sairAluno = true;
                            break;
                        }
                        case CADASTRAR: {
                            if (cadastrarAluno(qtdAlunos, alunos, MAXALUNOS)) {
                                qtdAlunos++;
                                printf("Aluno cadastrado com sucesso!\n");
                            }
                            else
                                printf("Matrícula não realizada!\n");

                            break;
                        }
                        case LISTAR: {
                            if (qtdAlunos == 0) {
                                printf("Não há alunos cadastrados!\n");
                                break;
                            }

                            switch(obtemOpcaoListagem()) {
                                case LISTAGEMGERAL: {
                                    listarAlunos(qtdAlunos, alunos);
                                    break;
                                }
                                case LISTAGEMFEM: {
                                    listarAlunosPorSexo('F', qtdAlunos, alunos);
                                    break;
                                }
                                case LISTAGEMMASC: {
                                    listarAlunosPorSexo('M', qtdAlunos, alunos);
                                    break;
                                }
                                case LISTAGEMALFABETICA: {
                                    listarAlunosAlfabeticamente(qtdAlunos, alunos);
                                    break;
                                }
                                case LISTAGEMNASCIMENTO: {
                                    listarAlunosPorNascimento(qtdAlunos, alunos);
                                    break;
                                }
                                default:
                                    break;
                            }
                            break;
                        }
                        case ATUALIZAR: {
                            if (atualizarAluno(qtdAlunos, alunos))
                                printf("Aluno atualizado com sucesso!\n");
                            else
                                printf("Atualização não realizada!\n");

                            break;
                        }
                        case EXCLUIR: {
                            if (excluirAluno(qtdAlunos, alunos)) {
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
            case PROFESSOR: {
                printf("\nMódulo Professor\n");

                int sairProfessor = false;

                while (!sairProfessor) {
                    switch (obtemOpcaoModulo()) {
                        case SAIR: {
                            sairProfessor = true;
                            break;
                        }
                        case CADASTRAR: {
                            if (cadastrarProfessor(qtdProfessores, professores, MAXPROFESSORES)) {
                                qtdProfessores++;
                                printf("Professor cadastrado com sucesso!\n");
                            }
                            else
                                printf("Matrícula não realizada!\n");

                            break;
                        }
                        case LISTAR: {
                            if (qtdProfessores == 0) {
                                printf("Não há professores cadastrados!\n");
                                break;
                            }

                            switch(obtemOpcaoListagem()) {
                                case LISTAGEMGERAL: {
                                    listarProfessores(qtdProfessores, professores);
                                    break;
                                }
                                case LISTAGEMFEM: {
                                    listarProfessoresPorSexo('F', qtdProfessores, professores);
                                    break;
                                }
                                case LISTAGEMMASC: {
                                    listarProfessoresPorSexo('M', qtdProfessores, professores);
                                    break;
                                }
                                case LISTAGEMALFABETICA: {
                                    listarProfessoresAlfabeticamente(qtdProfessores, professores);
                                    break;
                                }
                                case LISTAGEMNASCIMENTO: {
                                    listarProfessoresPorNascimento(qtdProfessores, professores);
                                    break;
                                }
                                default:
                                    break;
                            }
                            break;
                        }
                        case ATUALIZAR: {
                            if (atualizarProfessor (qtdProfessores, professores))
                                printf("Professor atualizado com sucesso!\n");
                            else
                                printf("Atualização não realizada!\n");

                            break;
                        }
                        case EXCLUIR: {
                            if (excluirProfessor(qtdProfessores, professores)) {
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
            case DISCIPLINA: {

                printf("\nMódulo Disciplina\n");

                int opcaoDisciplina;
                int sairDisciplina = false;

                while (!sairDisciplina) {
                    switch (obtemOpcaoDisciplina()) {
                        case SAIR: {
                            sairDisciplina = true;
                            break;
                        }

                        case CADASTRAR: {
                            if (cadastrarDisciplina(qtdDisciplinas, disciplinas, MAXDISCIPLINAS, professores, qtdProfessores)) {
                                qtdDisciplinas++;
                                printf("Disciplina cadastrada com sucesso!\n");
                            }
                            else
                                printf("Cadastro não realizado!\n");
                            break;
                        }

                        case LISTAR: {
                            if (qtdDisciplinas == 0) {
                                printf("Não há disciplinas cadastrados!\n");
                                break;
                            }

                            listarDisciplinas(qtdDisciplinas, disciplinas);
                            break;
                        }

                        case ATUALIZAR: {
                            if (atualizarDisciplina(qtdDisciplinas, disciplinas, qtdProfessores, professores))
                                printf("Disciplina atualizada com sucesso!\n");
                            else
                                printf("Atualização não realizada!\n");
                            break;
                        }

                        case EXCLUIR: {
                            if (excluirDisciplina(qtdDisciplinas, disciplinas)) {
                                printf("Disciplina excluída com sucesso!\n");
                                qtdDisciplinas--;
                            }
                            else
                                printf("Exclusão não realizada!\n");

                            break;
                        }

                        case 5 /*Pessoas matriculadas*/: {

                            int opcao;
                            int sairMatriculados = false;

                            while (!sairMatriculados){

                                opcao = obtemOpcaoMatriculados ();

                                switch (opcao){

                                    case 0: /*Voltar*/ {
                                        sairMatriculados = true;
                                        break;
                                    }

                                    case 1: /*Matricular aluno*/ {
                                        int matriculado = matricularAlunoDisciplina (disciplinas, qtdDisciplinas, alunos, qtdAlunos, qtdAlunosMatriculados);
                                        if (matriculado) {
                                            qtdAlunosMatriculados++;
                                            printf("Aluno cadastrado com sucesso!\n");
                                        }
                                        else
                                            printf("Cadastro não realizado!\n");
                                        break;
                                    }

                                    case 2: /*Excluir aluno*/ {
                                        int excluido = excluirAlunoDisciplina(disciplinas, qtdDisciplinas, alunos, qtdAlunos, qtdAlunosMatriculados);
                                        if (excluido) {
                                            printf("Aluno excluído com sucesso!\n");
                                        }
                                        else
                                            printf("Operação não realizada!\n");
                                        break;
                                    }

                                    case 3: /*Matrículas*/ {
                                        
                                        int opcaoListar;
                                        int sairListarMatriculados = false;

                                        while (!sairListarMatriculados){

                                            opcaoListar = obtemOpcaoListarMatriculados ();

                                            switch (opcaoListar){

                                                case 0: /*Voltar*/ {
                                                    sairListarMatriculados = true;
                                                    break;
                                                }
                                                
                                                case 1: /*Listar uma disciplina*/ {
                                                    listarDisciplinaAlunos (qtdDisciplinas, disciplinas);
                                                    break;
                                                }

                                                case 2: /*Lista de alunos matriculados em menos de 3 disciplinas*/{
                                                    listarAlunosMenosDeTresDisciplinas(qtdDisciplinas, disciplinas, alunos, qtdAlunos);
                                                    break;
                                                }

                                                case 3: /*Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas*/{
                                                    listarDisciplinasExtrapolandoVagas(qtdDisciplinas, disciplinas);
                                                    break;
                                                }

                                                default:
                                                    printf ("Opção inválida!");
                                                    break;
                                            }
                                        }
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