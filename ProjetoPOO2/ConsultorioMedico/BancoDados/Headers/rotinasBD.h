#ifndef ROTINASBD_H
#define	ROTINASBD_H
#include "../../LogicaNegocio/Headers/classeMedico.h"
#include "BancoDados.h"

class Rotinas{
public:
    void insere_medico(Medico*);
    list<string> busca_medico(string nome);
    int deleta_medico(string nome);
};
#endif

