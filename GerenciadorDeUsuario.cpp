#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "GerenciadorDeUsuario.h"
using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo){
    this->maximo = maximo;
    this->quantidadeDeAlunos = 0;
    this->quantidadeDeProfessores = 0;
    alunos = new Aluno*[maximo];
    professores = new Professor*[maximo];
}

GerenciadorDeUsuario::~GerenciadorDeUsuario(){
    for(int i = 0; i < quantidadeDeAlunos; ++i){
        delete alunos[i];
    }
    for(int i = 0; i < quantidadeDeProfessores; ++i){
        delete professores[i];
    }
    delete[] alunos;
    delete[] professores;
}

bool GerenciadorDeUsuario::adicionarAluno(Aluno* a){
    if (quantidadeDeAlunos >= maximo) return false;
    for (int i = 0; i < quantidadeDeAlunos; ++i){
        if (alunos[i]->getNusp() == a->getNusp()) return false;
    }
    for (int i = 0; i < quantidadeDeProfessores; ++i){
        if (professores[i]->getNusp() == a->getNusp()) return false;
    }
    alunos[quantidadeDeAlunos] = a;
    quantidadeDeAlunos++;
    return true;
}

bool GerenciadorDeUsuario::adicionarProfessor(Professor* a){
    if (quantidadeDeProfessores >= maximo) return false;
    for (int i = 0; i < quantidadeDeAlunos; ++i){
        if (alunos[i]->getNusp() == a->getNusp()) return false;
    }
    for (int i = 0; i < quantidadeDeProfessores; ++i){
        if (professores[i]->getNusp() == a->getNusp()) return false;
    }
    professores[quantidadeDeProfessores] = a;
    quantidadeDeProfessores++;
    return true;
}

Aluno* GerenciadorDeUsuario::getAluno(int nusp){
    for(int i = 0; i < quantidadeDeAlunos; ++i){
        if(alunos[i]->getNusp() == nusp){
            return alunos[i];
        }
    }
    return nullptr;
}

Professor* GerenciadorDeUsuario::getProfessor(int nusp){
    for(int i = 0; i < quantidadeDeProfessores; ++i){
        if(professores[i]->getNusp() == nusp){
            return professores[i];
        }
    }
    return nullptr;
}

Aluno** GerenciadorDeUsuario::getAlunos(int& quantidade){
    quantidade = quantidadeDeAlunos;
    return alunos;
}

Professor** GerenciadorDeUsuario::getProfessores(int& quantidade){
    quantidade = quantidadeDeProfessores;
    return professores;
}
