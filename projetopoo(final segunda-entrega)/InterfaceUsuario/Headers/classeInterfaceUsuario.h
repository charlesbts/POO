#ifndef INTERFACEUSUARIO_H
#define INTERFACEUSUARIO_H
#include "../../LogicaNegocio/Headers/classeMedico.h"
#include "../../LogicaNegocio/Headers/classeConsulta.h"
#include "../../LogicaNegocio/Headers/classePaciente.h"
#include "../../LogicaNegocio/Headers/classePessoa.h"
#define TAM_LINHA 50
#include <iostream>
#include <cstdlib>
using namespace std;

class InterfaceUsuario {
public:
    /**
    * @brief Apresenta o menu principal ao usu�rio.
    */
    void menu_usuario();
    /**
    * @brief Chama determinado m�todo da IU de acordo com a op��o do usu�rio.
    */
    void opcao_usuario();
    /**
    * @brief Recebe informa��es do usu�rio para fazer o cadastro do m�dico.
    */
    void cadastra_medico();
    /**
    * @brief Recebe informa��es do usu�rio para fazer o descadastro do m�dico.
    */
    void descadastra_medico();
    /**
    * @brief Recebe informa��es do usu�rio para fazer a atualiza��o do cadastro do m�dico.
    */
    void atualiza_medico();
    /**
    * @brief Recebe informa��es do usu�rio para fazer uma busca pelo cadastro do m�dico.
    */
    void procura_medico();
    /**
    * @brief Recebe informa��es do usu�rio para fazer o cadastro do paciente.
    */
    void cadastra_paciente();
    /**
    * @brief Recebe informa��es do usu�rio para fazer o descadastro do paciente.
    */
    void descadastra_paciente();
    /**
    * @brief Recebe informa��es do usu�rio para fazer a atualiza��o do cadastro do paciente.
    */
    void atualiza_paciente();
    /**
    * @brief Recebe informa��es do usu�rio para fazer uma busca pelo cadastro do paciente.
    */
    void procura_paciente();
    /**
    * @brief Recebe informa��es do usu�rio para marcar uma consulta.
    */
    void marca_consulta();
    /**
    * @brief Recebe informa��es do usu�rio para procurar uma consulta.
    */
    void procura_consulta();
    /**
    * @brief Recebe informa��es do usu�rio para desmarcar uma consulta.
    */
    void desmarca_consulta();
    /**
    * @brief Recebe informa��es do usu�rio para remarcar uma consulta.
    */
    void remarcar_consulta();
    /**
    * @brief Lista todas as consultas marcadas.
    */
    void lista_consultas_marcadas();
    /**
    * @brief Lista todos os m�dicos cadastrados.
    */
    void lista_medicos_cadastrados();
    /**
    * @brief Lista todos os pacientes cadastrados.
    */
    void lista_pacientes_cadastrados();
    /**
    * @brief Lista todos os pacientes em consulta com determinado m�dico.
    */
    void lista_pacientes_de_um_medico();
    /**
    * @brief Lista todos os pacientes em consulta com todos os m�dicos.
    */
    void lista_pacientes_de_todos_medicos();
    /**
    * @brief Lista todos os medicos em consulta com determinado paciente.
    */
    void lista_medicos_de_um_paciente();
    /**
    * @brief Lista todos os medicos em consulta com todos os pacientes.
    */
    void lista_medicos_de_todos_pacientes();
    /**
    * @brief Lista todas as consultas de um determinado paciente.
    */
    void lista_consultas_de_um_paciente();
    /**
    * @brief Lista todas as consultas de um determinado m�dico.
    */
    void lista_consultas_de_um_medico();
    /**
    * @brief Lista todos os pacientes que n�o possuem consulta marcada.
    */
    void lista_pacientes_sem_medico();
    /**
    * @brief Lista todos os m�dicos que n�o possuem consulta marcada.
    */
    void lista_medicos_sem_paciente();
};
#endif
