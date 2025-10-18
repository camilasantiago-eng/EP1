#include "Bolsa.h"
#define BOLSA_USP 700.0
Bolsa::Bolsa(Data *inicio, Data *fim, Professor *responsavel)
{
    this->inicio = inicio;
    this->fim = fim;
    this->responsavel = responsavel;
}
Bolsa::~Bolsa(){
    delete inicio;
    delete fim;
    delete responsavel;
}

    
Data *Bolsa::getInicio()
{
    return inicio;
}
Data *Bolsa::getFim()
{
    return fim;
}
Professor *Bolsa::getResponsavel()
{
    return responsavel;
}

bool Bolsa::estaDentroDoPeriodo(Data *d) {
    int mes_inicio = inicio->getAno() * 12 + (inicio->getMes() - 1);
    int mes_fim =  fim->getAno() * 12 + (fim->getMes() - 1);
    int mes_atual =  d->getAno() * 12 + (d->getMes() - 1);
    
    if (mes_atual >= mes_inicio && mes_atual <= mes_fim)
        return true;
    return false;
}
double Bolsa::getValor(Data *data)
{
    if (estaDentroDoPeriodo(data) == true)
        return BOLSA_USP;
    return 0;
}