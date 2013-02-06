#include <iostream>
#include "../Headers/classeMedico.h"
#include "../../BancoDados/Headers/rotinasBD.h"
#include <string.h>

Medico::Medico(string nome,string especialidade){
    this->m_especialidade = especialidade;
    this->m_nome = nome;
}

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

bool Medico::descadastra_pessoa(string nome){
int resultadoBd;
Rotinas *bd;
    if ((this->procura_pessoa(nome)).empty())
    return false;
    else
    resultadoBd = bd->deleta_medico(nome);
}

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

list<string> Medico::procura_pessoa(string nome){
Rotinas *bd;

    return bd->busca_medico(nome);
}
