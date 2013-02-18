#ifndef ROTINASBD_H
#define	ROTINASBD_H
#include "../../LogicaNegocio/Headers/classeMedico.h"
#include "../../LogicaNegocio/Headers/classePaciente.h"
#include "../../LogicaNegocio/Headers/classeConsulta.h"
#include "BancoDados.h"
#include <string>

class Rotinas{
public:
    /**
    * @brief Persiste um objeto Medico.
    * @param Objeto Medico.
    */
    void insere_medico(Medico *);
    /**
    * @brief Faz uma busca de um m�dico no Banco de Dados usando nome como chave.
    * @param String contendo o nome do m�dico.
    * @return Lista de string.
    */
    list<string> busca_medico(string nome);
    /**
    * @brief Faz uma busca de um m�dico no Banco de Dados usando especialidade como chave.
    * @param String contendo a especialidade do m�dico.
    * @return Lista de string.
    */
    list<string> busca_especialidade(string especialidade);
    /**
    * @brief Deleta um m�dico do banco de dados.
    * @param String contendo o nome do m�dico.
    */
    int deleta_medico(string nome);
    /**
    * @brief Retorna uma lista de todos os medicos que est�o no Banco de Dados.
    * @return Lista de string.
    */
    list<string> lista_medicos();
    /**
    * @brief Persiste um objeto Paciente.
    * @param Objeto Paciente.
    */
    void insere_paciente(Paciente *);
    /**
    * @brief Faz uma busca de um paciente no Banco de Dados usando nome como chave.
    * @param String contendo o nome do paciente.
    * @return Lista de string.
    */
    list<string> busca_paciente(string nome);
    /**
    * @brief Deleta um paciente do banco de dados.
    * @param String contendo o nome do paciente.
    */
    int deleta_paciente(string nome);
    /**
    * @brief Retorna uma lista de todos os pacientes que est�o no Banco de Dados.
    * @return Lista de string.
    */
    list<string> lista_pacientes();
    /**
    * @brief Persiste um objeto Consulta.
    * @param Objeto Consulta.
    */
    void insere_consulta(Consulta *);
    /**
    * @brief Faz uma busca de uma consulta no Banco de Dados usando nome do paciente e do m�dico como chave.
    * @param 1 - String contendo o nome do paciente.
    * @param 2 - String contendo o nome do m�dico.
    * @return Lista de string.
    */
    list<string> busca_consulta(string nomePaciente, string nomeMedico);
    /**
    * @brief Deleta uma consulta do banco de dados.
    * @param 1 - String contendo o nome do paciente.
    * @param 2 - String contendo o nome do m�dico.
    */
    void deleta_consulta(string nomePaciente, string nomeMedico);
    /**
    * @brief Retorna uma lista de todas as consultas que est�o no Banco de Dados.
    * @return Lista de string.
    */
    list<string> lista_consultas();
    /**
    * @brief Faz uma busca de todos os pacientes que est�o em consulta com determinado m�dico.
    * @param String contendo nome do m�dico.
    * @return Lista de string.
    */
    list<string> busca_pacientes_de_um_medico(string nomeMedico);
    /**
    * @brief Faz uma busca de todos os medicos que est�o em consulta com determinado paciente.
    * @param String contendo nome do paciente.
    * @return Lista de string.
    */
    list<string> busca_medicos_de_um_paciente(string nomePaciente);
    /**
    * @brief Faz uma busca de todas as consultas na qual o paciente est� cadastrado.
    * @param String contendo nome do paciente.
    * @return Lista de string.
    */
    list<string> busca_consultas_paciente(string nomePaciente);
    /**
    * @brief Faz uma busca de todas as consultas na qual o m�dico est� cadastrado.
    * @param String contendo nome do m�dico.
    * @return Lista de string.
    */
    list<string> busca_consultas_medico(string nomeMedico);
};
#endif

