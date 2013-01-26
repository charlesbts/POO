/*
*   Organização de Arquivos - Trabalho 1
*   Alunos: Bruno Ribeiro das Virgens (11/0111141)
*           Charles Cardoso de Oliveira (11/0112679)
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcoes_def.h"
#include "convencoes.h"

/* Protótipos de funções da interface */
char escolhe_lista();
char escolhe_operacao(char);
void opera(char, char);

/* Função main */
int main() {
    char opcaoMenu = CTE_OPPADRAO, opcaoLista = CTE_OPPADRAO, opcaoInicializar;
    int controle;
    /* Modo de inicialização do programa: primeira rodagem ou não? */
    printf("Esta e a primeira vez que o programa e rodado? (S/N)\n");
    printf("(S para reconstruir os arquivos e inicializar o programa)\n");
    printf("(N para somente verificar a existencia das listas)\n");
    scanf("%c", &opcaoInicializar);
    getchar();
    /* Inicialização do programa, com a checagem e inicialização dos arquivos necessários ao projeto */
    opcaoInicializar = toupper(opcaoInicializar);
    if(opcaoInicializar == 'S')
        controle = inicializa_programa(1);
    else
        controle = inicializa_programa(0);
    if(controle == SUC_FUNCAO)
        while(opcaoMenu != '0') {
                opcaoLista = CTE_OPPADRAO;
                opcaoMenu = escolhe_lista();
                if(opcaoMenu == '1' || opcaoMenu == '2')
                    while(opcaoLista != '0') {
                        opcaoLista = escolhe_operacao(opcaoMenu);
                        opera(opcaoMenu, opcaoLista);
                    }
                else if(opcaoMenu == '3')
                    controle = intercala("lista1.txt", "lista2.txt");
                else if(opcaoMenu != '0') {
                    printf("Opcao invalida! Aperte <enter> para continuar.\n");
                    getchar();
                }

            }
    else {
        printf("Por favor, verifique se as listas estao na pasta correta.\n");
        return INX_ARQUIVO;
    }
    return SUC_FUNCAO;
}

/* Menu para escolha de lista */
char escolhe_lista() {
    char opcaoMenu;
    printf("--------------------------------------------\n");
    printf("Menu Principal\n");
    printf("--------------------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Manipular a primeira lista\n");
    printf("2 - Manipular a segunda lista\n");
    printf("3 - Intercalar as listas\n");
    printf("Opcao: ");
    scanf("%c", &opcaoMenu);
    getchar();
    return opcaoMenu;
}

/* Menu para escolha de operação de lista */
char escolhe_operacao(char numLista) {
    char opcaoLista;
    printf("--------------------------------------------\n");
    printf("Operacoes com a Lista %c\n", numLista);
    printf("--------------------------------------------\n");
    printf("0 - Voltar\n");
    printf("1 - Criar arquivo de indices primarios\n");
    printf("2 - Criar arquivos de indices secundarios de OP\n");
    printf("3 - Criar arquivos de indices secundarios de Turma\n");
    printf("4 - Inserir registro\n");
    printf("5 - Excluir registro\n");
    printf("6 - Atualizar registro\n");
    printf("7 - Mostrar o arquivo de Registros\n");
    printf("8 - Reconstruir todos os indices\n");
    printf("--------------------------------------------\n");
    printf("Opcao: ");
    scanf("%c", &opcaoLista);
    getchar();
    return opcaoLista;
}

/* Direcionador do programa */
void opera(char opcaoMenu, char opcaoLista) {
    char listak[] = "listak.txt",
         ledk[] = "led_listak.txt",
         indicePrimariok[] = "indiceprimariok.ind",
         indiceChavesSecundariask[] = "idx_secundariakxy.ind",
         indiceLabelIDk[] = "lid_secundariakxy.ind";
    int controle;
    RegistroLIS restoObj;
    char restoStr[TAM_CHAVEPRI];
    /* Atribuições de nome */
    listak[5] = opcaoMenu;
    indicePrimariok[14] = opcaoMenu;
    indiceChavesSecundariask[14] = opcaoMenu;
    indiceLabelIDk[14] = opcaoMenu;
    ledk[9] = opcaoMenu;
    /* Switch principal */
    switch(opcaoLista) {
        case '0':
            break;
        case '1':
            /* Cria índice prim�rio */
            controle = indice_primario(listak, indicePrimariok);
            if(controle == SUC_FUNCAO)
                printf("Indice Primario da lista %c criado com sucesso!\n", opcaoMenu);
            break;
        case '2':
            /* Cria índice secund�rio de OP */
            indiceChavesSecundariask[15] = 'o';
            indiceLabelIDk[15] = 'o';
            indiceChavesSecundariask[16] = 'p';
            indiceLabelIDk[16] = 'p';
            controle = indice_secundario(listak, indicePrimariok, indiceChavesSecundariask, indiceLabelIDk, 50);
            if(controle == SUC_FUNCAO)
                printf("Indice Secundario de OP da lista %c criado com sucesso!\n", opcaoMenu);
            break;
        case '3':
            /* Cria índice secundário de Turma */
            indiceChavesSecundariask[15] = 't';
            indiceLabelIDk[15] = 't';
            indiceChavesSecundariask[16] = 'r';
            indiceLabelIDk[16] = 'r';
            controle = indice_secundario(listak, indicePrimariok, indiceChavesSecundariask, indiceLabelIDk, 64);
            if(controle == SUC_FUNCAO)
                printf("Indice Secundario de Turma da lista %c criado com sucesso!\n", opcaoMenu);
            break;
        case '4':
            /* Insere registro */
            controle = inclui_registro(listak, ledk, indicePrimariok, &restoObj, 0);
            if(controle == SUC_FUNCAO) {
                reconstroi_indice(listak, indicePrimariok, indiceChavesSecundariask, indiceLabelIDk);
                printf("Registro inserido com sucesso!\n");
            }
            else
                printf("Registro ja existente!\n");
            break;
        case '5':
            /* Remove registro */
            controle = exclui_registro(listak, ledk, indicePrimariok, restoStr, 0);
            if(controle == SUC_FUNCAO) {
                reconstroi_indice(listak, indicePrimariok, indiceChavesSecundariask, indiceLabelIDk);
                printf("Registro excluido com sucesso!\n");
            }
            else
                printf("Registro nao encontrado!\n");
            break;
        case '6':
            /* Atualiza registro */
            controle = atualiza_registro(listak, ledk, indicePrimariok);
            if(controle == SUC_FUNCAO)
                printf("Registro atualizado com sucesso!\n");
            else
                printf("Registro nao encontrado!\n");
            break;
        case '7':
            /* Mostra o arquivo de indices registros */
            controle = visualiza_registros(listak);
            break;
        case '8':
            /* Reconstroi todos os arquivos de indice */
            controle = reconstroi_indice(listak, indicePrimariok, indiceChavesSecundariask, indiceLabelIDk);
            break;
        case '9':
            controle = intercala("lista1.txt", "lista2.txt");
            break;
        default:
            printf("Operacao invalida! Tente novamente.\n");
    }
}
