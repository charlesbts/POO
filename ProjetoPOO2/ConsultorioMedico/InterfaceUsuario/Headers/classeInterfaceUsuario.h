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
    void menu_usuario();
    void opcao_usuario();
    void cadastra_medico();
    void descadastra_medico();
    void atualiza_medico();
    void procura_medico();
    void lista_consultas_marcadas();
    void lista_medicos_cadastrados();
    void lista_pacientes_cadastrados();
    void lista_pacientes_de_um_medico();
    void lista_pacientes_de_todos_medicos();
    void lista_medicos_de_um_paciente();
    void lista_medicos_de_todos_pacientes();
    void lista_consultas_de_um_paciente();
    void lista_consultas_de_um_medico();
    void lista_pacientes_sem_medico();
    void lista_medicos_sem_paciente();
    void sair_do_sistema();
};
#endif
