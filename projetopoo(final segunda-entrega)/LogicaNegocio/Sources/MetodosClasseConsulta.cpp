#define CONSULTA_IMPL
#include "../Headers/classeConsulta.h"
#include "../../BancoDados/Headers/rotinasBD.h"

/*Construtor que nao recebe argumentos*/
Consulta::Consulta(){

}
/*Construtor que preenche o objeto*/
Consulta::Consulta(string nomePaciente, string nomeMedico){

    this->m_paciente = nomePaciente;
    this->m_medico = nomeMedico;
    this->gera_codigo();
}
/*gera uma data pra consulta*/
void Consulta::gera_codigo(){
time_t data;

        time (&data);
        this->m_codigo = ctime(&data);
}
/*Recebe os dados vindos da Inferface faz a procura pra ver se ja existem consultas, caso nao existam
 efetua a marcacao e retonra um valor booleano verdadeiro,caso contrario retorna um valor booleano falso
  para interpretacao na logica*/
bool Consulta::marca_consulta(string nomePaciente, string nomeMedico){
Rotinas *bd;

    if(this->procura_consulta(nomePaciente, nomeMedico).empty()){
    Consulta *consulta = new Consulta(nomePaciente, nomeMedico);
    bd->insere_consulta(consulta);
    return true;
    }
    else
    return false;
}
/*recebe os dados da Interface e procura uma determinada consulta se existir retorna os dados dela. */
list<string> Consulta::procura_consulta(string nomePaciente, string nomeMedico){
Rotinas *bd;

    return bd->busca_consulta(nomePaciente, nomeMedico);
}
/*Recebe os dados da Interface, e verifica a existencia da consulta, se existir , desmarca a consulta e 
 retonra verdadeiro, se nao existir a consulta, retorna falso*/
bool Consulta::cancela_consulta(string nomePaciente, string nomeMedico){
Rotinas *bd;

    if(!(this->procura_consulta(nomePaciente, nomeMedico).empty())){
    bd->deleta_consulta(nomePaciente, nomeMedico);
    return true;
    }
    else
    return false;
}
/*Recebe os dados da IU, verifica se existem consultas, se existir, cancela, e depois a marca novamente*/
bool Consulta::remarca_consulta(string nomePaciente, string nomeMedico){
Rotinas *bd;

    if(this->cancela_consulta(nomePaciente, nomeMedico)){
    this->marca_consulta(nomePaciente, nomeMedico);
    return true;
    }
    else
    return false;
}
/*Retorna para interface a lista de consultas*/
list<string> Consulta::lista_consultas(){
Rotinas *bd;

    return bd->lista_consultas();
}
/*retorna para a interface os pacientes de um medico*/
list<string> Consulta::procura_pacientes_de_um_medico(string nomeMedico){
Rotinas *bd;

    return bd->busca_pacientes_de_um_medico(nomeMedico);
}
/*retorna para a interface uma lista com todas as consultas de um paciente*/
list<string> Consulta::procura_medicos_de_um_paciente(string nomePaciente){
Rotinas *bd;

    return bd->busca_medicos_de_um_paciente(nomePaciente);
}
/*busca todas as consultas de um determinado paciente*/
list<string> Consulta::procura_consultas_paciente(string nomePaciente){
Rotinas *bd;

    return bd->busca_consultas_paciente(nomePaciente);
}
/*procura as consultas de um determinado medico*/
list<string> Consulta::procura_consultas_medico(string nomeMedico){
Rotinas *bd;

    return bd->busca_consultas_medico(nomeMedico);
}
