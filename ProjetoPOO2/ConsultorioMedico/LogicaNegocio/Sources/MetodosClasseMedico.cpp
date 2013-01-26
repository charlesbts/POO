#include <iostream>
#include "../Headers/classeMedico.h"
#include "../../BancoDados/Headers/rotinasBD.h"
#include <string.h>

Medico::Medico(string nome,string especialidade){
    Medico::m_especialidade=especialidade;
    Medico::m_nome=nome;

    }


void Medico::cadastra_medico(string nome, string especialidade){
    Rotinas *bd;
    Medico *novoMedico=new Medico(nome,especialidade);
    bd->insere_medico(novoMedico);
}

vector<vector<string> > Medico::procura_pessoa(string nome){
    vector<vector<string> > resultadoBusca;
    Rotinas *bd;
    resultadoBusca = bd->busca_tabela(nome, "Medico");
}
