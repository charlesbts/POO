/*
 * File:   newtestclass.cpp
 * Author: KelvinEC
 *
 * Created on 16/02/2013, 23:56:41
 */

#include "newtestclass.h"
#include "../BancoDados/Headers/rotinasBD.h"
#include "../LogicaNegocio/Headers/classeMedico.h"
#include "../LogicaNegocio/Headers/classePaciente.h"
#include "../LogicaNegocio/Headers/classeConsulta.h"

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);


void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::InsercaoMedico() {
    Medico* newmedico = new Medico("Kelvin William","EC");
    Rotinas *bd;
    bd->insere_medico(newmedico);
    list<string>listaResultado = bd->busca_medico(newmedico->m_nome);    
    list<string>::iterator listaMedico = listaResultado.begin();
    listaMedico++; /* Valor da coluna medico */
    CPPUNIT_ASSERT_EQUAL(newmedico->m_nome,*listaMedico);
    listaMedico++;
    listaMedico++;
    CPPUNIT_ASSERT_EQUAL(newmedico->m_especialidade,*listaMedico);
    
    newmedico->m_nome = "Charles Cardoso";
    newmedico->m_especialidade="CIC";
    bd->insere_medico(newmedico);
    listaResultado = bd->busca_medico(newmedico->m_nome);    
    listaMedico = listaResultado.begin();
    listaMedico++; /* Valor da coluna medico */
    CPPUNIT_ASSERT_EQUAL(newmedico->m_nome,*listaMedico);
    listaMedico++;
    listaMedico++;
    CPPUNIT_ASSERT_EQUAL(newmedico->m_especialidade,*listaMedico);
    
    newmedico->m_nome = "Victor Quezado";
    newmedico->m_especialidade="NEGAS";
    bd->insere_medico(newmedico);
    listaResultado = bd->busca_medico(newmedico->m_nome);    
    listaMedico = listaResultado.begin();
    listaMedico++; /* Valor da coluna medico */
    CPPUNIT_ASSERT_EQUAL(newmedico->m_nome,*listaMedico);
    listaMedico++;
    listaMedico++;
    CPPUNIT_ASSERT_EQUAL(newmedico->m_especialidade,*listaMedico);
};
void newtestclass::InsercaoPaciente() {
    Paciente* newpaciente = new Paciente("Kelvin William","C7","82715501","18");
    Rotinas *bd;
    bd->insere_paciente(newpaciente);
    list<string>listaResultado = bd->busca_paciente(newpaciente->m_nome);    
    list<string>::iterator listaPaciente = listaResultado.begin();
    listaPaciente++; /* Valor da coluna medico */
    CPPUNIT_ASSERT_EQUAL(newpaciente->m_nome,*listaPaciente);
    listaPaciente++;
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(newpaciente->m_endereco,*listaPaciente);
    listaPaciente++;
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(newpaciente->m_telefone,*listaPaciente);
    listaPaciente++;
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(newpaciente->m_idade,*listaPaciente);
    
    Paciente* newpaciente2 = new Paciente("Charles","AsaNorte","82732","19");
    bd->insere_paciente(newpaciente2);
    listaResultado = bd->busca_paciente(newpaciente2->m_nome);    
    listaPaciente = listaResultado.begin();
    listaPaciente++; /* Valor da coluna medico */
    CPPUNIT_ASSERT_EQUAL(newpaciente2->m_nome,*listaPaciente);
    listaPaciente++;
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(newpaciente2->m_endereco,*listaPaciente);
    listaPaciente++;
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(newpaciente2->m_telefone,*listaPaciente);
    listaPaciente++;
    listaPaciente++;
    CPPUNIT_ASSERT_EQUAL(newpaciente2->m_idade,*listaPaciente);
};
void newtestclass::DelecaoMedico(){
 std::string nome = "Kelvin William";    
    Rotinas* newrotina;
    int result = newrotina->deleta_medico(nome); 
    CPPUNIT_ASSERT_EQUAL(true,newrotina->busca_medico(nome).empty());
    nome = "Charles Cardoso";
    result = newrotina->deleta_medico(nome);
    CPPUNIT_ASSERT_EQUAL(true,newrotina->busca_medico(nome).empty());
    nome = "Victor Quezado";
    result = newrotina->deleta_medico(nome);
    CPPUNIT_ASSERT_EQUAL(true,newrotina->busca_medico(nome).empty());
    nome = "Bruno Ribeiro";
    result = newrotina->deleta_medico(nome);
    CPPUNIT_ASSERT_EQUAL(true,newrotina->busca_medico(nome).empty());    
}
void newtestclass::DelecaoPaciente(){
 std::string nome = "Kelvin William";    
    Rotinas* newrotina;
    int result = newrotina->deleta_paciente(nome); 
    CPPUNIT_ASSERT_EQUAL(true,newrotina->busca_paciente(nome).empty());
    nome = "Charles Cardoso";
    result = newrotina->deleta_paciente(nome); 
    CPPUNIT_ASSERT_EQUAL(true,newrotina->busca_paciente(nome).empty()); 
}
void newtestclass::MarcaConsulta(){
    string nomeMedico = "Kelvin",nomePaciente = "Victor";
    Consulta *consulta = new Consulta(nomePaciente,nomeMedico);
    Rotinas* bd;
    bd->insere_consulta(consulta);    
    list<string>listaResultado = bd->busca_consulta(nomePaciente,nomeMedico);    
    list<string>::iterator listaConsulta = listaResultado.begin();
    listaConsulta++; /* Valor da coluna medico */
    CPPUNIT_ASSERT_EQUAL(nomeMedico,*listaConsulta);
    listaConsulta++;
    listaConsulta++;
    CPPUNIT_ASSERT_EQUAL(nomePaciente,*listaConsulta);
    
    consulta->m_paciente = "Charles";
    bd->insere_consulta(consulta);
    listaResultado = bd->busca_consulta(consulta->m_paciente,consulta->m_medico);
    listaConsulta = listaResultado.begin();
    listaConsulta++;
    CPPUNIT_ASSERT_EQUAL(nomeMedico,*listaConsulta);
    listaConsulta++;
    listaConsulta++;
    CPPUNIT_ASSERT_EQUAL(consulta->m_paciente,*listaConsulta);
}

void newtestclass::DeletaConsulta(){
    string nomePaciente = "Victor", nomeMedico = "Kelvin";
    Rotinas* bd;
    bd->deleta_consulta (nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,bd->busca_consulta(nomePaciente,nomeMedico).empty());
    nomePaciente = "Charles";
    bd->deleta_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,bd->busca_consulta(nomePaciente,nomeMedico).empty());
}