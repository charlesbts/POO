#ifndef PESSOAS_H
#define PESSOAS_H
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Pessoa {
public:
    string m_nome;
public:
    /**
    * @brief Faz um descadastramento de uma Pessoa.
    * @param String com o nome da Pessoa.
    * @return Sucesso ou Fracasso.
    */
    virtual bool descadastra_pessoa(string nome) =0;
    /**
    * @brief Faz uma prcocura de uma Pessoa.
    * @param String com o nome da Pessoa.
    * @return Lista de string.
    */
    virtual list<string> procura_pessoa(string nome) =0;
    /**
    * @brief Faz uma procura de todas as pessoas.
    * @return Lista de string.
    */
    virtual list<string> lista_pessoas() =0;
};
#endif
