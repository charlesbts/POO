#ifndef PACIENTES_H
#define PACIENTES_H
#include <iostream>
#include "classePessoa.h"
using namespace std;

/*class PacienteExcecao : public exception {
public:
const char* what() const throw() {
    return "ERRO:PACIENTE EXCESSAO";
}
}; */

class Paciente : public Pessoa {
public:
    string m_endereco;
    string m_telefone;
    string m_idade;
public:
    /**
    * @brief Construtor.
    */
    Paciente();
    /**
    * @brief Construtor.
    * @param 1 - Nome do Paciente.
    * @param 2 - Endereço do Paciente.
    * @param 3 - Telefone do Paciente.
    * @param 4 - Idade do Paciente.
    */
    Paciente(string nomePaciente, string endereco, string telefone, string idade);
    /**
    * @brief Utiliza o construtor para preencher um objeto do tipo Paciente.
    * @param 1 - Nome do Paciente.
    * @param 2 - Endereço do Paciente.
    * @param 3 - Telefone do Paciente.
    * @param 4 - Idade do Paciente.
    */
    bool cadastra_paciente(string nomePaciente, string endereco, string telefone, string idade);// throw(PacienteExcecao);
    /**
    * @brief Faz um descadastramento de um Paciente.
    * @param String com o nome do Paciente.
    * @return Sucesso ou Fracasso.
    */
    bool descadastra_pessoa(string nome); //throw(PacienteExcecao);
    /**
    * @brief Faz um descadastramento seguido de um cadastro com os novos dados.
    * @param 1 - Nome do Paciente.
    * @param 2 - Novo Nome do Paciente.
    * @param 3 - Novo Endereço do Paciente.
    * @param 4 - Novo Telefone do Paciente.
    * @param 5 - Nova Idade do Paciente.
    */
    bool altera_cadastro(string nomePaciente, string novoNomePaciente, string novoEndereco, string novoTelefone, string novaIdade); //throw(PacienteExcecao);
    /**
    * @brief Faz uma procura de um Paciente.
    * @param String com o nome de um Paciente.
    * @return Lista de string.
    */
    list<string> procura_pessoa(string nome);
    /**
    * @brief Faz uma procura de todos os pacientes.
    * @return Lista de string.
    */
    list<string> lista_pessoas();
    /**
    * @brief Destrutor.
    */
    ~Paciente();
};
#endif
