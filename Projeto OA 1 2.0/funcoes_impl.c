/* Definição de módulo-servidor */
#define FUN_IMPL

/* Includes */
#include "funcoes_def.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* IMPLEMENTAÇÕES */

/* ARQUIVOS */

/* Inicializa todos os arquivos necessários
* Esta função permite que não sejam feitas as checagens dos arquivos abertos ao longo da execução
*/
int inicializa_programa(int versao) {
    /* Declaração de variáveis */
    FILE *inicializador;
    /* Arquivos principais (lista1.txt, lista2.txt) */
    inicializador = fopen("lista1.txt", "r");
    if(inicializador == NULL) {
        fclose(inicializador);
        return INX_ARQUIVO;
    }
    fclose(inicializador);
    inicializador = fopen("lista2.txt", "r");
    if(inicializador == NULL) {
        fclose(inicializador);
        return INX_ARQUIVO;
    }
    fclose(inicializador);
    /* Arquivos gerados pelo programa */
    if(versao) {
        /* LEDs das listas */
        inicializador = fopen("led_lista1.txt", "w");
        fprintf(inicializador, "%s\n", CTE_FIMLISTA);
        fclose(inicializador);
        inicializador = fopen("led_lista2.txt", "w");
        fprintf(inicializador, "%s\n", CTE_FIMLISTA);
        fclose(inicializador);
        /* Índices primários */
        inicializador = fopen("indiceprimario1.ind", "a");
        fclose(inicializador);
        inicializador = fopen("indiceprimario2.ind", "a");
        fclose(inicializador);
        /* Índices secundários de OP */
        inicializador = fopen("idx_secundaria1op.ind", "a");
        fclose(inicializador);
        inicializador = fopen("idx_secundaria2op.ind", "a");
        fclose(inicializador);
        /* Label IDs de OP */
        inicializador = fopen("lid_secundaria1op.ind", "a");
        fclose(inicializador);
        inicializador = fopen("lid_secundaria2op.ind", "a");
        fclose(inicializador);
        /* Índices secundários de Turma */
        inicializador = fopen("idx_secundaria1tr.ind", "a");
        fclose(inicializador);
        inicializador = fopen("idx_secundaria2tr.ind", "a");
        fclose(inicializador);
        /* Label IDs de Turma */
        inicializador = fopen("lid_secundaria1tr.ind", "a");
        fclose(inicializador);
        inicializador = fopen("lid_secundaria1tr.ind", "a");
        fclose(inicializador);
    }
    return SUC_FUNCAO;

}

/* Cria indice primário */
int indice_primario(char *nomeLista, char *nomeIndicePrimario) {
    /* Declaração de variáveis */
    int contagem = 0;
    char linha[TAM_REGLISTA], chave[TAM_CHAVEPRI];
    FILE *arqLista, *arqIndicePrimario;
    arqLista = fopen(nomeLista, "r");
    arqIndicePrimario = fopen(nomeIndicePrimario, "w");
    /* Monta e insere chaves primárias no arquivo final */
    while(!feof(arqLista)) {
        fgets(linha, TAM_REGLISTA, arqLista);
        if(linha[0] != '*') {
            cria_chave_primaria(linha, chave);
            /* Insere no arquivo de índices */
                if(!feof(arqLista))
                    fprintf(arqIndicePrimario, "%.30s\t%.4d\n", chave, contagem * TAM_REGLISTA);
                contagem++;
        }
        else
            contagem++;
    }
    fclose(arqLista);
    fclose(arqIndicePrimario);
    /* Ordena o arquivo recém-criado */
    ordena_indice_primario(nomeIndicePrimario);
    return SUC_FUNCAO;
}

