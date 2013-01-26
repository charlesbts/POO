#ifndef MEDICOS_H
#define MEDICOS_H
#include <iostream>
#include <exception>
#include "classePessoa.h"
using namespace std;

class MedicoExcecao : public exception {
public:
const char* what() const throw() {
    return "ERRO:MEDICO EXCESSAO";
}
};

class Medico : public Pessoa {
public:
    string m_especialidade;
public:
    Medico(string ,string );
    void cadastra_medico(string ,string ); //throw (MedicoExcecao);
  //  void descadastra_pessoa(char*) throw(MedicoExcecao);
    //void altera_cadastro(Medico *) throw (MedicoExcecao);
    vector<vector<string> > procura_pessoa(string nome);
    ~Medico();
};
#endif

