#ifndef MEDICOS_H
#define MEDICOS_H
#include <iostream>
#include <exception>
#include "classePessoa.h"
#include "../../BancoDados/Headers/BancoDados.h"
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
    Medico(string nomeMedico,string especialidade);
    bool cadastra_medico(string nomeMedico ,string especialidade); //throw (MedicoExcecao);
    bool descadastra_pessoa(string nomeMedico); //throw(MedicoExcecao);
    bool altera_cadastro(string nomeMedico, string novoNomeMedico, string especialidade); //throw (MedicoExcecao);
    list<string> procura_pessoa(string nome);
    ~Medico();
};
#endif

