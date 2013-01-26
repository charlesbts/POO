#ifndef CONSULTAS_H
#define CONSULTAS_H
#include <iostream>
using namespace std;

class Consulta {
private:
    string m_paciente;
    string m_medico;
    const int m_codigo;
public:
    Consulta(const int codigo);
    void marca_consulta();
    void procura_consulta();
    void remarca_consulta();
    void cancela_consulta();
    int incrementa_consulta(const int codigo);
    ~Consulta();
};
#endif
