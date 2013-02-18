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
    * @brief Apresenta o menu principal ao usuário.
    */
    void menu_usuario();
    /**
    * @brief Chama determinado método da IU de acordo com a opção do usuário.
    */
    void opcao_usuario();
    /**
    * @brief Recebe informações do usuário para fazer o cadastro do médico.
    */
    void cadastra_medico();
    /**
    * @brief Recebe informações do usuário para fazer o descadastro do médico.
    */
    void descadastra_medico();
    /**
    * @brief Recebe informações do usuário para fazer a atualização do cadastro do médico.
    */
    void atualiza_medico();
    /**
    * @brief Recebe informações do usuário para fazer uma busca pelo cadastro do médico.
    */
    void procura_medico();
    /**
    * @brief Recebe informações do usuário para fazer o cadastro do paciente.
    */
    void cadastra_paciente();
    /**
    * @brief Recebe informações do usuário para fazer o descadastro do paciente.
    */
    void descadastra_paciente();
    /**
    * @brief Recebe informações do usuário para fazer a atualização do cadastro do paciente.
    */
    void atualiza_paciente();
    /**
    * @brief Recebe informações do usuário para fazer uma busca pelo cadastro do paciente.
    */
    void procura_paciente();
    /**
    * @brief Recebe informações do usuário para marcar uma consulta.
    */
    void marca_consulta();
    /**
    * @brief Recebe informações do usuário para procurar uma consulta.
    */
    void procura_consulta();
    /**
    * @brief Recebe informações do usuário para desmarcar uma consulta.
    */
    void desmarca_consulta();
    /**
    * @brief Recebe informações do usuário para remarcar uma consulta.
    */
    void remarcar_consulta();
    /**
    * @brief Lista todas as consultas marcadas.
    */
    void lista_consultas_marcadas();
    /**
    * @brief Lista todos os médicos cadastrados.
    */
    void lista_medicos_cadastrados();
    /**
    * @brief Lista todos os pacientes cadastrados.
    */
    void lista_pacientes_cadastrados();
    /**
    * @brief Lista todos os pacientes em consulta com determinado médico.
    */
    void lista_pacientes_de_um_medico();
    /**
    * @brief Lista todos os pacientes em consulta com todos os médicos.
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
    * @brief Lista todas as consultas de um determinado médico.
    */
    void lista_consultas_de_um_medico();
    /**
    * @brief Lista todos os pacientes que não possuem consulta marcada.
    */
    void lista_pacientes_sem_medico();
    /**
    * @brief Lista todos os médicos que não possuem consulta marcada.
    */
    void lista_medicos_sem_paciente();
};
#endif
