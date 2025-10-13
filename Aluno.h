#ifndef ALUNO_H
#define ALUNO_H
#include <iostream>
#include "Bolsa.h"
using namespace std;

class Aluno
{
    private:
    int nusp;
    int maximo;
    string nome;

    Bolsa **bolsa;
    int quantidadeDeBolsas;

    int converterParaMes(Data *d);

    public:
    Aluno(int nusp, string nome, int maximo);
    virtual ~Aluno();
    string getNome();
    int getNusp();
    bool temConflitoDeBolsas(Data *inicio1, Data *fim1, Data *inicio2, Data *fim2);
    bool adicionar(Bolsa *bolsa);
    Bolsa **getBolsas();
    int getQuantidadeDeBolsas();
    double getValor(Data *data);
};

#endif
