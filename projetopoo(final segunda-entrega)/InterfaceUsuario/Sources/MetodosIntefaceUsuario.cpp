#include <iostream>
#include "../Headers/classeInterfaceUsuario.h"
#include "../../LogicaNegocio/Headers/classeMedico.h"

/* Imprime o meno para o usuario*/
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
    cout << "19 - Listar todos os medicos de todos pacientes."<<endl;
    cout << "20 - Listar todas as consultas de um paciente."<<endl;
    cout << "21 - Listar todas as consultas de um medico."<<endl;
    cout << "22 - Listar pacientes cadastrados sem medico."<<endl;
    cout << "23 - Listar medicos cadastrados sem pacientes."<<endl;
    cout << "24 - SAIR."<<endl;
}
/*Loop pra capturar a opcao escolhida*/
void InterfaceUsuario::opcao_usuario(){
string opcaoUsuario;
    do{
    cout << "Favor escolher uma opcao: ";
    cin >> opcaoUsuario;
    cin.ignore();

        switch (atoi(opcaoUsuario.c_str())){
            case 1:
                this->cadastra_paciente();
            break;
            case 2:
                this->procura_paciente();
            break;
            case 3:
                this->atualiza_paciente();
            break;
            case 4:
                this->descadastra_paciente();
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
            case 9:
                this->marca_consulta();
            break;
            case 10:
                this->procura_consulta();
            break;
            case 11:
                this->remarcar_consulta();
            break;
            case 12:
                this->desmarca_consulta();
            break;
            case 13:
                this->lista_consultas_marcadas();
            break;
            case 14:
                this->lista_medicos_cadastrados();
            break;
            case 15:
                this->lista_pacientes_cadastrados();
            break;
            case 16:
                this->lista_pacientes_de_um_medico();
            break;
            case 17:
                this->lista_pacientes_de_todos_medicos();
            break;
            case 18:
                this->lista_medicos_de_um_paciente();
            break;
            case 19:
                this->lista_medicos_de_todos_pacientes();;
            break;
            case 20:
                this->lista_consultas_de_um_paciente();
            break;
            case 21:
                this->lista_consultas_de_um_medico();
            break;
            case 22:
                this->lista_pacientes_sem_medico();
            break;
            case 23:
                this->lista_medicos_sem_paciente();
            break;
            case 24:
            break;
            default:
                cout<<"OPCAO ESCOLHIDA NAO EXISTE."<<endl;
            break;
        }
    }while (opcaoUsuario!="24");
}
/*Pede ao usuario o Nome e a Especialidade do Medico, verifica se tem algum medico com esse nome ja cadastrado
 caso haja, retorna isso ao usuario, caso contrario passa os dados para a camada seguinte*/
void InterfaceUsuario::cadastra_medico(){
char nomeMedico[TAM_LINHA], especialidade[TAM_LINHA];
Medico *medico = new Medico();

    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
    cout<<"Insira a especialidade do medico: ";
    cin.getline(especialidade, TAM_LINHA);
        if (medico->cadastra_medico(string(nomeMedico),string(especialidade)))
        cout<<"MEDICO CADASTRADO COM SUCESSO."<<endl;
        else
        cout<<"ESTE MEDICO JA ESTA CADASTRADO."<<endl;
}
/* Recebe o nome do medico e verifica se existe. Caso exista efetua o descadastro e retorna uma mensagem
 de sucesso na operacao, caso contrário, imprime uma mensagem de que o medico nao existe*/
void InterfaceUsuario::descadastra_medico(){
char nomeMedico[TAM_LINHA];
Medico *medico = new Medico();

    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
        if (medico->descadastra_pessoa(string(nomeMedico)))
        cout<<"MEDICO DESCADASTRADO COM SUCESSO."<<endl;
        else
        cout<<"MEDICO NAO CADASTRADO."<<endl;
}
/* Pede ao usuario o nome do medico, faz uma busca pra atestar a existencia do medico, verificado isso efetua o descadastro
 logo apos pede o novo nome e nova especialidade, e realiza um novo cadastro */
