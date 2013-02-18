/*
 * File:   TesteLogicaNegocio.cpp
 * Author: KelvinEC
 *
 * Created on 17/02/2013, 03:43:39
 */

#include "TesteClassePaciente.h"
#include "../../LogicaNegocio/Headers/classePaciente.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TesteClassePaciente);

void TesteClassePaciente::setUp() {
}

void TesteClassePaciente::tearDown() {
}

void TesteClassePaciente::InsercaoPaciente() {
    std::string nome="Maria",endereco = "RO",telefone = "34834782", idade = "50";
    Paciente* newpaciente = new Paciente();
    bool result;
    result = newpaciente->cadastra_paciente(nome,endereco,telefone,idade);
    CPPUNIT_ASSERT(result == true);
    nome = "Francisca";
    endereco = "GOV";
    telefone = "NAOTEM";
    idade = "65";
    result = newpaciente->cadastra_paciente(nome,endereco,telefone,idade);
    CPPUNIT_ASSERT(result == true);
    nome = "Eustacio";
    endereco = "Nolocal";
    telefone = "66666666666";
    idade = "95";
    result = newpaciente->cadastra_paciente(nome,endereco,telefone,idade);
    CPPUNIT_ASSERT(result == true);
    nome = "ZinBacalhau";
    endereco = "SMV";
    telefone = "36132353";
    idade = "77";
    result = newpaciente->cadastra_paciente(nome,endereco,telefone,idade);
    CPPUNIT_ASSERT(result == true);
}
void TesteClassePaciente::InsercaoPacienteFailedMethod() {
    // Apartir daqui tem que falhar, registros já incluidos.
    std::string nome="Maria",endereco = "RO", telefone = "34834782", idade = "50";
    Paciente* newpaciente = new Paciente();
    bool result = newpaciente->cadastra_paciente(nome,endereco,telefone,idade);
    CPPUNIT_ASSERT(result == false);
    nome = "Francisca";
    endereco = "GOV";
    telefone = "NAOTEM";
    idade = "65";
    result = newpaciente->cadastra_paciente(nome,endereco,telefone,idade);
    CPPUNIT_ASSERT(result == false);
    nome = "Eustacio";
    endereco = "Nolocal";
    telefone = "66666666666";
    idade = "95";
    result = newpaciente->cadastra_paciente(nome,endereco,telefone,idade);
    CPPUNIT_ASSERT(result == false);
    nome = "ZinBacalhau";
    endereco = "SMV";
    telefone = "36132353";
    idade = "77";
    result = newpaciente->cadastra_paciente(nome,endereco,telefone,idade);
    CPPUNIT_ASSERT(result == false);
}

void TesteClassePaciente::PesquisaPaciente(){
    std::string nome = "Francisca";;
    Paciente* newpaciente = new Paciente();
    list<string>listaResultado = newpaciente->procura_pessoa(nome);    
    list<string>::iterator listaPaciente = listaResultado.begin();
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(nome,*listaPaciente);
    nome = "Eustacio";;
    listaResultado = newpaciente->procura_pessoa(nome);
    listaPaciente = listaResultado.begin();
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(nome,*listaPaciente);
    nome = "ZinBacalhau";
    listaResultado = newpaciente->procura_pessoa(nome);
    listaPaciente = listaResultado.begin();
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(nome,*listaPaciente);
    nome = "Maria";
    listaResultado = newpaciente->procura_pessoa(nome);
    listaPaciente = listaResultado.begin();
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(nome,*listaPaciente);  
}
void TesteClassePaciente::AlteracaoCadastroPaciente(){
    Paciente* newpaciente = new Paciente();
    string nome = "Francisca",newnome = "Francisca Silva",newendereco = "LOL",newtelefone = "8271831",newidade="98";
    bool result = newpaciente->altera_cadastro(nome,newnome,newendereco,newtelefone,newidade);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nome = "Eustacio";newnome = "Eustacio Silva";newendereco = "MEME";newtelefone = "3351392";newidade="25";
    result = newpaciente->altera_cadastro(nome,newnome,newendereco,newtelefone,newidade);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nome = "ZinBacalhau";newnome = "ZinBacalhau Cruz";newendereco = "SAMAVI";newtelefone = "33300293";newidade="65";
    result = newpaciente->altera_cadastro(nome,newnome,newendereco,newtelefone,newidade);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nome = "Maria";newnome = "Maria do Carmo",newendereco = "Riacho Fundo I",newtelefone = "NAOTTEM",newidade="200";
    result = newpaciente->altera_cadastro(nome,newnome,newendereco,newtelefone,newidade);
    CPPUNIT_ASSERT_EQUAL(true,result);
}

