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
    cout << "Cadastro de bolsa" << endl;
    
   
    cout << "Alunos" << endl;
    int num_alunos = 0;
    Aluno **lista_alunos = gerenciador.getAlunos(num_alunos);
    
    for (int i = 0; i < num_alunos; ++i) {
       cout << lista_alunos[i]->getNusp()<< " " << lista_alunos[i]->getNome() << endl;
    }
    cout << "Digite o NUSP do aluno:";
    int nuspAluno;
    cin >> nuspAluno;
    
    Aluno* aluno_alvo = gerenciador.getAluno(nuspAluno);
    if (aluno_alvo == nullptr) {
        cout << "Aluno inexistente" << endl;
        return; 
    
    }
    cout << "Professores" << endl;
    int num_professores = 0;
    Professor** lista_professores = gerenciador.getProfessores(num_professores);
    for(int i = 0; i < num_professores; ++i) {
        cout << lista_professores[i]->getNusp()<< " " << lista_professores[i]->getNome() << " " << lista_professores[i]->getUnidade() << endl;
    }
    
    cout << "Digite o NUSP do professor:";
    int nuspProfessor;
    cin >> nuspProfessor;
    
    Professor* professor_alvo = gerenciador.getProfessor(nuspProfessor);
    if (professor_alvo == nullptr) {
        cout << "Professor inexistente" << endl;
        return; 
    }
    
    // --- 3. OBTENÇÃO DAS DATAS E CRIAÇÃO DA BOLSA ---
    int mesInicio, anoInicio, mesFim, anoFim;
    cout << "Digite o mes e ano de inicio:";
    cin >> mesInicio >> anoInicio;
    cout << "Digite o mes e ano de fim:";
    cin >> mesFim >> anoFim;
    
    Data *inicio = new Data(mesInicio, anoInicio);
    Data *fim = new Data(mesFim, anoFim);
    
    Bolsa *nova_bolsa = new Bolsa(inicio, fim, professor_alvo);
    
 
    bool verifica = aluno_alvo->adicionar(nova_bolsa);
    
    if (verifica) {
        cout << "Bolsa cadastrada com sucesso" << endl;
    } else {
        cout << "Erro ao cadastrar bolsa" << endl;
       
        delete nova_bolsa;
      
        delete inicio;
        delete fim;
    }
}
         if (opcao == 4) {
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