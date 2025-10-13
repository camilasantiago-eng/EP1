#include "Bolsa.h"
#include "Aluno.h"
#include "Data.h"
#include "Professor.h"
#include "GerenciadorDeUsuario.h"
#include <iostream>
using namespace std;

const int MAX_USUARIOS = 10;

void MenuInicial()
{
    GerenciadorDeUsuario gerenciador(MAX_USUARIOS);
    int opcao = -1;

    while (opcao != 0) {
        cout << "Gestao de bolsas USP" << endl;
        cout << "1) Adicionar aluno " << endl;
        cout << "2) Adicionar professor" << endl;
        cout << "3) Cadastrar bolsa" << endl;
        cout << "4) Consultar usuario" << endl;
        cout << "0) Sair " << endl;
        cout << "Escolha uma opcao:";
        cin >> opcao;

        if (opcao == 1) {
            int nusp;
            string nome;
            cout << "Cadastro de aluno" << endl;
            cout << "Digite o NUSP:";
            cin >> nusp;
            cout << "Digite o nome:";
            cin >> nome;
            Aluno *a = new Aluno(nusp, nome, MAX_USUARIOS);
            bool verifica = gerenciador.adicionarAluno(a);
            if (verifica)
                cout << endl << "Aluno adicionado com sucesso" << endl;
            else
                cout << endl << "Erro ao adicionar aluno" << endl;
        }
        else if (opcao == 2) {
            int nusp;
            string nomeProfessor, unidade;
            cout << "Cadastro de professor" << endl << "Digite o NUSP:";
            cin >> nusp;
            cout << "Digite o nome:";
            cin >> nomeProfessor;
            cout << "Digite a unidade:";
            cin >> unidade;
            Professor *professor = new Professor(nusp, nomeProfessor, unidade);
            bool verifica = gerenciador.adicionarProfessor(professor);
            if (verifica)
                cout << "Professor adicionado com sucesso" << endl;
            else {
                cout << "Erro ao adicionar professor" << endl;
                delete professor;
            }
        }
        else if (opcao == 3) {
            int nuspAluno, nuspProfessor;
            bool alunoExiste = false, professorExiste = false;
            cout << "Cadastro de bolsa" << endl;
            cout << "Alunos" << endl;
            for (int i = 0; i < MAX_USUARIOS; i++) {
                Aluno* aluno = gerenciador.getAluno(nuspAluno);
                if (aluno != nullptr) {
                    cout << aluno->getNusp() << "-" << aluno->getNome() << endl;
                }
            }
            cout << "Digite o NUSP do aluno:";
            cin >> nuspAluno;
            for (int i = 0; i < MAX_USUARIOS; i++) {
                Aluno* aluno = gerenciador.getAluno(nuspAluno);
                if (aluno != nullptr && aluno->getNusp() == nuspAluno) {
                    alunoExiste = true;
                    break;
                }
            }
            if (!alunoExiste) {
                cout << "Aluno inexistente" << endl;
            } else {
                cout << "Professores" << endl;
                for (int j = 0; j < MAX_USUARIOS; j++) {
                    Professor* prof = gerenciador.getProfessor(nuspProfessor);
                    if (prof != nullptr) {
                        cout << prof->getNusp() << "-" << prof->getNome() << endl;
                    }
                }
                cout << "Digite o NUSP do professor:";
                cin >> nuspProfessor;
                for (int j = 0; j < MAX_USUARIOS; j++) {
                    Professor* prof = gerenciador.getProfessor(nuspProfessor);
                    if (prof != nullptr && prof->getNusp() == nuspProfessor) {
                        professorExiste = true;
                        break;
                    }
                }
                if (!professorExiste) {
                    cout << "Professor inexistente" << endl;
                } else {
                    int mesInicio, anoInicio, mesFim, anoFim;
                    cout << "Digite o mes e ano de inicio:";
                    cin >> mesInicio >> anoInicio;
                    cout << "Digite o mes e ano de fim :";
                    cin >> mesFim >> anoFim;
                    Data *inicio = new Data(mesInicio, anoInicio);
                    Data *fim = new Data(mesFim, anoFim);
                    Professor *professor = gerenciador.getProfessor(nuspProfessor);
                    Bolsa *bolsa = new Bolsa(inicio, fim, professor);
                    Aluno *aluno = gerenciador.getAluno(nuspAluno);
                    bool verifica = aluno->adicionar(bolsa);
                    if (verifica)
                        cout << "Bolsa adicionada com sucesso" << endl;
                    else {
                        cout << "Erro ao adicionar bolsa" << endl;
                        delete bolsa;
                        delete inicio;
                        delete fim;
                    }
                }
            }
        }
        else if (opcao == 4) {
            cout << endl << "Consulta de Usuario" << endl << endl;
            cout << "Digite o NUSP: ";
            int nusp;
            cin >> nusp;
            cout << endl;
            Aluno *a = gerenciador.getAluno(nusp);
            if (a != nullptr) {
                cout << "Aluno: " << a->getNome() << endl;
                int quantidadeDeBolsas = a->getQuantidadeDeBolsas();
                if (quantidadeDeBolsas == 0) {
                    cout << "Sem bolsas" << endl;
                } else {
                    cout << "Bolsas: " << endl;
                    Bolsa **vetorbolsas = a->getBolsas();
                    for (int i = 0; i < quantidadeDeBolsas; i++) {
                        Data *inicio = vetorbolsas[i]->getInicio();
                        Data *fim = vetorbolsas[i]->getFim();
                        Professor *professor = vetorbolsas[i]->getResponsavel();
                        cout << inicio->getMes() << "/" << inicio->getAno()
                             << " a " << fim->getMes() << "/" << fim->getAno()
                             << " - Orientador: " << professor->getNome() << endl;
                    }
                }
            } else {
                Professor *professor = gerenciador.getProfessor(nusp);
                if (professor != nullptr) {
                    cout << "Professor: " << professor->getNome() << ", Unidade: "
                         << professor->getUnidade() << endl;
                } else {
                    cout << "Usuario nao encontrado" << endl;
                }
            }
        }
    }
}