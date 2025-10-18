#include "Bolsa.h"
#include "Aluno.h"
#include "Data.h"
#include "Professor.h"
#include "GerenciadorDeUsuario.h"
#include <iostream>
using namespace std;

const int MAX_USUARIOS = 10;


void menu()
{
    GerenciadorDeUsuario gerenciador(MAX_USUARIOS);
    int opcao = -1;

    while (opcao != 0)
    {
        cout << endl << "Gestao de bolsas USP " << endl;
        cout << "1) Adicionar aluno " << endl;
        cout << "2) Adicionar professor " << endl;
        cout << "3) Cadastrar bolsa " << endl;
        cout << "4) Consultar usuario " << endl;
        cout << "0) Sair " << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1)
        {
            cout << endl << "Cadastro de Aluno " << endl;
            int nusp;
            string nome;
            cout << "Digite o NUSP: ";
            cin >> nusp;
            cout << "Digite o nome: ";
            cin >> nome;

            Aluno *a = new Aluno(nusp, nome, MAX_USUARIOS);
            if (gerenciador.adicionarAluno(a))
                cout << "Aluno adicionado com sucesso " << endl;
        }
        else if (opcao == 2)
        {
            cout << endl << "Cadastro de Professor " << endl;
            int nusp;
            string nome, unidade;
            cout << "Digite o NUSP: ";
            cin >> nusp;
            cout << "Digite o nome: ";
            cin >> nome;
            cout << "Digite a unidade: ";
            cin >> unidade;
            Professor *p = new Professor(nusp, nome, unidade);
            if (gerenciador.adicionarProfessor(p))
                cout << "Professor adicionado com sucesso " << endl;
        }
        else if (opcao == 3)
        {
            cout << endl << "Cadastro de Bolsa " << endl;
            int nuspAluno, nuspProfessor;
            int mesInicio, anoInicio, mesFim, anoFim;

            cout << "Alunos " << endl;
            int qtdAlunos;
            Aluno **alunos = gerenciador.getAlunos(qtdAlunos);
            for (int i = 0; i < qtdAlunos; i++)
                cout << alunos[i]->getNusp() << " - " << alunos[i]->getNome() << " " << endl;

            cout << "Digite o NUSP do aluno: ";
            cin >> nuspAluno;
            Aluno *aluno = gerenciador.getAluno(nuspAluno);

            cout << endl << "Professores " << endl;
            int qtdProf;
            Professor **profs = gerenciador.getProfessores(qtdProf);
            for (int i = 0; i < qtdProf; i++)
                cout << profs[i]->getNusp() << " - " << profs[i]->getNome() << " - " << profs[i]->getUnidade() << " " << endl;

            cout << "Digite o NUSP do professor: ";
            cin >> nuspProfessor;
            Professor *prof = gerenciador.getProfessor(nuspProfessor);

            cout << "Digite o mes e ano de inicio: ";
            cin >> mesInicio >> anoInicio;
            cout << "Digite o mes e ano de fim: ";
            cin >> mesFim >> anoFim;

            Bolsa *bolsa = new Bolsa(new Data(mesInicio, anoInicio), new Data(mesFim, anoFim), prof);
            if (aluno->adicionar(bolsa))
                cout << "Bolsa cadastrada com sucesso " << endl;
            else
                cout << "Erro ao cadastrar bolsa " << endl;
        }
        else if (opcao == 4)
        {
            cout << endl << "Consulta de Usuario " << endl;
            cout << "Digite o NUSP: ";
            int nusp;
            cin >> nusp;

            Aluno *aluno = gerenciador.getAluno(nusp);
            Professor *prof = gerenciador.getProfessor(nusp);

            if (aluno != nullptr)
            {
                cout << "Aluno: " << aluno->getNome() << " " << endl;
                if (aluno->getQuantidadeDeBolsas() == 0)
                    cout << "Sem bolsas " << endl;
                else
                {
                    cout << "Bolsas: " << endl;
                    Bolsa **bolsas = aluno->getBolsas();
                    for (int i = 0; i < aluno->getQuantidadeDeBolsas(); i++)
                        cout << bolsas[i]->getInicio()->getMes() << "/" << bolsas[i]->getInicio()->getAno()
                             << " a " << bolsas[i]->getFim()->getMes() << "/" << bolsas[i]->getFim()->getAno()
                             << " - Orientador: " << bolsas[i]->getResponsavel()->getNome() << " " << endl;
                }
            }
            else if (prof != nullptr)
            {
                cout << "Professor: " << prof->getNome() << ", Unidade: " << prof->getUnidade() << " " << endl;
            }
        }
    }
}