/* Cria índice secundário
* CS: Chave Secundária; LID: Label ID
*/
int indice_secundario(char *nomeLista, char *nomeIndicePrimario, char *nomeIndiceCS, char *nomeIndiceLID, int offset) {
    /* Declarações */
    FILE *arqLista, *arqIndicePrimario, *arqIndiceCS, *arqIndiceLID;
    RegistroGER *listaIndiceCS, *listaIndiceLID, *temporario;
    char linha[TAM_REGLISTA], chavePrimaria[TAM_CHAVEPRI], chaveSecundaria[3];
    int i = 0, controle, byteOffset;
    /* Abrir arquivos */
    arqLista = fopen(nomeLista, "r");
    arqIndicePrimario = fopen(nomeIndicePrimario, "r");
    arqIndiceCS = fopen(nomeIndiceCS, "w");
    arqIndiceLID = fopen(nomeIndiceLID, "w");
    listaIndiceCS = inicializa_lista();
    listaIndiceLID = inicializa_lista();
    /* Monta o arquivo de Label ID */
    while(!feof(arqLista)) {
        fgets(linha, TAM_REGLISTA, arqLista);
        if(linha[0] != '*') {
            controle = cria_chave_primaria(linha, chavePrimaria);
            chaveSecundaria[0] = linha[offset];
            chaveSecundaria[1] = linha[offset + 1];
            chaveSecundaria[2] = '\0';
            byteOffset = busca_lista(listaIndiceCS, chaveSecundaria);
            if(byteOffset == INX_REGISTRO) {
                listaIndiceLID = insere_lista(listaIndiceLID, chaveSecundaria, chavePrimaria, i * TAM_REGCHAVE);
                listaIndiceCS = insere_lista(listaIndiceCS, chaveSecundaria, chavePrimaria, i * TAM_REGCHAVE);
                fprintf(arqIndiceLID, "%.30s\t%s\n", chavePrimaria, CTE_FIMLISTA);
            }
            else {
                listaIndiceLID = insere_lista(listaIndiceLID, chaveSecundaria, chavePrimaria, i * TAM_REGCHAVE);
                atualiza_lista(listaIndiceCS, chaveSecundaria, i * TAM_REGCHAVE);
                fprintf(arqIndiceLID, "%.30s\t%.4d\n", chavePrimaria, byteOffset);
            }
            i++;
        }
        else
            i++;
    }
    /* Monta o arquivo de Chaves Secundárias */
    for(temporario = listaIndiceCS; temporario != NULL; temporario = temporario->proximo)
        fprintf(arqIndiceCS, "%.30s\t%.4d\n", temporario->chaveSecundaria, temporario->byteOffset); /* Imprime o byte offset do topo da lista */
    fclose(arqLista);
    fclose(arqIndicePrimario);
    fclose(arqIndiceCS);
    fclose(arqIndiceLID);
    libera_lista(listaIndiceCS);
    libera_lista(listaIndiceLID);
    return SUC_FUNCAO;
}

/* Monta chave primária a partir de uma string desorganizada */
int cria_chave_primaria(char *chaveOriginal, char *chavePrimaria) {
    char temp;
    int i = 0, j = 0;
    /* i controla a passagem atual, j controla o tamanho final da string (que deve ser de exatamente 30 caracteres) */
    do {
        temp = chaveOriginal[j];
        /* converte espacos em underscores */
        if(temp == ' ') {
            chavePrimaria[i] = '_';
            i++;
        }
        /* Ignora pipelines e espacos, e passa os caracteres que sao letras para maiusculo */
        if(temp != '|' && temp != ' ') {
            if(isalpha(temp))
                temp = toupper(temp);
            chavePrimaria[i] = temp;
            i++;
        }
        j++;
    } while(j < TAM_CHAVEPRI);
    /* Completa com underscores, caso a string nao tenha os 30 caracteres */
    if(strlen(chavePrimaria) < TAM_CHAVEPRI)
        for(i = strlen(chavePrimaria); i < TAM_CHAVEPRI - 1; i++)
            chavePrimaria[i] = '_';
    /* Atribui o final da string */
    chavePrimaria[TAM_CHAVEPRI - 1] = '\0';
    return SUC_FUNCAO;
}

