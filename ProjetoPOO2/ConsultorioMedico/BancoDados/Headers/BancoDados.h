#ifndef BANCODADOS_H
#define BANCODADOS_H
#include "sqlite3.h"
#include <string>
#include <vector>
using namespace std;

class BancoDados{
private:
    sqlite3 *database;
public:
    BancoDados (char* nomeArquivo);
    bool open (char* nomeArquivo);
    vector<vector<string> > rotina (char* query);
    void close();
    ~BancoDados();
};

#endif
