# define PACIENTE_IMPL
#include <iostream>
#include "../Headers/classePaciente.h"
#include "../../BancoDados/Headers/rotinasBD.h"
#include <string>

Paciente::Paciente(){

}
/*Preenche um objeto Paciente*/
Paciente::Paciente(string nome, string endereco, string telefone, string idade){

    this->m_nome = nome;
    this->m_endereco = endereco;
    this->m_telefone = telefone;
    this->m_idade = idade;
}
/*recebe os dados da Interface, verifica a existencia do paciente, caso nao exista o cadastra e retorna um valor
 verdadeiro, caso contrario, retorna um valor falso*/
bool Paciente::cadastra_paciente(string nomePaciente, string endereco, string telefone, string idade){
Rotinas *bd;

    if ((this->procura_pessoa(nomePaciente)).empty()){
    Paciente *novoPaciente = new Paciente(nomePaciente, endereco, telefone, idade);
    bd->insere_paciente(novoPaciente);
    return true;
    }
    else{
    return false;
    }
}
/*recebe um nome da logica, e verifica se existe um cadastro para este nome, caso exista, descadastra e retorna verdadeiro
 caso contraio, retorna falso*/
bool Paciente::descadastra_pessoa(string nome){
Rotinas *bd;

    if ((this->procura_pessoa(nome)).empty())
    return false;
    else{
    bd->deleta_paciente(nome);
    return true;
    }
}
/*recebe um nome da logica, descadastra(condicao de existencia ja foi verificada na interface), e faz um novo 
 cadastro com os novos dados*/
bool Paciente::altera_cadastro(string nomePaciente, string novoNomePaciente, string endereco, string telefone, string idade){
Rotinas *bd;

    if(this->descadastra_pessoa(nomePaciente)){
    this->cadastra_paciente(novoNomePaciente, endereco, telefone, idade);
    return true;
    }
    else{
    return false;
    }
}
/*Procura uma determinada pessoa nos cadastros*/
list<string> Paciente::procura_pessoa(string nome){
Rotinas *bd;

    return bd->busca_paciente(nome);
}
/*Retonar uma lista de pacientes*/
list<string> Paciente::lista_pessoas(){
Rotinas *bd;

    return bd->lista_pacientes();
}
