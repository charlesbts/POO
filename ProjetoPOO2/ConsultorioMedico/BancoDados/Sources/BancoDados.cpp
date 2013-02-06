#include <iostream>
#include <stdio.h>
#include <list>
#include "../Headers/BancoDados.h"
#include "sqlite3.h"

using namespace std;

BancoDados::BancoDados(string nomeArquivo){
    bool status;
    this->statement = NULL;
    this->database = NULL;
    status = open(nomeArquivo.c_str());
}

bool BancoDados::open(string nomeArquivo){
    if (sqlite3_open(nomeArquivo.c_str(), &database)==SQLITE_OK)
        return true;
    else
        return false;
}

void BancoDados::prepare(const string &query){
    int result = sqlite3_prepare_v2(this->database, query.c_str(), -1,&this->statement, 0);
}

void BancoDados::liga_string(const int indice, const string &texto){
    sqlite3_bind_text(this->statement, indice, texto.c_str(), texto.size(), NULL);
}

void BancoDados::close(){
    sqlite3_close(database);
}

list<string> BancoDados::executa_statement(){
list<string> listaResultado;

    while (sqlite3_step(this->statement) == SQLITE_ROW){
    int colunas = sqlite3_column_count(this->statement);
        for (int i=0; i<colunas;i++){
        listaResultado.push_back(string((const char *) sqlite3_column_name(this->statement, i)));
        listaResultado.push_back(string((const char *) sqlite3_column_text(this->statement, i)));
        }
    }
sqlite3_finalize(this->statement);
return listaResultado;
}
