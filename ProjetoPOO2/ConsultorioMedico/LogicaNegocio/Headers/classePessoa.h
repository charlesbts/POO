#ifndef PESSOAS_H
#define PESSOAS_H
#include <iostream>
#include <vector>
using namespace std;

class Pessoa {
public:
    string m_nome;
public:
    //virtual void cadastra_pessoa() =0;
    //virtual void descadastra_pessoa(char *) =0;
    //virtual void altera_cadastro(Pessoa *) =0;
    virtual vector<vector<string> > procura_pessoa(string nome) =0;
};
#endif

