#ifndef CONSULTAS_H
#define CONSULTAS_H
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Consulta {
public:
    string m_paciente;
    string m_medico;
    string m_codigo;
public:
    /**
    * @brief Construtor.
    */
    Consulta();
    /**
    * @brief Construtor.
    * @param 1 - Nome do Paciente.
    * @param 2 - Nome do M�dico.
    */
    Consulta(string nomePaciente, string nomeMedico);
    /**
    * @brief Usa o Construtor para preencher um objeto Consulta.
    * @param 1 - Nome do Paciente.
    * @param 2 - Nome do M�dico.
    */
    bool marca_consulta(string nomePaciente, string nomeMedico);
    /**
    * @brief Faz uma procura de uma determinada consulta.
    * @param 1 - Nome do Paciente.
    * @param 2 - Nome do M�dico.
    */
    list<string> procura_consulta(string nomePaciente, string nomeMedico);
    /**
    * @brief Faz um cancelamento seguido de uma marca��o de uma determinada consulta.
    * @param 1 - Nome do Paciente.
    * @param 2 - Nome do M�dico.
    */
    bool remarca_consulta(string nomePaciente, string nomeMedico);
    /**
    * @brief Faz um cancelamento de uma determinada consulta.
    * @param 1 - Nome do Paciente.
    * @param 2 - Nome do M�dico.
    */
    bool cancela_consulta(string nomePaciente, string nomeMedico);
    /**
    * @brief Procura por todas as consultas.
    * @return Lista de string.
    */
    list<string> lista_consultas();
    /**
    * @brief Procura por todas os pacientes em consulta com um determinado m�dico.
    * @param String com o nome do m�dico.
    * @return Lista de string.
    */
    list<string> procura_pacientes_de_um_medico(string nomeMedico);
    /**
    * @brief Procura por todas os m�dicos em consulta com um determinado paciente.
    * @param String com o nome do paciente.
    * @return Lista de string.
    */
    list<string> procura_medicos_de_um_paciente(string nomePaciente);
    /**
    * @brief Procura por todas as consultas de um determinado paciente.
    * @param String com o nome do paciente.
    * @return Lista de string.
    */
    list<string> procura_consultas_paciente(string nomePaciente);
    /**
    * @brief Procura por todas as consultas de um determinado m�dico.
    * @param String com o nome do m�dico.
    * @return Lista de string.
    */
    list<string> procura_consultas_medico(string nomeMedico);
    /**
    * @brief Gera o c�digo da consulta.
    */
    void gera_codigo();
    /**
    * @brief Destrutor.
    */
    ~Consulta();
};
#endif
