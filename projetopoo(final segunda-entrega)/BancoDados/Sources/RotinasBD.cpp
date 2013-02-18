#include <iostream>
#include <map>
#include "../Headers/rotinasBD.h"
#include "../../LogicaNegocio/Headers/classeMedico.h"
#include "../../LogicaNegocio/Headers/classePaciente.h"
#include "../../LogicaNegocio/Headers/classeConsulta.h"

using namespace std;
/*recebe um objeto do tipo Medico preenchido, prepara a query, e insere no banco*/
void Rotinas::insere_medico(Medico *novoMedico){
BancoDados *bd;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("INSERT INTO Medico(nome, especialidade) VALUES(?, ?);");
    bd->liga_string(1, novoMedico->m_nome);
    bd->liga_string(2, novoMedico->m_especialidade);
    bd->executa_statement();
    bd->close();
}
/*recebe um nome da logica, prepara a query, e deleta o medico do banco*/
int Rotinas::deleta_medico(string nomeMedico){
BancoDados *bd;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("DELETE FROM Medico WHERE nome like ?;");
    bd->liga_string(1, nomeMedico);
    bd->executa_statement();
    bd->close();
    return 0;
}
/*recebe um nome da logica, prepara a query e efetua busca do medico, retorna uma lista com o nome das colunas 
 e os valores encontrados*/
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
/*recebe a especialidade de um determinando medico da logica, e prepara a query pra busca, e retorna um medico
 com a determinada especialidade*/
list<string> Rotinas::busca_especialidade(string especialidade){
BancoDados *bd;
list<string> listaResultado;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT nome FROM Medico WHERE especialidade like ?;");
    bd->liga_string(1, especialidade);
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
/*Prepara uma query para a listagem de todos os medicos*/
list<string> Rotinas::lista_medicos(){
BancoDados *bd;
list<string> listaResultado;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT * FROM Medico;");
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
/*recebe um objeto paciente preenchido, prepara uma query para a insercao do paceinte na sua tabela, e insere.*/
void Rotinas::insere_paciente(Paciente *novoPaciente){
BancoDados *bd;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("INSERT INTO Paciente(nome, endereco, telefone, idade) VALUES(?, ?, ?, ?);");
    bd->liga_string(1, novoPaciente->m_nome);
    bd->liga_string(2, novoPaciente->m_endereco);
    bd->liga_string(3, novoPaciente->m_telefone);
    bd->liga_string(4, novoPaciente->m_idade);
    bd->executa_statement();
    bd->close();
}
/*recebe da logica um nome de paciente, prepara a query para delecao, e o deleta*/
int Rotinas::deleta_paciente(string nomePaciente){
BancoDados *bd;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("DELETE FROM Paciente WHERE nome like ?;");
    bd->liga_string(1, nomePaciente);
    bd->executa_statement();
    bd->close();
    return 0;
}
/*recebe um nome da logica, prepara a query para a busca na tabela paciente, busca, e retorna uma lista
 com os valores encontrados*/
list<string> Rotinas::busca_paciente(string nomePaciente){
BancoDados *bd;

    list<string> listaResultado;
    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT * FROM Paciente WHERE nome like ?;");
    bd->liga_string(1, nomePaciente);
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
/*Prepara uma query para busca de pacientes, como nao especifica um em especial, retorna uma lista com todos os pacientes*/
list<string> Rotinas::lista_pacientes(){
BancoDados *bd;
list<string> listaResultado;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT * FROM Paciente;");
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
/*Recebe um objeto consultas preenchido da logica, e prepara a query para insercao na tabela propria, e insere*/
void Rotinas::insere_consulta(Consulta *consulta){
BancoDados *bd;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("INSERT INTO Consulta(paciente, medico, codigo) VALUES(?, ?, ?);");
    bd->liga_string(1, consulta->m_paciente);
    bd->liga_string(2, consulta->m_medico);
    bd->liga_string(3, consulta->m_codigo);
    bd->executa_statement();
    bd->close();
}
/*recebe o nome do paciente e do medico, e preara a query para buscar uma consulta onde os campos sejam identicos 
 aos desejados e retorna uma lista com esses valores*/
list<string> Rotinas::busca_consulta(string nomePaciente, string nomeMedico){
BancoDados *bd;
list<string> listaResultado;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT * FROM Consulta WHERE paciente like ? AND medico like ?;");
    bd->liga_string(1, nomePaciente);
    bd->liga_string(2, nomeMedico);
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
/*recebe um nome de paciente e medico, e deleta uma consulta que contenha esses elementos*/
void Rotinas::deleta_consulta(string nomePaciente, string nomeMedico){
BancoDados *bd;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("DELETE FROM Consulta WHERE paciente like ? AND medico like ?;");
    bd->liga_string(1, nomePaciente);
    bd->liga_string(2, nomeMedico);
    bd->executa_statement();
    bd->close();
}
/*Prepara a query para busca, como nao especifica valores especificos armazena todas as consultas numa lista
 e retorna pra logica*/
list<string> Rotinas::lista_consultas(){
BancoDados *bd;
list<string> listaResultado;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT * FROM Consulta;");
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
/*Prepara a query para buscar todos os paciente que tenham consultas marcadas com um determinado medico*/
list<string> Rotinas::busca_pacientes_de_um_medico(string nomeMedico){
BancoDados *bd;
list<string> listaResultado;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT paciente FROM Consulta WHERE medico like ?;");
    bd->liga_string(1, nomeMedico);
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
/*Procura no banco todos os medicos de um determinado paciente e os retorna numa lista*/
list<string> Rotinas::busca_medicos_de_um_paciente(string nomePaciente){
BancoDados *bd;
list<string> listaResultado;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT medico FROM Consulta WHERE paciente like ?;");
    bd->liga_string(1, nomePaciente);
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
/*procura no banco, todas as consultas de um determinado paciente*/
list<string> Rotinas::busca_consultas_paciente(string nomePaciente){
BancoDados *bd;
list<string> listaResultado;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT * FROM Consulta WHERE paciente like ?;");
    bd->liga_string(1, nomePaciente);
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
/*busca todas as consultas marcadas para um determinado medico*/
list<string> Rotinas::busca_consultas_medico(string nomeMedico){
BancoDados *bd;
list<string> listaResultado;

    bd = new BancoDados("consultorio.sqlite3");
    bd->prepare("SELECT * FROM Consulta WHERE medico like ?;");
    bd->liga_string(1, nomeMedico);
    listaResultado = bd->executa_statement();
    bd->close();
    return listaResultado;
}
