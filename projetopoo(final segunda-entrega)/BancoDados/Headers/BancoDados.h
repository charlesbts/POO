#ifndef BANCODADOS_H
#define BANCODADOS_H

#include "sqlite3.h"
#include <exception>
#include <string>
#include <list>
#include <ctime>
using namespace std;

class BancoDadosExcecao : public exception{
private:
    const char* erro;
    const char* data;
public:
    /**
    * @brief Preenche o atributo erro.
    * @param recebe um objeto que faz conexão com o Banco.
    */
   inline void seta_erro(sqlite3 *database);
   /**
   * @brief Preenche o atributo data.
   */
   inline void seta_data();
   /**
   * @brief Persiste no banco de dados o erro e a data quando ocorreu.
   */
    void erro_banco_dados(sqlite3 *database);
};

class BancoDados{
private:
    sqlite3 *database;
    sqlite3_stmt *statement;
public:
    /**
    * @brief Construtor
    * @param Recebe o nome do arquivo usado como Banco de Dados.
    */
    BancoDados(string nomeArquivo);
    /**
    * @brief Usa o Construtor para abrir conexão com o Banco de Dados.
    * @param Recebe o nome do Banco de Dados.
    * @throw Objeto BancoDadosExcecao.
    */
    bool open(string nomeArquivo) throw (BancoDadosExcecao);
    /**
    * @brief Executa o comando SQL.
    * @return Retorna uma lista caso o comando SQL exija retorno.
    */
    list<string> executa_statement();
    /**
    * @brief Prepara o comando SQL.
    * @param Recebe uma string contendo o comando SQL.
    * @throw Objeto BancoDadosExcecao.
    */
    void prepare(const string &query) throw (BancoDadosExcecao);
    /**
    * @brief Liga uma string a determinado comando SQL.
    * @param 1 - Recebe o indice.
    * @param 2 - Conteudo da string.
    */
    void liga_string(const int indice,const string &texto);
    /**
    * @brief Fecha conexão com o Banco de Dados.
    */
    void close();
    /**
    * @brief Destrutor.
    */
    ~BancoDados();
};

#endif