void TesteClassePaciente::AlteracaoCadastroPacienteFailedMethod(){
    Paciente* newpaciente = new Paciente();
    string nome = "Francisca",newnome = "Francisca Silva",newendereco = "LOL",newtelefone = "8271831",newidade="98";
    bool result = newpaciente->altera_cadastro(nome,newnome,newendereco,newtelefone,newidade);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nome = "Eustacio";newnome = "Eustacio Silva";newendereco = "MEME";newtelefone = "3351392";newidade="25";
    result = newpaciente->altera_cadastro(nome,newnome,newendereco,newtelefone,newidade);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nome = "ZinBacalhau";newnome = "ZinBacalhau Cruz";newendereco = "SAMAVI";newtelefone = "33300293";newidade="65";
    result = newpaciente->altera_cadastro(nome,newnome,newendereco,newtelefone,newidade);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nome = "Maria";newnome = "Maria do Carmo",newendereco = "Riacho Fundo I",newtelefone = "NAOTTEM",newidade="200";
    result = newpaciente->altera_cadastro(nome,newnome,newendereco,newtelefone,newidade);
    CPPUNIT_ASSERT_EQUAL(false,result);
}


void TesteClassePaciente::DelecaoPaciente(){ /* Testa a delecao de pacientess que nao existem*/
    std::string nome = "Francisca Silva";   /*Ou ja foram deletados*/ 
    Paciente* newpaciente = new Paciente();
    bool result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==true);
    nome = "Eustacio Silva";
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==true);
    nome = "ZinBacalhau Cruz";
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==true);
    nome = "Maria do Carmo";
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==true);    
}

void TesteClassePaciente::DelecaoPacienteFailedMethod(){
    std::string nome = "Francisca";    
    Paciente* newpaciente = new Paciente();
    bool result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "Eustacio";
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "ZinBacalhau";
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "Maria";
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false); 
    nome = "Francisca Silva";    
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "Eustacio Silva";
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "ZinBacalhau Cruz";
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "Maria do Carmo";
    result = newpaciente->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
}


void TesteClassePaciente::PesquisaPacienteFailedMethod(){ /* Faz uma pesquisa de Registros removidos e/ou inexistentes*/
    std::string nome = "Francisca";;
    Paciente* newpaciente = new Paciente();;
    CPPUNIT_ASSERT(newpaciente->procura_pessoa(nome).empty()==true); 
    nome = "Eustacio";;                                             
    CPPUNIT_ASSERT(newpaciente->procura_pessoa(nome).empty()==true);
    nome = "ZinBacalhau";
    CPPUNIT_ASSERT(newpaciente->procura_pessoa(nome).empty()==true);
    nome = "Maria";
    CPPUNIT_ASSERT(newpaciente->procura_pessoa(nome).empty()==true);
    nome = "Eustacio Silva";;                                             
    CPPUNIT_ASSERT(newpaciente->procura_pessoa(nome).empty()==true);
    nome = "ZinBacalhau Cruz";
    CPPUNIT_ASSERT(newpaciente->procura_pessoa(nome).empty()==true);
    nome = "Maria do Carmo";
    CPPUNIT_ASSERT(newpaciente->procura_pessoa(nome).empty()==true);
    nome = "Francisca Silva";
    CPPUNIT_ASSERT(newpaciente->procura_pessoa(nome).empty()==true);
}

