#ifndef BANCODADOS_H
#define BANCODADOS_H

#include "sqlite3.h"
#include <string>
#include <list>
#include <exception>
using namespace std;

/*class BancoDadosExcecao : exception{
private:
    string erro;
public:

};*/

class BancoDados{
private:
    sqlite3 *database;
    sqlite3_stmt *statement;
public:
    BancoDados(string nomeArquivo);
    bool open(string nomeArquivo);
    list<string> executa_statement();
    void prepare(const string &query);
    void liga_string(const int indice,const string &texto);
    void close();
    ~BancoDados();
};

#endif
