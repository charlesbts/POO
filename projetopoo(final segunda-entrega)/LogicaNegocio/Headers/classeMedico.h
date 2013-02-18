#ifndef MEDICOS_H
#define MEDICOS_H
#include <iostream>
#include <exception>
#include "classePessoa.h"
#include "../../BancoDados/Headers/BancoDados.h"
using namespace std;

/*class MedicoExcecao : public exception {
private:
    string excecao;
public:
    void erro_logica_negocio() {
    return this->excecao;
}
};*/

class Medico : public Pessoa {
public:
    string m_especialidade;
public:
    /**
    * @brief Construtor.
    */
    Medico();
    /**
    * @brief Construtor.
    * @param 1 - Nome do M�dico.
    * @param 2 - Especialidade do M�dico.
    */
    Medico(string nomeMedico, string especialidade);
    /**
    * @brief Utiliza o construtor para preencher um objeto do tipo M�dico.
    * @param 1 - Nome do M�dico.
    * @param 2 - Especialidade do M�dico.
    */
    bool cadastra_medico(string nomeMedico, string especialidade); //throw (MedicoExcecao);
    /**
    * @brief Faz um descadastramento de um M�dico.
    * @param String com o nome do M�dico.
    * @return Sucesso ou Fracasso.
    */
    bool descadastra_pessoa(string nomeMedico); //throw(MedicoExcecao);
    /**
    * @brief Faz um descadastramento seguido de um cadastro com os novos dados.
    * @param 1 - Nome do M�dico.
    * @param 2 - Novo Nome do M�dico.
    * @param 3 - Nova Especialidade do M�dico.
    */
    bool altera_cadastro(string nomeMedico, string novoNomeMedico, string especialidade); //throw (MedicoExcecao);
    /**
    * @brief Faz uma procura de um M�dico.
    * @param String com o nome de um M�dico.
    * @return Lista de string.
    */
    list<string> procura_pessoa(string nome);
    /**
    * @brief Faz uma procura de um m�dico usando especialidade como chave.
    * @param String com a especialidade.
    * @return Lista de string.
    */
    list<string> procura_especialidade(string especialidade);
    /**
    * @brief Faz uma procura de todos os m�dicos.
    * @return Lista de string.
    */
    list<string> lista_pessoas();
    /**
    * @brief Destrutor.
    */
    ~Medico();
};
#endif