/* Função auxiliar que combina um nome e uma matrícula em chave primária */
int combina_string(char *entradaMatricula, char *entradaNome, char *chaveFormatada) {
    /* Declaração de variáveis */
    int controle;
    char chaveDesformatada[TAM_REGCHAVE];
    char matricula[TAM_MATRICULA + 1], nome[TAM_NOME];
    /* Atribui '\0' ao final da string (obrigatoriamente) e '_' sendo o último caracter efetivo (conforme o formato de chave primária) */
    strcpy(matricula, entradaMatricula);
    strcpy(nome, entradaNome);
    matricula[TAM_MATRICULA] = '\0';
    matricula[TAM_MATRICULA - 1] = '_';
    /* Monta a chave desformatada e, por fim, a chave primária */
    strcpy(chaveDesformatada, matricula);
    strcat(chaveDesformatada, nome);
    controle = cria_chave_primaria(chaveDesformatada, chaveFormatada);
    return SUC_FUNCAO;
}

/* Realiza a ordenação por heap sort
* Os parâmetros de entrada devem ser o Vetor, (tamanho do Vetor)-1 e o tamanho do índice que se deseja ordenar (TAM_CHAVEPRI ou TAM_CHAVESEC) */
int heap_sort(RegistroGER *registro, int tamanhoVetor, int indice) {
    int i, controle;
    RegistroGER temp;
    build_heap(registro, tamanhoVetor, indice);
    for (i = tamanhoVetor; i >= 1; i--) {
        temp = registro[0];
        registro[0] = registro[i];
        registro[i] = temp;
        tamanhoVetor--;
        controle = max_heap(registro, 0, tamanhoVetor, indice);
    }
    return controle;
}

/* Função auxiliar da heap_sort para construir a heap */
int build_heap(RegistroGER *registro, int tamanhoVetor, int indice) {
    int i, controle;
    for(i = (int) tamanhoVetor / 2; i >= 0; i--)
        controle = max_heap(registro, i, tamanhoVetor, indice);
    return controle;
}

/* Função auxiliar da build_sort para construir a heap */
int max_heap(RegistroGER *registro, int indiceVetor, int tamanhoVetor, int indice){
    int esquerda = (2 * indiceVetor), direita = (2 * indiceVetor + 1);
    int maior, controle;
    RegistroGER temp;
    if (esquerda >= 0 && esquerda <= tamanhoVetor && strcoll(registro[esquerda].chavePrimaria, registro[indiceVetor].chavePrimaria) > 0)
        maior = esquerda;
    else
        maior = indiceVetor;
    if (direita <= tamanhoVetor && direita >= 0 && strcoll(registro[direita].chavePrimaria, registro[maior].chavePrimaria) > 0)
        maior = direita;
    if (maior != indiceVetor) {
        temp = registro[indiceVetor];
        registro[indiceVetor] = registro[maior];
        registro[maior] = temp;
        controle = max_heap(registro, maior, tamanhoVetor, indice);
    }
    return SUC_FUNCAO;
}

/* Visualiza um arquivo de índices baseado no tipo de entrada */
int visualiza_indice(char *nomeIndice, int tipo) {
    /* Declarações */
    FILE *arqIndice;
    RegistroGER registro;
    registro.proximo = NULL;
    /* Abertura de arquivos */
    arqIndice = fopen(nomeIndice, "r");
    printf("\n--------------------------------------------");
    if(!tipo) { /* 0 indica índice primário */
         printf("\nARQUIVO DE INDICES PRIMARIOS");
         do {
             fscanf(arqIndice, "%s", registro.chavePrimaria);
             fscanf(arqIndice, "%d", &(registro.byteOffset));
             if(!feof(arqIndice))
                printf("\nChave Primaria: %s\tByte Offset: %d", registro.chavePrimaria, registro.byteOffset);
        } while(!feof(arqIndice));
    }
    else {
        printf("\nARQUIVO DE INDICES SECUNDARIOS");
         do {
            fscanf(arqIndice, "%s", registro.chaveSecundaria);
            fscanf(arqIndice, "%d", &(registro.byteOffset));
            if(!feof(arqIndice))
                printf("Chave Secundaria: %s\tByte Offset: %d", registro.chaveSecundaria, registro.byteOffset);
        } while(!feof(arqIndice));
    }
    printf("\n--------------------------------------------\n");
    fclose(arqIndice);
    return SUC_FUNCAO;
}

