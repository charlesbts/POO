/*
 * File:   newtestclass.h
 * Author: KelvinEC
 *
 * Created on 16/02/2013, 23:56:39
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);
    
    CPPUNIT_TEST(InsercaoMedico);
    CPPUNIT_TEST(InsercaoPaciente);    
    CPPUNIT_TEST(DelecaoMedico);
    CPPUNIT_TEST(DelecaoPaciente);
    CPPUNIT_TEST(MarcaConsulta);
    CPPUNIT_TEST(DeletaConsulta);
    
    CPPUNIT_TEST_SUITE_END();

public:

    void setUp();
    void tearDown();

private:
    void InsercaoMedico();
    void InsercaoPaciente();
    void DelecaoMedico();
    void DelecaoPaciente();
    void MarcaConsulta();
    void DeletaConsulta();
};

#endif	/* NEWTESTCLASS_H */

