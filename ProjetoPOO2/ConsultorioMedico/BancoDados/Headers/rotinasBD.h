#ifndef ROTINASBD_H
#define	ROTINASBD_H
#include "../../LogicaNegocio/Headers/classeMedico.h"
#include "BancoDados.h"

class Rotinas{
public:
    void insere_medico(Medico*);
    vector<vector<string> > busca_tabela(string nome, string tabela);
    char* conversor_string_to_char(string);

};
#endif

