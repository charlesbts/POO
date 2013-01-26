#include <iostream>
#include "../Headers/classeInterfaceUsuario.h"
#include "../../LogicaNegocio/Headers/classeMedico.h"

void InterfaceUsuario::cadastra_medico(){
string nomeMedico, especialidade;
Medico *objeto;

cout<<"Insira o nome do medico: ";
cin>>nomeMedico;
cout<<"Insira a especialidade do medico: ";
cin>>especialidade;
objeto->cadastra_medico(nomeMedico,especialidade);
}

void InterfaceUsuario::procura_pessoa(){
string nomePessoa;
Medico *objeto;
vector<vector<string> > dados;
cout<<"Insira o nome a ser procurado: ";
cin>>nomePessoa;
dados = objeto->procura_pessoa(nomePessoa);
for(vector<vector<string> >::iterator it = dados.begin(); it < dados.end(); ++it){
	    vector<string> row = *it;
	    cout << "NOME: " << row.at(0) <<"ESPECIALIDADE:" << row.at(1) << endl;
}
}