void InterfaceUsuario::atualiza_medico(){
char nomeMedico[TAM_LINHA], novoNomeMedico[TAM_LINHA], especialidade[TAM_LINHA];
Medico *medico = new Medico();

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
/*Pede ao usuario o nome do medico a ser procurado, caso seja encontrado retorna os dados do medico,
 caso contrario, imprime uma mensagem da inexistencia do medico*/
void InterfaceUsuario::procura_medico(){
list<string> listaResultado;
char nomeMedico[TAM_LINHA];
Medico *medico = new Medico();

    cout<<"Insira o nome do medico a ser procurado: ";
    cin.getline(nomeMedico, TAM_LINHA);
    listaResultado = medico->procura_pessoa(string(nomeMedico));
        if (listaResultado.empty()){
        cout<<"MEDICO NAO CADASTRADO."<<endl;
        }
            for (list<string>::iterator listaMedico = listaResultado.begin(); listaMedico != listaResultado.end(); listaMedico++){
            cout<<*listaMedico<<": "; /* Nome coluna */
            listaMedico++;
            cout<<*listaMedico<<endl; /* Valor coluna */
            }
}
/*Lista todos os medicos cadastrados no sistema*/
void InterfaceUsuario::lista_medicos_cadastrados(){
Medico *medico = new Medico();
list<string> listaResultado;

    listaResultado = medico->lista_pessoas();
        if(listaResultado.empty())
        cout<<"NAO EXISTE MEDICO CADASTRADO."<<endl;
            for (list<string>::iterator listaMedico = listaResultado.begin(); listaMedico != listaResultado.end(); listaMedico++){
            cout<<*listaMedico<<": "; /* Nome coluna */
            listaMedico++;
            cout<<*listaMedico<<endl; /* Valor coluna */
            }
}
/* Pede ao usuario o nome, endereco, telefone e idade do paciente. Verifica se existe ou nao,
 caso nao exista efetua o cadastro, caso exista retorma uma mensagem dizendo que ja existe paciente cadastrado
 com aquele nome*/
void InterfaceUsuario::cadastra_paciente(){
char nomePaciente[TAM_LINHA], endereco[TAM_LINHA], telefone[TAM_LINHA];
string idade;
Paciente *paciente = new Paciente();

    cout<<"Insira o nome do paciente: ";
    cin.getline(nomePaciente, TAM_LINHA);
    cout<<"Insira o endereco do paciente: ";
    cin.getline(endereco, TAM_LINHA);
    cout<<"Insira o telefone do paciente: ";
    cin.getline(telefone, TAM_LINHA);
    cout<<"Insira a idade do paciente: ";
    cin>>idade;
        if (paciente->cadastra_paciente(string(nomePaciente), string(endereco), string(telefone), idade))
        cout<<"PACIENTE CADASTRADO COM SUCESSO."<<endl;
        else
        cout<<"ESTE PACIENTE JA ESTA CADASTRADO."<<endl;
}
/*Pede o nome do paciente a ser descadastrado, verifica se o mesmo existe, caso exista, efetua o descadastro,
 caso contrario, retorna uma mensagem dizendo que o paciente desejado nao existe*/
void InterfaceUsuario::descadastra_paciente(){
char nomePaciente[TAM_LINHA];
Paciente *paciente = new Paciente();

    cout<<"Insira o nome do paciente: ";
    cin.getline(nomePaciente, TAM_LINHA);
        if (paciente->descadastra_pessoa(string(nomePaciente)))
        cout<<"PACIENTE DESCADASTRADO COM SUCESSO."<<endl;
        else
        cout<<"PACIENTE NAO CADASTRADO."<<endl;
}
/*Pede ao usuario o nome do paciente, verifica se existe, caso exista, pede os novos dados,
 caso contrario retrna uma mensagem dizendo que o paciente nao existe*/
void InterfaceUsuario::atualiza_paciente(){
char nomePaciente[TAM_LINHA], novoNomePaciente[TAM_LINHA], endereco[TAM_LINHA], telefone[TAM_LINHA];
string idade;
Paciente *paciente = new Paciente();

    cout<<"Insira o nome do paciente: ";
    cin.getline(nomePaciente, TAM_LINHA);
        if ((paciente->procura_pessoa(nomePaciente)).empty()){
        cout<<"PACIENTE NAO CADASTRADO."<<endl;
        }
        else{
        cout<<"Insira o novo nome para o paciente: ";
        cin.getline(novoNomePaciente, TAM_LINHA);
        cout<<"Insira o novo endereco para o paciente: ";
        cin.getline(endereco, TAM_LINHA);
        cout<<"Insira o novo telefone para o paciente: ";
        cin.getline(telefone, TAM_LINHA);
        cout<<"Insira a nova idade para o paciente: ";
        cin>>idade;
        paciente->altera_cadastro(string(nomePaciente), string(novoNomePaciente), string(endereco), string(telefone), idade);
        cout<<"PACIENTE ATUALIZADO COM SUCESSO."<<endl;
        }
}
/*Pede ao usuario o nomed do paciente a ser procurado, caso exista, retorna os dados do paciente
 caso contrario retonra uma mensagem dizendo que o paciente nao existe*/
void InterfaceUsuario::procura_paciente(){
list<string> listaResultado;
char nomePaciente[TAM_LINHA];
Paciente *paciente = new Paciente();

    cout<<"Insira o nome do paciente a ser procurado: ";
    cin.getline(nomePaciente, TAM_LINHA);
    listaResultado = paciente->procura_pessoa(string(nomePaciente));
        if (listaResultado.empty()){
        cout<<"PACIENTE NAO CADASTRADO."<<endl;
        }
            for (list<string>::iterator listaPaciente = listaResultado.begin(); listaPaciente != listaResultado.end(); listaPaciente++){
            cout<<*listaPaciente<<": "; /* Nome coluna */
            listaPaciente++;
            cout<<*listaPaciente<<endl; /* Valor coluna */
            }
}
/*Lista todos os paciente cadastrados*/
void InterfaceUsuario::lista_pacientes_cadastrados(){
Paciente *paciente = new Paciente();
list<string> listaResultado;

    listaResultado = paciente->lista_pessoas();
        if(listaResultado.empty())
        cout<<"NAO EXISTE PACIENTE CADASTRADO."<<endl;
            for (list<string>::iterator listaPaciente = listaResultado.begin(); listaPaciente != listaResultado.end(); listaPaciente++){
            cout<<*listaPaciente<<": "; /* Nome coluna */
            listaPaciente++;
            cout<<*listaPaciente<<endl; /* Valor coluna */
            }
}
/*Pede ao usuario o Nome do Paciente e o Nome do medico desejado para a consulta, e verifica se os mesmos existem 
 no banco de dados, caso existam, marca a consulta*/
void InterfaceUsuario::marca_consulta(){
char nomePaciente[TAM_LINHA], especialidade[TAM_LINHA];
list<string> listaResultado;
Paciente *paciente = new Paciente();
Medico *medico = new Medico();
Consulta *consulta = new Consulta();

    cout<<"Insira o nome do paciente: ";
    cin.getline(nomePaciente, TAM_LINHA);
        if(paciente->procura_pessoa(string(nomePaciente)).empty()){
        cout<<"PACIENTE NAO CADASTRADO"<<endl;
        }
        else{
        cout<<"Insira a especialidade desejada na consulta: ";
        cin.getline(especialidade, TAM_LINHA);
            listaResultado = medico->procura_especialidade(string(especialidade));
            if(listaResultado.empty()){
            cout<<"NAO EXISTE MEDICO CADASTRADO COM ESSA ESPECIALIDADE."<<endl;
            }
            else{
            list<string>::iterator listaMedico = listaResultado.begin();
            listaMedico++; /* Valor da coluna medico */
            if (consulta->marca_consulta(string(nomePaciente), *listaMedico))
            cout<<"CONSULTA MARCADA COM SUCESSO."<<endl;
            else
            cout<<"ESSA CONSULTA JA FOI MARCADA."<<endl;
            }
        }
}
/*Pede ao usuario nome do medico e paciente e verifica se existem consultas marcadas*/
void InterfaceUsuario::procura_consulta(){
char nomePaciente[TAM_LINHA], nomeMedico[TAM_LINHA];
Consulta *consulta = new Consulta();
list<string> listaResultado;

    cout<<"Insira o nome do paciente: ";
    cin.getline(nomePaciente, TAM_LINHA);
    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
    listaResultado = consulta->procura_consulta(string(nomePaciente), string(nomeMedico));
    if (listaResultado.empty()){
        cout<<"CONSULTA NAO FOI MARCADA."<<endl;
        }
            for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
            cout<<*listaConsulta<<": "; /* Nome coluna */
            listaConsulta++;
            cout<<*listaConsulta<<endl; /* Valor coluna */
            }
}
/*Pede nome do medico e do paciente e verifica se existem consultas, caso exista , desmarca, caso contrario
 retorna uma mensagem dizendo que nao existem consultas marcadas*/
