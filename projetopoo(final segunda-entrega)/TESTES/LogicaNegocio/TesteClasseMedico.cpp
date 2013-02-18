/*
 * File:   TesteClasseMedico.cpp
 * Author: KelvinEC
 *
 * Created on 17/02/2013, 14:33:43
 */

#include "TesteClasseMedico.h"
#include "../../LogicaNegocio/Headers/classeMedico.h"

CPPUNIT_TEST_SUITE_REGISTRATION(TesteClasseMedico);



void TesteClasseMedico::setUp() {
}

void TesteClasseMedico::tearDown() {
}
void TesteClasseMedico::InsercaoMedico() {
    std::string nome="Joao",especialidade="EC";
    Medico* newmedico = new Medico();
    bool result;
    result = newmedico->cadastra_medico(nome,especialidade);
    CPPUNIT_ASSERT(result == true);
    nome = "Joaquim";
    especialidade = "CIC";
    result = newmedico->cadastra_medico(nome,especialidade);
    CPPUNIT_ASSERT(result == true);
    nome = "Quezado";
    especialidade = "QT";
    result = newmedico->cadastra_medico(nome,especialidade);
    CPPUNIT_ASSERT(result == true);
    nome = "Das Virgens";
    especialidade = "TOOLS";
    result = newmedico->cadastra_medico(nome,especialidade);
    CPPUNIT_ASSERT(result == true);
}
void TesteClasseMedico::InsercaoMedicoFailedMethod() {
    std::string nome="Joao", especialidade="EC";
    Medico* newmedico = new Medico();
    bool result = newmedico->cadastra_medico(nome,especialidade);
    CPPUNIT_ASSERT(result == false);
    nome = "Joaquim";
    especialidade = "CIC";
    result = newmedico->cadastra_medico(nome,especialidade);
    CPPUNIT_ASSERT(result == false);
    nome = "Quezado";
    especialidade = "QT";
    result = newmedico->cadastra_medico(nome,especialidade);
    CPPUNIT_ASSERT(result == false);
    nome = "Das Virgens";
    especialidade = "TOOLS";
    result = newmedico->cadastra_medico(nome,especialidade);
    CPPUNIT_ASSERT(result == false);
}
void TesteClasseMedico::PesquisaMedico(){
    std::string nome = "Joao";
    Medico* newmedico = new Medico();
    list<string>listaResultado = newmedico->procura_pessoa(nome);    
    list<string>::iterator listaMedico = listaResultado.begin();
    listaMedico++;
    CPPUNIT_ASSERT_EQUAL(nome,*listaMedico);
    nome = "Joaquim";
    listaResultado = newmedico->procura_pessoa(nome);
    listaMedico = listaResultado.begin();
    listaMedico++;
    CPPUNIT_ASSERT_EQUAL(nome,*listaMedico);
    nome = "Quezado";
    listaResultado = newmedico->procura_pessoa(nome);
    listaMedico = listaResultado.begin();
    listaMedico++;
    CPPUNIT_ASSERT_EQUAL(nome,*listaMedico);
    nome = "Das Virgens";
    listaResultado = newmedico->procura_pessoa(nome);
    listaMedico = listaResultado.begin();
    listaMedico++;
    CPPUNIT_ASSERT_EQUAL(nome,*listaMedico);   
}
void TesteClasseMedico::AlteracaoCadastroMedico(){
    Medico* newmedico = new Medico();
    string nome = "Joao",newnome = "Kelvin William",newespecialidade = "EC";
    bool result = newmedico->altera_cadastro(nome,newnome,newespecialidade);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nome = "Joaquim";newnome="Charles Cardoso";newespecialidade = "BD";
    result = newmedico->altera_cadastro(nome,newnome,newespecialidade);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nome = "Das Virgens";newnome="Bruno Ribeiro";newespecialidade = "QTISTA";
    result = newmedico->altera_cadastro(nome,newnome,newespecialidade);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nome = "Quezado";newnome="Victor Quezado";newespecialidade = "VAGAL";
    result = newmedico->altera_cadastro(nome,newnome,newespecialidade);
    CPPUNIT_ASSERT_EQUAL(true,result);
}

void TesteClasseMedico::AlteracaoCadastroMedicoFailedMethod(){
    Medico* newmedico = new Medico();
    string nome = "Joao",newnome = "Kelvin William",newespecialidade = "EC";
    bool result = newmedico->altera_cadastro(nome,newnome,newespecialidade);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nome = "Joaquim";newnome="Charles Cardoso";newespecialidade = "BD";
    result = newmedico->altera_cadastro(nome,newnome,newespecialidade);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nome = "Das Virgens";newnome="Bruno Ribeiro";newespecialidade = "QTISTA";
    result = newmedico->altera_cadastro(nome,newnome,newespecialidade);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nome = "Quezado";newnome="Victor Quezado";newespecialidade = "VAGAL";
    result = newmedico->altera_cadastro(nome,newnome,newespecialidade);
    CPPUNIT_ASSERT_EQUAL(false,result);
}
void TesteClasseMedico::DelecaoMedico(){
    std::string nome = "Kelvin William";    
    Medico* newmedico = new Medico();
    bool result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==true);
    nome = "Charles Cardoso";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==true);
    nome = "Victor Quezado";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==true);
    nome = "Bruno Ribeiro";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==true);    
}

void TesteClasseMedico::DelecaoMedicoFailedMethod(){ /*Testa a Delecao de Pacientes que Não existem no Banco*/
    std::string nome = "Joao";                      /*ou ja foram deletados, comprovando que nao existem*/
    Medico* newmedico = new Medico();
    bool result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "Joaquim";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "Quezado";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "Das Virgens";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);  
    nome = "Kelvin William";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "Victor Quezado";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);
    nome = "Bruno Ribeiro";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false); 
    nome = "Charles Cardoso";
    result = newmedico->descadastra_pessoa(nome);
    CPPUNIT_ASSERT(result==false);  
}

void TesteClasseMedico::PesquisaMedicoFailedMethod(){ /* Pesquia Nomes que Nao existem e/ou Foram Deletados*/
    string nome = "Kelvin William";                     
    Medico* newmedico = new Medico();
    CPPUNIT_ASSERT(newmedico->procura_pessoa(nome).empty()==true);   
    nome = "Charles Cardoso";
    CPPUNIT_ASSERT(newmedico->procura_pessoa(nome).empty()==true);  
    nome = "Victor Quezado";
    CPPUNIT_ASSERT(newmedico->procura_pessoa(nome).empty()==true);   
    nome = "Bruno Ribeiro";
    CPPUNIT_ASSERT(newmedico->procura_pessoa(nome).empty()==true);  
    nome = "Joaquim";
    CPPUNIT_ASSERT(newmedico->procura_pessoa(nome).empty()==true);  
    nome = "Quezado";
    CPPUNIT_ASSERT(newmedico->procura_pessoa(nome).empty()==true);   
    nome = "Das Virgens";
    CPPUNIT_ASSERT(newmedico->procura_pessoa(nome).empty()==true);
    nome = "Joao";
    CPPUNIT_ASSERT(newmedico->procura_pessoa(nome).empty()==true);
}



