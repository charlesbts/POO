/*
 * File:   TesteClasseMedico.h
 * Author: KelvinEC
 *
 * Created on 17/02/2013, 14:33:42
 */

#ifndef TESTECLASSEMEDICO_H
#define	TESTECLASSEMEDICO_H

#include <cppunit/extensions/HelperMacros.h>

class TesteClasseMedico : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TesteClasseMedico);

    CPPUNIT_TEST (InsercaoMedico);
    CPPUNIT_TEST (InsercaoMedicoFailedMethod);
    CPPUNIT_TEST (PesquisaMedico);
    CPPUNIT_TEST (AlteracaoCadastroMedico);
    CPPUNIT_TEST (AlteracaoCadastroMedicoFailedMethod);
    CPPUNIT_TEST (DelecaoMedico);
    CPPUNIT_TEST (DelecaoMedicoFailedMethod);
    CPPUNIT_TEST (PesquisaMedicoFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:

    void setUp();
    void tearDown();

private:
    void InsercaoMedico();
    void InsercaoMedicoFailedMethod();
    void PesquisaMedico();
    void AlteracaoCadastroMedico();
    void AlteracaoCadastroMedicoFailedMethod();
    void DelecaoMedico();
    void DelecaoMedicoFailedMethod();
    void PesquisaMedicoFailedMethod();
};

#endif	/* TESTECLASSEMEDICO_H */