void InterfaceUsuario::desmarca_consulta(){
char nomePaciente[TAM_LINHA], nomeMedico[TAM_LINHA];
Consulta *consulta = new Consulta();

    cout<<"Insira o nome do paciente: ";
    cin.getline(nomePaciente, TAM_LINHA);
    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
        if(consulta->cancela_consulta(nomePaciente, nomeMedico))
        cout<<"CONSULTA DESMARCADA COM SUCESSO."<<endl;
        else
        cout<<"ESSA CONSULTA NAO FOI MARCADA."<<endl;
}
/*Pede nome do Paciente e do  medico, verifica a existencia da consulta, caso exista a remarca, caso contrario
 retorna uma mensagem dizendo que a consulta nao existe*/
void InterfaceUsuario::remarcar_consulta(){
char nomePaciente[TAM_LINHA], nomeMedico[TAM_LINHA];
Consulta *consulta = new Consulta();

    cout<<"Insira o nome do paciente: ";
    cin.getline(nomePaciente, TAM_LINHA);
    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
        if(consulta->remarca_consulta(nomePaciente, nomeMedico))
        cout<<"CONSULTA REMARCADA COM SUCESSO."<<endl;
        else
        cout<<"ESSA CONSULTA NAO FOI MARCADA"<<endl;
}
/*Lista todas as consultas marcadas*/
void InterfaceUsuario::lista_consultas_marcadas(){
Consulta *consulta = new Consulta();
list<string> listaResultado;

    listaResultado = consulta->lista_consultas();
        if (listaResultado.empty())
        cout<<"NENHUMA CONSULTA FOI MARCADA"<<endl;
        else{
        for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
            cout<<*listaConsulta<<": "; /* Nome coluna */
            listaConsulta++;
            cout<<*listaConsulta<<endl; /* Valor coluna */
            }
        }
}
/*Lista todos os pacientes de um Medico*/
void InterfaceUsuario::lista_pacientes_de_um_medico(){
char nomeMedico[TAM_LINHA];
Consulta *consulta = new Consulta();
list<string> listaResultado;

    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
    listaResultado = consulta->procura_pacientes_de_um_medico(nomeMedico);
        if (listaResultado.empty())
        cout<<"NAO EXISTE NENHUMA CONSULTA COM ESSE MEDICO."<<endl;
        else{
        for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
            cout<<*listaConsulta<<": "; /* Nome coluna */
            listaConsulta++;
            cout<<*listaConsulta<<endl; /* Valor coluna */
            }
        }
}
/*Lista todos os pacientes de todos os medicos*/
void InterfaceUsuario::lista_pacientes_de_todos_medicos(){
Medico *medico = new Medico();
Consulta *consulta = new Consulta();
list<string> listaResultado;
list<string> listaResultado2;

    listaResultado = medico->lista_pessoas();
        for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
        cout<<*listaConsulta<<" do Medico"<<": "; /* Nome coluna */
        listaConsulta++;
        listaResultado2 = consulta->procura_pacientes_de_um_medico(*listaConsulta); /* Colocando o nome do medico no metodo procura */
        cout<<*listaConsulta<<endl; /* Valor coluna */
        advance(listaConsulta,2); /* Pula a especialidade */
            for (list<string>::iterator listaConsulta = listaResultado2.begin(); listaConsulta != listaResultado2.end(); listaConsulta++){
            cout<<*listaConsulta<<": "; /* Nome coluna */
            listaConsulta++;
            cout<<*listaConsulta<<endl; /* Valor coluna */
            }
        }
}
/*Pede o nome do medico, verifica se existem consultas para o medico, caso exista, as imprime,
 caso contrario exibe uma mensagem dizendo que nao existem consultas marcadas para o medico*/
