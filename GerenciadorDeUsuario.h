#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H
#include <iostream>
#include "Aluno.h"
#include "Professor.h"
using namespace std;

class GerenciadorDeUsuario{

    private:
    Aluno **alunos;
    Professor **professores;
    int maximo;
    int quantidadeDeAlunos;
    int quantidadeDeProfessores;

 public:

GerenciadorDeUsuario(int maximo); 
virtual ~GerenciadorDeUsuario(); 
bool adicionarAluno(Aluno* a); 
bool adicionarProfessor(Professor* a); 
Aluno* getAluno(int nusp); 
Professor* getProfessor(int nusp); 
Aluno** getAlunos(int& quantidade); 
Professor** getProfessores(int& quantidade);
};
#endif
