#include <iostream>
#include "../Headers/classeMedico.h"
#include "../../BancoDados/Headers/rotinasBD.h"
#include <string>
/*Construtor Nulo*/
Medico::Medico(){
}
/*Construtor que instancia e preenche o objeto*/
Medico::Medico(string nome,string especialidade){

    this->m_especialidade = especialidade;
    this->m_nome = nome;
}
/*Recebe os dados da interface, verica a existencia do medico, caso nao exista, marca e retorna valor verdadeiro
 para a interface, caso contrário, retorna falso a interface*/
bool Medico::cadastra_medico(string nomeMedico, string especialidade){
Rotinas *bd;

    if ((this->procura_pessoa(nomeMedico)).empty()){
    Medico *novoMedico = new Medico(nomeMedico,especialidade);
    bd->insere_medico(novoMedico);
    return true;
    }
    else{
    return false;
    }
}
/*Recebe o nome da interface, verifica a existencia, se existir descadastra e retorna valor verdadeiro para a interface*/
bool Medico::descadastra_pessoa(string nome){
Rotinas *bd;

    if ((this->procura_pessoa(nome)).empty())
    return false;
    else{
    bd->deleta_medico(nome);
    return true;
    }
}
/*Recebe o nome da interface, verifica a existencia caso exista descadastra, e cadastra com os novos dados*/
bool Medico::altera_cadastro(string nomeMedico, string novoNomeMedico, string especialidade){
Rotinas *bd;

    if(this->descadastra_pessoa(nomeMedico)){
    this->cadastra_medico(novoNomeMedico, especialidade);
    return true;
    }
    else{
    return false;
    }
}
/*procura um determinado medico*/
list<string> Medico::procura_pessoa(string nome){
Rotinas *bd;

    return bd->busca_medico(nome);
}
/*Procura todos os medicos de uma determinada especialidade*/
list<string> Medico::procura_especialidade(string especialidade){
Rotinas *bd;

    return bd->busca_especialidade(especialidade);
}
/*retorna para  a inferface a lista de medicos*/
list<string> Medico::lista_pessoas(){
Rotinas *bd;

    return bd->lista_medicos();
}