void InterfaceUsuario::lista_medicos_de_um_paciente(){
char nomePaciente[TAM_LINHA];
Consulta *consulta = new Consulta();
list<string> listaResultado;

    cout<<"Insira o nome do paciente: ";
    cin.getline(nomePaciente, TAM_LINHA);
    listaResultado = consulta->procura_medicos_de_um_paciente(nomePaciente);
        if (listaResultado.empty())
        cout<<"NAO EXISTE NENHUMA CONSULTA COM ESSE PACIENTE."<<endl;
        else{
        for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
            cout<<*listaConsulta<<": "; /* Nome coluna */
            listaConsulta++;
            cout<<*listaConsulta<<endl; /* Valor coluna */
            }
        }
}
/*Lista todas as consultas marcadas para todos os pacientes*/
void InterfaceUsuario::lista_medicos_de_todos_pacientes(){
Paciente *paciente = new Paciente();
Consulta *consulta = new Consulta();
list<string> listaResultado;
list<string> listaResultado2;

    listaResultado = paciente->lista_pessoas();
        for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
        cout<<*listaConsulta<<" do Paciente"<<": "; /* Nome coluna */
        listaConsulta++;
        listaResultado2 = consulta->procura_medicos_de_um_paciente(*listaConsulta); /* Colocando o nome do paciente no metodo procura */
        cout<<*listaConsulta<<endl; /* Valor coluna */
        advance(listaConsulta, 6); /* Pula endereco, telefone, idade */
            for (list<string>::iterator listaConsulta = listaResultado2.begin(); listaConsulta != listaResultado2.end(); listaConsulta++){
            cout<<*listaConsulta<<": "; /* Nome coluna */
            listaConsulta++;
            cout<<*listaConsulta<<endl; /* Valor coluna */
            }
        }
}
/*Lista todas as consultas de um determinado paciente fornecido pelo usuario*/
void InterfaceUsuario::lista_consultas_de_um_paciente(){
char nomePaciente[TAM_LINHA];
Consulta *consulta = new Consulta();
list<string> listaResultado;

    cout<<"Insira o nome do paciente: ";
    cin.getline(nomePaciente, TAM_LINHA);
    listaResultado = consulta->procura_consultas_paciente(nomePaciente);
        if(listaResultado.empty())
        cout<<"NENHUMA CONSULTA PARA ESSE PACIENTE."<<endl;
        else{
            for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
                cout<<*listaConsulta<<": "; /* Nome coluna */
                listaConsulta++;
                cout<<*listaConsulta<<endl; /* Valor coluna */
            }
        }
}
/*Lista as consultas de um determinado medico*/
void InterfaceUsuario::lista_consultas_de_um_medico(){
char nomeMedico[TAM_LINHA];
Consulta *consulta = new Consulta();
list<string> listaResultado;

    cout<<"Insira o nome do medico: ";
    cin.getline(nomeMedico, TAM_LINHA);
    listaResultado = consulta->procura_consultas_medico(nomeMedico);
        if(listaResultado.empty())
        cout<<"NENHUMA CONSULTA PARA ESSE MEDICO."<<endl;
        else{
            for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
                cout<<*listaConsulta<<": "; /* Nome coluna */
                listaConsulta++;
                cout<<*listaConsulta<<endl; /* Valor coluna */
            }
        }
}
/*Lista todos os pacientes que nao tem consultas marcadas*/
void InterfaceUsuario::lista_pacientes_sem_medico(){
Paciente *paciente = new Paciente();
Consulta *consulta = new Consulta();
list<string> listaResultado;
list<string> listaResultado2;

    listaResultado = paciente->lista_pessoas();
        for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
        listaConsulta++;
        listaResultado2 = consulta->procura_medicos_de_um_paciente(*listaConsulta); /* Colocando o nome do paciente no metodo procura */
            if (listaResultado2.empty()){
            cout<<"Paciente: "; /* Nome coluna */
            cout<<*listaConsulta<<endl; /* Valor coluna */
            }
            advance(listaConsulta, 6); /* Pula endereco, telefone, idade */
        }
        if(!listaResultado2.empty())
        cout<<"TODOS PACIENTES TEM MEDICOS PARA CONSULTAS."<<endl;
}
/*Lista todos os medicos que nao tem pacientes marcados*/
void InterfaceUsuario::lista_medicos_sem_paciente(){
Medico *medico = new Medico();
Consulta *consulta = new Consulta();
list<string> listaResultado;
list<string> listaResultado2;

    listaResultado = medico->lista_pessoas();
        for (list<string>::iterator listaConsulta = listaResultado.begin(); listaConsulta != listaResultado.end(); listaConsulta++){
        listaConsulta++;
        listaResultado2 = consulta->procura_pacientes_de_um_medico(*listaConsulta); /* Colocando o nome do medico no metodo procura */
            if (listaResultado2.empty()){
            cout<<"Medico: "; /* Nome coluna */
            cout<<*listaConsulta<<endl; /* Valor coluna */
            }
            advance(listaConsulta, 2); /* Pula especialidade */
        }
        if(!listaResultado2.empty())
        cout<<"TODOS MEDICO TEM PACIENTES PARA CONSULTAS."<<endl;
}