/* Visualiza um arquivo de registros */
int visualiza_registros(char *nomeLista) {
    FILE *arqLista;
    char linha[TAM_REGLISTA];
    arqLista = fopen(nomeLista, "r");
    printf("\n--------------------------------------------");
    printf("\nARQUIVO DE INDICES PRIMARIOS");
    printf("\nMatricula\tNome\t\t\t\tOP\tCurso\tTurma\n");
    do {
        fgets(linha, TAM_REGLISTA, arqLista);
        if(linha[0] != '*' && !feof(arqLista)) /* Se não estiver desabilitado */
            printf("\n%s", linha);
    } while(!feof(arqLista));
    printf("\n--------------------------------------------\n");
    fclose(arqLista);
    return SUC_FUNCAO;
}

/* Separação do input de dados */
int preenche_registro(RegistroLIS *objeto, char *chavePrimaria, int modo) {
    /* Declaração de variáveis */
    int controle;
    char nome[TAM_NOME], matricula[TAM_MATRICULA];
    /* Captura os dados essenciais à montagem da chave primária */
    printf("Digite o nome (%d caracteres): ", TAM_NOME - 1);
    gets(objeto->nome);
    printf("Digite a matricula (%d caracteres): ", TAM_MATRICULA - 1);
    gets(objeto->matricula);
    if(!modo) { /* 0 indica atualização ou cadastro */
        /* Captura os restantes dos dados */
        printf("Digite o OP (%d caracteres): ", TAM_OP - 1);
        gets(objeto->op);
        printf("Digite o curso (%d caracter): ", TAM_CURSO - 1);
        gets(objeto->curso);
        printf("Digite a turma (%d caracteres): ", TAM_TURMA);
        gets(objeto->turma);
    }
    strcpy(nome, objeto->nome);
    strcpy(matricula, objeto->matricula);
    /* Combina a matricula e o nome em chave primária */
    controle = combina_string(objeto->matricula, objeto->nome, chavePrimaria);
    return controle;
}

/* Inclui um registro, atualizando os índices primário e secundário */
int inclui_registro(char *nomeLista, char *nomeLED, char *nomeIndicePrimario, RegistroLIS *objeto, int atualiza) {
    /* Declaração de variáveis */
    FILE *arqLista;
    LED *listaInvertida;
    RegistroGER *registro;
    RegistroLIS linha;
    char chaveFormatada[TAM_CHAVEPRI];
    int tamanho = 0, posicao, byteOffset, i;
    /* Verifica se esta no modo de atualizacao do registro */
    if(!atualiza)
        preenche_registro(&linha, chaveFormatada, 0);
    else {
        strcpy(linha.matricula, objeto->matricula);
        strcpy(linha.nome, objeto->nome);
        strcpy(linha.op, objeto->op);
        strcpy(linha.curso, objeto->curso);
        strcpy(linha.turma, objeto->turma);
    }
    listaInvertida = inicializa_led();
    arqLista = fopen(nomeLista, "r+");
    /* Verifica se o registro existe */
    registro = converte_arquivo(nomeIndicePrimario, &tamanho);
    posicao = busca_binaria(registro, tamanho, chaveFormatada);
    if(posicao == INX_REGISTRO) {
        /* Preenche a lista de espacos disponiveis e retira o primeiro espaco */
        listaInvertida = preenche_led(listaInvertida, nomeLED);
        listaInvertida = pop_led(listaInvertida, &byteOffset);
        if(byteOffset == CTE_FIMLISTAI)
            /* Se nao existirem espacos livres, vai até o final do arquivo e insere o registro */
            fseek(arqLista, tamanho * TAM_REGLISTA - 1, SEEK_SET);
        else
            /* Se existirem, vai até última posição excluída */
            fseek(arqLista, posicao, SEEK_SET);
        /* Imprime os campos */
        fprintf(arqLista, "%.6s ", linha.matricula);
        fprintf(arqLista, "|%s", linha.nome);
        for(i = strlen(linha.nome); i < TAM_NOME; i++)
            fprintf(arqLista, " ");
        fprintf(arqLista, "|%.2s  ", linha.op);
        fprintf(arqLista, "|%.1s       ", linha.curso);
        fprintf(arqLista, "|%.2s", linha.turma);
        if(byteOffset == CTE_FIMLISTAI)
            fprintf(arqLista, "\n");
        /* Se nao houverem espacos disponiveis, insere a constante de fim de lista na LED */
        if(listaInvertida == NULL)
            listaInvertida = insere_led_inicio(listaInvertida, CTE_FIMLISTAI);
        retorna_led(listaInvertida, nomeLED);
    }
    else {
        fclose(arqLista);
        return JEX_REGISTRO;
    }
    fclose(arqLista);
    return SUC_FUNCAO;
}

