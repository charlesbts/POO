/*
 * File:   TesteClasseConsulta.h
 * Author: KelvinEC
 *
 * Created on 17/02/2013, 17:09:17
 */

#ifndef TESTECLASSECONSULTA_H
#define	TESTECLASSECONSULTA_H

#include <cppunit/extensions/HelperMacros.h>

class TesteClasseConsulta : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(TesteClasseConsulta);

    CPPUNIT_TEST(MarcaConsulta);
    CPPUNIT_TEST(MarcaConsultaFailedMethod);
    CPPUNIT_TEST(ProcuraConsulta);
    CPPUNIT_TEST(RemarcaConsulta);
    CPPUNIT_TEST(RemarcaConsultaFailedMethod);
    CPPUNIT_TEST(CancelaConsulta);
    CPPUNIT_TEST(CancelaConsultaFailedMethod);
    CPPUNIT_TEST(ProcuraConsultaFailedMethod);
    CPPUNIT_TEST_SUITE_END();

public:
    TesteClasseConsulta();
    virtual ~TesteClasseConsulta();
    void setUp();
    void tearDown();

private:
    void MarcaConsulta();
    void MarcaConsultaFailedMethod();
    void ProcuraConsulta();
    void RemarcaConsulta();
    void RemarcaConsultaFailedMethod();
    void CancelaConsulta();
    void CancelaConsultaFailedMethod();
    void ProcuraConsultaFailedMethod();
    
};

#endif	/* TESTECLASSECONSULTA_H */

