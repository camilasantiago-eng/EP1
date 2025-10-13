#include "Bolsa.h"
#define BOLSA_USP 700.0
Bolsa::Bolsa(Data *inicio, Data *fim, Professor *responsavel)
{
    this->inicio = inicio;
    this->fim = fim;
    this->responsavel = responsavel;
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
bool Bolsa::estaDentroDoPeriodo(Data *d)
{
    if (d->getMes() > inicio->getMes() && d->getAno() >= inicio->getAno() && d->getMes() < fim->getMes() && d->getAno() <= fim->getAno())
        return true;
    return false;
}
double Bolsa::getValor(Data *data)
{
    if (estaDentroDoPeriodo(data) == true)
        return BOLSA_USP;
    return 0;
}