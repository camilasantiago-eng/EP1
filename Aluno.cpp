#include <iostream>
using namespace std;
#include "Bolsa.h"
#include "Aluno.h"
#include "Data.h"

Aluno::Aluno(int nusp, string nome, int maximo): nusp(nusp), nome(nome), maximo(maximo)
{
    quantidadeDeBolsas = 0;
    bolsa = new Bolsa*[maximo];
}

Aluno::~Aluno()
{
    for(int i = 0; i < quantidadeDeBolsas; ++i)
    {
        delete bolsa[i];
    }
    delete[] bolsa;
}

string Aluno::getNome()
{
    return nome;
}

int Aluno::getNusp()
{
    return nusp;
}

int Aluno::converterParaMes(Data *data)
{
    return data->getAno() * 12 + (data->getMes() - 1);
}

bool Aluno::temConflitoDeBolsas(Data *inicio1, Data *fim1, Data *inicio2, Data *fim2)
{
    int in1 = converterParaMes(inicio1);
    int f1 = converterParaMes(fim1);
    int in2 = converterParaMes(inicio2);
    int f2 = converterParaMes(fim2);

    if (f1 < in2 || f2 < in1) return false;
    return true;
}

bool Aluno::adicionar(Bolsa *bolsa)
{
    if (quantidadeDeBolsas >= maximo)
    {
        return false;
    }

    Data *novoInicio = bolsa->getInicio();
    Data *novoFim = bolsa->getFim();

    for (int i = 0; i < quantidadeDeBolsas; ++i)
    {
        if (temConflitoDeBolsas(novoInicio, novoFim, this->bolsa[i]->getInicio(), this->bolsa[i]->getFim()))
        {
            return false;
        }
    }

    this->bolsa[quantidadeDeBolsas] = bolsa;
    quantidadeDeBolsas++;
    return true;
}

Bolsa **Aluno::getBolsas()
{
    return bolsa;
}

int Aluno::getQuantidadeDeBolsas()
{
    return quantidadeDeBolsas;
}

double Aluno::getValor(Data *data)
{
    double soma = 0.0;
    for (int i = 0; i < quantidadeDeBolsas; ++i)
    {
        soma += bolsa[i]->getValor(data);
    }
    return soma;
}
