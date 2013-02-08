#ifndef PACIENTES_H
#define PACIENTES_H
#include <iostream>
#include "classePessoa.h"
using namespace std;

class PacienteExcecao : public exception {
public:
const char* what() const throw() {
    return "ERRO:PACIENTE EXCESSAO";
}
};

class Paciente : public Pessoa {
private:
    string m_endereco;
    string m_telefone;
    int m_idade;
    int m_estado;
public:
    void cadastra_pessoa() throw(PacienteExcecao);
    void descadastra_pessoa(char*) throw(PacienteExcecao);
    void altera_cadastro(Paciente *) throw(PacienteExcecao);
    int procura_pessoa(char *);
};
#endif