/* Exclui um registro, atualizando os índices primário e secundário */
int exclui_registro(char *nomeLista, char *nomeLED, char *nomeIndicePrimario, char *chaveObjeto, int atualiza) {
    /* Declaração de variáveis */
    FILE *arqLista, *arqLED;
    RegistroGER *registro;
    LED *listaInvertida;
    RegistroLIS linha;
    char chaveFormatada[TAM_CHAVEPRI + 1], resto[10];
    int tamanho = 0, posicao;
    /* Captura os dados */
    if(!atualiza) /* atualiza = 1 indica atualizacao de registro, em vez de exclusão */
        preenche_registro(&linha, chaveFormatada, 1);
    else
        strcpy(chaveFormatada, chaveObjeto);
    /* Abertura dos arquivos */
    arqLista = fopen(nomeLista, "r+");
    arqLED = fopen(nomeLED, "r+");
    /* Realiza a busca desta chave */
    registro = converte_arquivo(nomeIndicePrimario, &tamanho);
    posicao = busca_binaria(registro, tamanho, chaveFormatada);
    /* Caso o registro exista, exclui */
    if(posicao != INX_REGISTRO) {
        /* Procura pelo registro e armazena os dados armazenados anteriormente */
        fseek(arqLista, registro[posicao].byteOffset, SEEK_SET);
        fgets(linha.matricula, TAM_MATRICULA, arqLista);
        fgets(resto, 2, arqLista);
        fgets(linha.nome, TAM_NOME, arqLista);
        fgets(resto, 2, arqLista);
        fgets(linha.op, TAM_INDSECUND, arqLista);
        fgets(resto, 3, arqLista);
        fgets(linha.curso, TAM_CURSO, arqLista);
        fgets(resto, 8, arqLista);
        /* Procura novamente pelo registro e o desabilita */
        fgets(linha.turma, TAM_INDSECUND, arqLista);
        fseek(arqLista, registro[posicao].byteOffset, SEEK_SET);
        fprintf(arqLista, "*");
        fclose(arqLista);
        /* Atualiza a lista associada */
        listaInvertida = inicializa_led();
        listaInvertida = preenche_led(listaInvertida, nomeLED);
        listaInvertida = insere_led_inicio(listaInvertida, registro[posicao].byteOffset);
        retorna_led(listaInvertida, nomeLED);
    }
    /* Caso o registro não exista, retorna um erro avisando da inexistência do registro */
    else {
        fclose(arqLista);
        fclose(arqLED);
        return INX_REGISTRO;
    }

    fclose(arqLED);
    return SUC_FUNCAO;
}

