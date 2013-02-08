#include <iostream>
#include <map>
#include "../Headers/rotinasBD.h"
#include "../../LogicaNegocio/Headers/classeMedico.h"

using namespace std;

void Rotinas::insere_medico(Medico *novoMedico){
    BancoDados *bd;
    bd = new BancoDados("consultorio.sqlite3");
    bd->executa_statement();
    bd->prepare("INSERT INTO Medico(nome, especialidade) VALUES(?, ?);");
    bd->liga_string(1, novoMedico->m_nome);
    bd->liga_string(2, novoMedico->m_especialidade);
    bd->executa_statement();
    bd->close();
}

int Rotinas::deleta_medico(string nomeMedico){
    BancoDados *bd;
    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("DELETE FROM Medico WHERE nome like ?;");
    bd->liga_string(1, nomeMedico);
    bd->executa_statement();
    bd->close();
    return 0;
}

list<string> Rotinas::busca_medico(string nomeMedico){
    BancoDados *bd;
    list<string> listaResultado;
    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT * FROM Medico WHERE nome like ?;");
    bd->liga_string(1, nomeMedico);
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
