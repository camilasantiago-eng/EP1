#include "Data.h"

Data::Data(int mes, int ano)
{
    this->mes = mes;
    this->ano = ano;
}
Data::~Data() {}
int Data::getAno()
{
    return ano;
}

int Data::getMes(){
    return mes;
}