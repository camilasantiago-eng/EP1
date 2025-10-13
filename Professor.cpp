#include "Professor.h"

Professor:: Professor(int nusp, string nome, string unidade){
    this-> nusp = nusp;
    this ->nome = nome;
    this->unidade = unidade;
    
}
Professor:: ~Professor(){}
string Professor:: getNome(){
    return nome;
}
string Professor:: getUnidade(){
    return unidade;
}
int Professor:: getNusp(){
    return nusp;
}