#include <iostream>
#include "../Headers/BancoDados.h"
#include "sqlite3.h"

using namespace std;

BancoDados::BancoDados(char* nomeArquivo){
    bool status;
    database = NULL;
    open(nomeArquivo);
}

bool BancoDados::open(char* nomeArquivo){
    if (sqlite3_open(nomeArquivo, &database)==SQLITE_OK)
        return true;
    else
        return false;
}

vector<vector<string> > BancoDados::rotina(char* query){
sqlite3_stmt *statement;
vector<vector<string> > resultados;

    if(sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK){
    int colunas = sqlite3_column_count(statement);
    int status = SQLITE_ROW;
        while(status==SQLITE_ROW){
        status = sqlite3_step(statement);
	            if(status == SQLITE_ROW){
                vector<string> valores;
	                for(int col = 0; col < colunas; col++){
                    valores.push_back((char*)sqlite3_column_text(statement, col));
	                }
                    resultados.push_back(valores);
	            }
	        }
            sqlite3_finalize(statement);
	    }

	    string error = sqlite3_errmsg(database);
	    if(error != "not an error")
	    cout << query << " " << error << endl;

	    return resultados;
}


void BancoDados::close(){
    sqlite3_close(database);
}
