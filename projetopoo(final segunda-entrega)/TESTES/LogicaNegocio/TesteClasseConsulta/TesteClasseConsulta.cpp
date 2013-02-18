/*
 * File:   TesteClasseConsulta.cpp
 * Author: KelvinEC
 *
 * Created on 17/02/2013, 17:09:17
 */

#include "TesteClasseConsulta.h"
#include "../../../LogicaNegocio/Headers/classeConsulta.h"


CPPUNIT_TEST_SUITE_REGISTRATION(TesteClasseConsulta);

TesteClasseConsulta::TesteClasseConsulta() {
}

TesteClasseConsulta::~TesteClasseConsulta() {
}

void TesteClasseConsulta::setUp() {
}

void TesteClasseConsulta::tearDown() {
}

void TesteClasseConsulta::MarcaConsulta() {
    string nomePaciente = "Victor",nomeMedico = "Kelvin";
    Consulta* newconsulta = new Consulta();
    bool result = newconsulta->marca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nomePaciente = "Victor";
    nomeMedico = "Charles";
    result = newconsulta->marca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nomePaciente = "Bruno";
    nomeMedico = "Kelvin";
    result = newconsulta->marca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nomePaciente = "Bruno";
    nomeMedico = "Charles";
    result = newconsulta->marca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
    
}
void TesteClasseConsulta::MarcaConsultaFailedMethod() { /*Testa marcar a consulta de um paciente com o mesmo medico.*/
    string nomePaciente = "Victor",nomeMedico = "Kelvin";/*E também, Pacientes com Médicos Inexistentes, e vice-versa*/
    Consulta* newconsulta = new Consulta();
    bool result = newconsulta->marca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nomePaciente = "Victor";
    nomeMedico = "Charles";
    result = newconsulta->marca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nomePaciente = "Bruno";
    nomeMedico = "Kelvin";
    result = newconsulta->marca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nomePaciente = "Bruno";
    nomeMedico = "Charles";
    result = newconsulta->marca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
   
}

