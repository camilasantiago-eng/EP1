#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
using namespace std;
class Professor
{
private:
    string nome;
    string unidade;
    int nusp;

public:
    Professor(int nusp, string nome, string unidade);
    virtual ~Professor();
    string getNome();
    int getNusp();
    string getUnidade();
 };
#endif