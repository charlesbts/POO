#include <iostream>
#include <string.h>
#include "../Headers/rotinasBD.h"
#include "../../LogicaNegocio/Headers/classeMedico.h"

void Rotinas::insere_medico(Medico *newmedico){
    BancoDados *bd;
    string query="INSERT INTO Medico VALUES('"+ newmedico->m_nome +"','" +newmedico->m_especialidade+"');";
    bd= new BancoDados(conversor_string_to_char("ConsultorioMedico.sqlite3"));
    bd->rotina(conversor_string_to_char("CREATE TABLE Medico(nome TEXT,especialidade TEXT);"));
    bd->rotina(conversor_string_to_char(query));
    bd->close();
}

vector<vector<string> > Rotinas::busca_tabela(string nome, string tabela){
    vector<vector<string> > resultadoBusca;
    BancoDados *bd = new BancoDados(conversor_string_to_char("ConsultorioMedico.sqlite3"));
    string query = "SELECT "+nome+" FROM "+tabela+";";
    resultadoBusca = bd->rotina(conversor_string_to_char(query));
    return resultadoBusca;
    }

char* Rotinas::conversor_string_to_char(string linha){
    char *palavra;
    palavra = new char[linha.size()+1];
    strcpy(palavra,linha.c_str());
    return palavra;
}