void TesteClasseConsulta::ProcuraConsulta(){
    string nomePaciente = "Victor",nomeMedico = "Kelvin";
    Consulta* newconsulta = new Consulta();
    list<string> listaResultado = newconsulta->procura_consulta(nomePaciente,nomeMedico);
    list<string>::iterator listaConsultas = listaResultado.begin();
    listaConsultas++;
    CPPUNIT_ASSERT_EQUAL(nomeMedico,(*listaConsultas));
    listaConsultas++;
    listaConsultas++;
    CPPUNIT_ASSERT_EQUAL(nomePaciente,(*listaConsultas));
    nomePaciente = "Victor";
    nomeMedico = "Charles";
    listaResultado = newconsulta->procura_consulta(nomePaciente,nomeMedico);
    listaConsultas = listaResultado.begin();
    listaConsultas++;
    CPPUNIT_ASSERT_EQUAL(nomeMedico,(*listaConsultas));
    listaConsultas++;
    listaConsultas++;
    CPPUNIT_ASSERT_EQUAL(nomePaciente,(*listaConsultas));
    nomePaciente = "Bruno";
    nomeMedico = "Kelvin";
    listaResultado = newconsulta->procura_consulta(nomePaciente,nomeMedico);
    listaConsultas = listaResultado.begin();
    listaConsultas++;
    CPPUNIT_ASSERT_EQUAL(nomeMedico,(*listaConsultas));
    listaConsultas++;
    listaConsultas++;
    CPPUNIT_ASSERT_EQUAL(nomePaciente,(*listaConsultas));
    nomePaciente = "Bruno";
    nomeMedico = "Charles";
    listaResultado = newconsulta->procura_consulta(nomePaciente,nomeMedico);
    listaConsultas = listaResultado.begin();
    listaConsultas++;
    CPPUNIT_ASSERT_EQUAL(nomeMedico,(*listaConsultas));
    listaConsultas++;
    listaConsultas++;
    CPPUNIT_ASSERT_EQUAL(nomePaciente,(*listaConsultas));
}
void TesteClasseConsulta::RemarcaConsulta() { /*Testa marcar a consulta de um paciente com o mesmo medico.*/
    string nomePaciente = "Victor",nomeMedico = "Kelvin";/*E também, Pacientes com Médicos Inexistentes, e vice-versa*/
    Consulta* newconsulta = new Consulta();
    bool result = newconsulta->remarca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
     nomePaciente = "Victor";
    nomeMedico = "Charles";
    result = newconsulta->remarca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nomePaciente = "Bruno";
    nomeMedico = "Kelvin";
    result = newconsulta->remarca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nomePaciente = "Bruno";
    nomeMedico = "Charles";
    result = newconsulta->remarca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
}
void TesteClasseConsulta::RemarcaConsultaFailedMethod() { /*Testa remarcar a consulta de um paciente com o mesmo medico.*/
    string nomePaciente = "Victor",nomeMedico = "Joaquim";/*Só falha se não existir uma consulta pra aquele medico ou os campos nao exisitere*/
    Consulta* newconsulta = new Consulta();
    bool result = newconsulta->remarca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
     nomePaciente = "Joaquim";
    nomeMedico = "Charles";
    result = newconsulta->remarca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nomePaciente = "Bruno";
    nomeMedico = "Kelvin";
    result = newconsulta->cancela_consulta(nomePaciente,nomeMedico); //Cancelando uma consulta
    result = newconsulta->remarca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
    result = newconsulta->marca_consulta(nomePaciente,nomeMedico);// Remarcando aconsulta cancelada pra nao afetar outros testes
    nomePaciente = "Bruno";
    nomeMedico = "Charles";
    result = newconsulta->cancela_consulta(nomePaciente,nomeMedico); //Cancelando uma consulta
    result = newconsulta->remarca_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
    result = newconsulta->marca_consulta(nomePaciente,nomeMedico);// Remarcando aconsulta cancelada pra nao afetar outros testes
}
void TesteClasseConsulta::CancelaConsulta() {
    string nomePaciente = "Victor",nomeMedico = "Kelvin";
    Consulta* newconsulta = new Consulta();
    bool result = newconsulta->cancela_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nomePaciente = "Victor";
    nomeMedico = "Charles";
    result = newconsulta->cancela_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nomePaciente = "Bruno";
    nomeMedico = "Kelvin";
    result = newconsulta->cancela_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);
    nomePaciente = "Bruno";
    nomeMedico = "Charles";
    result = newconsulta->cancela_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(true,result);    
}
void TesteClasseConsulta::CancelaConsultaFailedMethod() { //Método falha quando nao existe consulta marcada pros campos
    string nomePaciente = "Victor",nomeMedico = "Kelvin"; // ou os campos sao invalidos.
    Consulta* newconsulta = new Consulta();
    bool result = newconsulta->cancela_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nomePaciente = "Victor";
    nomeMedico = "Charles";
    result = newconsulta->cancela_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nomePaciente = "Bruno";
    nomeMedico = "Kelvin";
    result = newconsulta->cancela_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);
    nomePaciente = "Bruno";
    nomeMedico = "Charles";
    result = newconsulta->cancela_consulta(nomePaciente,nomeMedico);
    CPPUNIT_ASSERT_EQUAL(false,result);    
}
void TesteClasseConsulta::ProcuraConsultaFailedMethod(){ //Falha quando nao existem consultas ou campos sao invalidos
    string nomePaciente = "Victor",nomeMedico = "Kelvin";
    Consulta* newconsulta = new Consulta();
    CPPUNIT_ASSERT_EQUAL(true,newconsulta->procura_consulta(nomePaciente,nomeMedico).empty());
    nomePaciente = "Victor";
    nomeMedico = "Charles";
    CPPUNIT_ASSERT_EQUAL(true,newconsulta->procura_consulta(nomePaciente,nomeMedico).empty());
    nomePaciente = "Bruno";
    nomeMedico = "Kelvin";
    CPPUNIT_ASSERT_EQUAL(true,newconsulta->procura_consulta(nomePaciente,nomeMedico).empty());
    nomePaciente = "Bruno";
    nomeMedico = "Charles";
    CPPUNIT_ASSERT_EQUAL(true,newconsulta->procura_consulta(nomePaciente,nomeMedico).empty());
}