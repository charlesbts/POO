#define EXCECOESBANCODADOS_IMPL
#include "../Headers/BancoDados.h"

inline void BancoDadosExcecao::seta_erro(sqlite3 *database){
    this->erro = sqlite3_errmsg(database);
}

inline void BancoDadosExcecao::seta_data(){
time_t data;

        time (&data);
        this->data = ctime(&data);
}

void BancoDadosExcecao::erro_banco_dados(sqlite3 *database){
BancoDados *bd = new BancoDados("consultorio.sqlite3");

    this->seta_erro(database);
    this->seta_data();
    bd->prepare("INSERT INTO Erro (data, erro) VALUES (?, ?);");
    bd->liga_string(1, this->data);
    bd->liga_string(2, this->erro);
    bd->executa_statement();
    bd->close();
}