/** \brief Funcao para reconstruir totalmente o indice primario e todos os indices secundarios de uma lista */
int reconstroi_indice(char *listak, char *indicePrimariok, char *indiceChavesSecundariask, char *indiceLabelIDk) {
    int controle;
    /* Imprime o indice primario antes de refazê-lo por completo */
    controle = visualiza_indice(indicePrimariok, 0);
    controle = indice_primario(listak, indicePrimariok);
    /* Imprime o indice primario após refazê-lo */
    controle = visualiza_indice(indicePrimariok, 0);
    /* Atribui os nomes dos arquivos de chave secundaria e recria-os a partir do novo indice primario */
    indiceChavesSecundariask[15] = 'o';
    indiceLabelIDk[15] = 'o';
    indiceChavesSecundariask[16] = 'p';
    indiceLabelIDk[16] = 'p';
    controle = indice_secundario(listak, indicePrimariok, indiceChavesSecundariask, indiceLabelIDk, 50);
    indiceChavesSecundariask[15] = 't';
    indiceLabelIDk[15] = 't';
    indiceChavesSecundariask[16] = 'r';
    indiceLabelIDk[16] = 'r';
    controle = indice_secundario(listak, indicePrimariok, indiceChavesSecundariask, indiceLabelIDk, 64);
    return SUC_FUNCAO;
}

/* Realiza a ordenação do índice primário passado */
int ordena_indice_primario(char *nomeIndicePrimario) {
    FILE *arqIndicePrimario;
    RegistroGER *registro;
    int tamanho, controle, i;
    /* Carrega o arquivo para a memória e ordena */
    registro = converte_arquivo(nomeIndicePrimario, &tamanho);
    controle = heap_sort(registro, tamanho - 1, TAM_CHAVEPRI);
    arqIndicePrimario = fopen(nomeIndicePrimario, "w");
    /* Imprime o resultado ordenado de volta */
    for(i = 0; i <= tamanho - 1; i++)
        if(registro[i].byteOffset != CTE_FIMLISTAI)
            fprintf(arqIndicePrimario, "%.30s\t%.4d\n", registro[i].chavePrimaria, registro[i].byteOffset);
    fclose(arqIndicePrimario);
    return SUC_FUNCAO;
}

/* Atualiza um registro, bem como os índices primário e secundário */
int atualiza_registro(char *nomeLista, char *nomeLED, char *nomeIndicePrimario) {
    RegistroLIS linha;
    char chaveFormatada[TAM_CHAVEPRI], controle;
    preenche_registro(&linha, chaveFormatada, 1);
    controle = exclui_registro(nomeLista, nomeLED, nomeIndicePrimario, chaveFormatada, 1);
    if(controle == INX_REGISTRO)
        return controle;
    printf("Digite os novos dados: \n");
    preenche_registro(&linha, chaveFormatada, 0);
    controle = inclui_registro(nomeLista, nomeLED, nomeIndicePrimario, &linha, 1);
    return SUC_FUNCAO;
}

