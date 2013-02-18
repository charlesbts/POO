/*
 * File:   TesteLogicaNegocio.h
 * Author: KelvinEC
 *
 * Created on 17/02/2013, 03:43:39
 */

#ifndef TESTECLASSEPACIENTE_H
#define	TESTECLASSEPACIENTE_H

#include <cppunit/extensions/HelperMacros.h>

class TesteClassePaciente : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TesteClassePaciente);
        
    CPPUNIT_TEST (InsercaoPaciente);
    CPPUNIT_TEST (InsercaoPacienteFailedMethod);
    CPPUNIT_TEST (PesquisaPaciente);
    CPPUNIT_TEST (AlteracaoCadastroPaciente);
    CPPUNIT_TEST (AlteracaoCadastroPacienteFailedMethod);        
    CPPUNIT_TEST (DelecaoPaciente);
    CPPUNIT_TEST (DelecaoPacienteFailedMethod);   
    CPPUNIT_TEST (PesquisaPacienteFailedMethod);
    
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

private:
   
    void InsercaoPaciente();
    void InsercaoPacienteFailedMethod();
    void PesquisaPaciente();
    void AlteracaoCadastroPaciente();
    void AlteracaoCadastroPacienteFailedMethod();
    void DelecaoPaciente();
    void DelecaoPacienteFailedMethod();
    void PesquisaPacienteFailedMethod();

};

#endif	/* TESTECLASSEPACIENTE_H */

