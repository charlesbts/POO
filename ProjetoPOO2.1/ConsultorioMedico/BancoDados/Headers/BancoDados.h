#ifndef BANCODADOS_H
#define BANCODADOS_H

#include "sqlite3.h"
#include <string>
#include <list>
#include <ctime>
using namespace std;

class BancoDadosExcecao{
private:
    const char* erro;
    const char* data;
public:
   inline void seta_erro(sqlite3 *database);
   inline void seta_data();
    void erro_banco_dados(sqlite3 *database);
};

class BancoDados{
private:
    sqlite3 *database;
    sqlite3_stmt *statement;
public:
    BancoDados(string nomeArquivo);
    bool open(string nomeArquivo) throw (BancoDadosExcecao);
    list<string> executa_statement() throw (BancoDadosExcecao);
    void prepare(const string &query) throw (BancoDadosExcecao);
    void liga_string(const int indice,const string &texto);
    void close();
    ~BancoDados();
};

#endif
