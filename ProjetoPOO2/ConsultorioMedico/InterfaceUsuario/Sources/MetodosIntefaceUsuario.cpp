#include <iostream>
#include "../Headers/classeInterfaceUsuario.h"
#include "../../LogicaNegocio/Headers/classeMedico.h"

void InterfaceUsuario::menu_usuario(){
    cout << "*******************************************************************"<< endl;
    cout << "************* SISTEMA DE AJUDA AO CONSULTORIO *********************"<<endl;
    cout << "*******************************************************************"<<endl;
    cout << "Operacoes disponiveis:"<<endl;
    cout << "1 - Cadastrar paciente."<<endl;
    cout << "2 - Procurar paciente."<<endl;
    cout << "3 - Atualizar paciente."<<endl;
    cout << "4 - Descadastrar paciente."<<endl;
    cout << "5 - Cadastrar medico."<<endl;
    cout << "6 - Procurar medico."<<endl;
    cout << "7 - Atualizar medico."<<endl;
    cout << "8 - Descadastrar medico."<<endl;
    cout << "9 - Marcar consulta."<<endl;
    cout << "10 - Procurar consulta."<<endl;
    cout << "11 - Remarcar consulta."<<endl;
    cout << "12 - Cancelar consulta."<<endl;
    cout << "13 - Listar todas as consultas marcadas."<<endl;
    cout << "14 - Listar todos os medicos cadastrados."<<endl;
    cout << "15 - Listar todos os pacientes cadastrados."<<endl;
    cout << "16 - Listar todos os pacientes de um medico."<<endl;
    cout << "17 - Listar todos os pacientes de todos os medicos."<<endl;
    cout << "18 - Listar todos os medicos de um paciente."<<endl;
    cout << "19 - Listar todos os medicos de um paciente."<<endl;
    cout << "20 - Listar todas as consultas de um paciente."<<endl;
    cout << "21 - Listar todas as consultas de um paciente."<<endl;
    cout << "22 - Listar todas as consultas de um paciente."<<endl;
    cout << "23 - Listar medicos cadastrados sem pacientes."<<endl;
    cout << "24 - SAIR."<<endl;
}

void InterfaceUsuario::opcao_usuario(){
string opcaoUsuario;
    do{
    cout << "Favor escolher uma opcao: ";
    cin >> opcaoUsuario;
    cin.ignore();

        switch (atoi(opcaoUsuario.c_str())){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
                this->cadastra_medico();
            break;
            case 6:
                this->procura_medico();
            break;
            case 7:
                this->atualiza_medico();
            break;
            case 8:
                this->descadastra_medico();
            break;
            default:
                cout<<"OPCAO ESCOLHIDA NAO EXISTE."<<endl;
            break;
        }
    }while (opcaoUsuario!="24");
}

void InterfaceUsuario::cadastra_medico(){
char nomeMedico[TAM_LINHA], especialidade[TAM_LINHA];
Medico *medico;

    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
    cout<<"Insira a especialidade do medico: ";
    cin.getline(especialidade, TAM_LINHA);
    if (medico->cadastra_medico(string(nomeMedico),string(especialidade)))
    cout<<"MEDICO CADASTRADO COM SUCESSO."<<endl;
    else
    cout<<"ESTE MEDICO JA ESTA CADASTRADO."<<endl;
}

void InterfaceUsuario::descadastra_medico(){
char nomeMedico[TAM_LINHA];
Medico *medico;

    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
        if (medico->descadastra_pessoa(string(nomeMedico)))
        cout<<"MEDICO DESCADASTRADO COM SUCESSO."<<endl;
        else
        cout<<"MEDICO NAO CADASTRADO."<<endl;
}

void InterfaceUsuario::atualiza_medico(){
char nomeMedico[TAM_LINHA], novoNomeMedico[TAM_LINHA], especialidade[TAM_LINHA];
Medico *medico;

    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
        if ((medico->procura_pessoa(nomeMedico)).empty()){
        cout<<"MEDICO NAO CADASTRADO."<<endl;
        }
        else{
        cout<<"Insira o novo nome para o medico: ";
        cin.getline(novoNomeMedico, TAM_LINHA);
        cout<<"Insira a nova especialidade para o medico: ";
        cin.getline(especialidade, TAM_LINHA);
        medico->altera_cadastro(string(nomeMedico), string(novoNomeMedico), string(especialidade));
        cout<<"MEDICO ATUALIZADO COM SUCESSO."<<endl;
        }
}

void InterfaceUsuario::procura_medico(){
list<string> listaResultado;
char nomeMedico[TAM_LINHA];
Medico *medico;

    cout<<"Insira o nome do medico a ser procurado: ";
    cin.getline(nomeMedico, TAM_LINHA);
    listaResultado = medico->procura_pessoa(string(nomeMedico));
        if (listaResultado.empty()){
        cout<<"MEDICO NAO CADASTRADO."<<endl;
        }
            for (list<string>::iterator it = listaResultado.begin(); it != listaResultado.end(); it++){
            cout<<*it<<": "; /* Nome coluna */
            it++;
            cout<<*it<<endl; /* Valor coluna */
            }
}