/* Intercala duas listas */
int intercala(char *nomeLista1, char *nomeLista2) {
    /* Declaração de Variáveis */
    FILE *arqLista1, *arqLista2, *arqLista12, *arqIndice1, *arqIndice2;
    char linhaArq1[TAM_REGLISTA], linhaArq2[TAM_REGLISTA];
    char linhaInd1[TAM_CHAVEPRI], linhaInd2[TAM_CHAVEPRI];
    int offset1, offset2, controle;
    /* Normalização dos índices primários */
    controle = indice_primario("lista1.txt", "indiceprimario1.ind");
    controle = indice_primario("lista2.txt", "indiceprimario2.ind");
    /* Abertura de arquivos */
    arqLista1 = fopen(nomeLista1, "r");
    arqLista2 = fopen(nomeLista2, "r");
    arqIndice1 = fopen("indiceprimario1.ind", "r");
    arqIndice2 = fopen("indiceprimario2.ind", "r");
    arqLista12 = fopen("lista12.txt", "w");
    /* Estabelecimento de condição inicial */
    fscanf(arqIndice1, "%s%d", linhaInd1, &offset1);
    fscanf(arqIndice2, "%s%d", linhaInd2, &offset2);
    while(!feof(arqIndice1) && !feof(arqIndice2)) {
            /* Registro da lista 1 é menor que registro da lista 2? */
            if(strcoll(linhaInd1, linhaInd2) < 0 && !feof(arqLista1)) {
                fseek(arqLista1, offset1, SEEK_SET);
                fgets(linhaArq1, TAM_REGLISTA, arqLista1);
                /* Insere o registro na lista final e caminha na lista 1 */
                fprintf(arqLista12, "%s", linhaArq1);
                fscanf(arqIndice1, "%s%d", linhaInd1, &offset1);
            }
            /* Registro da lista 1 é maior que registro da lista 2? */
            else if(strcoll(linhaInd1, linhaInd2) > 0 && !feof(arqLista2)) {
                fseek(arqLista2, offset2, SEEK_SET);
                fgets(linhaArq2, TAM_REGLISTA, arqLista2);
                /* Insere o registro na lista final e caminha na lista 2 */
                fprintf(arqLista12, "%s", linhaArq2);
                fscanf(arqIndice2, "%s%d", linhaInd2, &offset2);
            }
            /* Registro da lista 1 é igual ao registro da lista 2? */
            else if(!strcmp(linhaInd1, linhaInd2)) {
                fseek(arqLista1, offset1, SEEK_SET);
                fgets(linhaArq1, TAM_REGLISTA, arqLista1);
                /* Insere o registro na lista final e caminha nas duas listas */
                fprintf(arqLista12, "%s\n", linhaArq1);
                fscanf(arqIndice1, "%s%d", linhaInd1, &offset1);
                fscanf(arqIndice2, "%s%d", linhaInd2, &offset2);
            }
    }
    /* Fechamento dos arquivos */
    fclose(arqLista1);
    fclose(arqLista2);
    fclose(arqLista12);
    fclose(arqIndice1);
    fclose(arqIndice2);
    return SUC_FUNCAO;
}

/* Realiza uma busca binária */
int busca_binaria(RegistroGER* vetorInd, int tam, char* chave){
    int inicio = 0;
    int meio;
    char temp[TAM_CHAVEPRI];
    while(inicio <= tam) {
        meio = (int) (inicio + tam) / 2;
        strcpy(temp, vetorInd[meio].chavePrimaria);
        if(!strcmp(vetorInd[meio].chavePrimaria, chave))
            return meio;
        else if(strcoll(vetorInd[meio].chavePrimaria, chave) > 0)
            tam = meio - 1;
        else
            inicio = meio + 1;
    }
    return INX_REGISTRO;
}

/* Converte registros de um arquivo para um vetor */
RegistroGER* converte_arquivo(char *nomeArquivo, int *j) {
    FILE *arqIndice;
    int i = 1;
    char resto;
    RegistroGER *vetorInd = NULL;
    arqIndice = fopen(nomeArquivo, "r");
    do {
        fseek(arqIndice, -2, SEEK_CUR); /* Volta 2 bytes por ter que ler o final do arquivo com a resto */
        vetorInd = (RegistroGER *) realloc(vetorInd, i * sizeof(RegistroGER));
        fscanf(arqIndice, "%s", vetorInd[i-1].chavePrimaria);
        fscanf(arqIndice, "%d", &(vetorInd[i-1].byteOffset));
        i++;
        (*j)++;
        resto = fgetc(arqIndice);
        resto = fgetc(arqIndice);
    } while(resto != EOF);
    fclose(arqIndice);
    return vetorInd;
}

/* LISTAS */

/* Retorna uma lista vazia */
RegistroGER* inicializa_lista() {
    return NULL;
}

/*  Insere um elemento na lista */
RegistroGER* insere_lista(RegistroGER *registro, char *chaveSec, char *chavePrim, int byteOffset) {
    RegistroGER *novo = (RegistroGER *) malloc(sizeof(RegistroGER));
    strcpy(novo->chaveSecundaria, chaveSec);
    strcpy(novo->chavePrimaria, chavePrim);
    novo->byteOffset = byteOffset;
    novo->proximo = registro;
    return novo;
}

