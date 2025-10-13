#ifndef DATA_H
#define DATA_H

class Data
{
private:
    int mes;
    int ano;

public:
    Data(int mes, int ano);
    virtual ~Data();
    int getMes();
    int getAno();
};
#endif