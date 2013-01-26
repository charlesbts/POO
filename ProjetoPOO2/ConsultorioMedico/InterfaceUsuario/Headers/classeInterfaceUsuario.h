#ifndef INTERFACEUSUARIO_H
#define INTERFACEUSUARIO_H
#include <iostream>
using namespace std;

class InterfaceUsuario {
public:
    void cadastra_medico();
    void procura_pessoa();
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