/* Atualiza um elemento da lista */
int atualiza_lista(RegistroGER *lista, char *chaveSecundaria, int novoOffset) {
    RegistroGER *registro = lista;
    while(strcmp(registro->chaveSecundaria,chaveSecundaria) && registro->proximo!=NULL)
        registro = registro->proximo;
    registro->byteOffset = novoOffset;
    return SUC_FUNCAO;
}

/* Busca um elemento na lista */
int busca_lista(RegistroGER *registro, char *chaveSec) {
    RegistroGER *p;
    for (p=registro; p!=NULL; p=p->proximo)
        if (!strcmp(p->chaveSecundaria,chaveSec))
            return p->byteOffset;
    return INX_REGISTRO;       /* n�o achou o elemento */
}

/* Libera a lista da memória */
int libera_lista(RegistroGER *registro) {
    RegistroGER *p = registro;
    while (p != NULL) {
        RegistroGER *t = p->proximo; /*  guarda refer�ncia  para o pr�ximo  elemento */
        free(p);            /* libera a mem�ria apontada por p */
        p = t;              /* faz p apontar para o pr�ximo */
    }
    return SUC_FUNCAO;
}

/* Inicializa a LED */
LED* inicializa_led() {
    return NULL;
}

/* Insere um elemento no início da LED */
LED* insere_led_inicio(LED *listaInvertida, int byteOffset) {
    LED *novo = (LED *) malloc(sizeof(LED));
    novo->byteOffset = byteOffset;
    novo->proximo = listaInvertida;
    return novo;
}

/* Insere um elemento no final da LED */
LED* insere_led_fim(LED *listaInvertida, int byteOffset) {
    LED *temp, *novo = (LED *) malloc(sizeof(LED));
    novo->byteOffset = byteOffset;
    novo->proximo = NULL;
    temp = listaInvertida;
    if (listaInvertida == NULL) {
        listaInvertida = insere_led_inicio(listaInvertida, novo->byteOffset);
        return listaInvertida;
    }
    while(temp->proximo != NULL)
        temp = temp->proximo;
    temp->proximo = novo;
    return listaInvertida;
}

/* Função auxiliar: retira do início da LED */
LED* pop_led(LED *listaInvertida, int *byteOffset) {
   LED *temp = listaInvertida->proximo;
   *byteOffset = listaInvertida->byteOffset;
   free(listaInvertida);
   return temp;
}

/* Preenche a LED com os dados do arquivo */
LED* preenche_led(LED *listaInvertida, char *nomeLED) {
    FILE *arqLED;
    int byteOffset;
    arqLED = fopen(nomeLED, "r");
    while(!feof(arqLED)) {
        fscanf(arqLED, "%d", &byteOffset);
        if(!feof(arqLED))
            listaInvertida = insere_led_fim(listaInvertida, byteOffset);
    }
    fclose(arqLED);
    return listaInvertida;
}

/* Retorna a LED para o arquivo e libera da memória */
int retorna_led(LED *listaInvertida, char *nomeLED) {
    FILE *arqLED;
    LED *temp;
    /* Abre o arquivo para a escrita, limpando-o do conteúdo atual */
    arqLED = fopen(nomeLED, "w");
    temp = listaInvertida;
    /* Escreve todos os nós da LED no arquivo */
    while(temp != NULL) {
        fprintf(arqLED, "%d\n", temp->byteOffset);
        temp = temp->proximo;
    }
    /* Libera a LED */
    fclose(arqLED);
    libera_led(listaInvertida);
    return SUC_FUNCAO;
}

/* Libera a LED da memória */
int libera_led(LED *listaInvertida) {
    LED *p = listaInvertida;
    while (p != NULL) {
        LED *t = p->proximo;
        free(p);
        p = t;
    }
    return SUC_FUNCAO;
}
