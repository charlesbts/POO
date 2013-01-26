/* Trava de inclusões múltiplas */
#ifndef FUN_DEF
#define FUN_DEF

/* Definição de módulo-servidor */
#ifdef FUN_IMPL
#define FUN_EXT
#else
#define FUN_EXT extern
#endif

/* Includes */
#include <stdio.h>
#include "convencoes.h"

/* Estruturas */

typedef struct registrosec {
    char chavePrimaria[TAM_CHAVEPRI], chaveSecundaria[3];
    int byteOffset;
    struct registrosec *proximo;
} RegistroGER;

typedef struct registrolis {
    char matricula[TAM_MATRICULA], nome[TAM_NOME];
    char op[3], curso[3], turma[3];
} RegistroLIS;

typedef struct led {
    int byteOffset;
    struct led *proximo;
} LED;

/* Protótipos (EA) */
FUN_EXT int inicializa_programa(int);
FUN_EXT int indice_primario(char *, char *);
FUN_EXT int indice_secundario(char *, char *, char *, char *, int);
FUN_EXT int cria_chave_primaria(char *, char *);
FUN_EXT int combina_string(char *, char *, char *);
FUN_EXT int heap_sort(RegistroGER *, int, int);
FUN_EXT int build_heap(RegistroGER *, int, int);
FUN_EXT int max_heap(RegistroGER *, int, int, int);
FUN_EXT int visualiza_indice(char *, int);
FUN_EXT int visualiza_registros(char *);
FUN_EXT int preenche_registro(RegistroLIS *, char *, int);
FUN_EXT int inclui_registro(char *, char *, char *, RegistroLIS *, int);
FUN_EXT int exclui_registro(char *, char *, char *, char *, int);
FUN_EXT int reconstroi_indice(char *, char *, char *, char *);
FUN_EXT int ordena_indice_primario(char *);
FUN_EXT int atualiza_registro(char *, char *, char *);
FUN_EXT int intercala(char *, char *);
FUN_EXT int busca_binaria(RegistroGER*, int, char *);
FUN_EXT RegistroGER* converte_arquivo(char *, int *);

/* Protótipos (LISTAS) */
FUN_EXT RegistroGER* inicializa_lista();
FUN_EXT RegistroGER* insere_lista(RegistroGER *, char *, char *, int);
FUN_EXT int atualiza_lista(RegistroGER *, char *, int);
FUN_EXT int busca_lista(RegistroGER *, char *);
FUN_EXT int libera_lista(RegistroGER *);
FUN_EXT LED* inicializa_led();
FUN_EXT LED* insere_led_inicio(LED *, int);
FUN_EXT LED* insere_led_fim(LED *, int);
FUN_EXT LED* pop_led(LED *, int *);
FUN_EXT LED* preenche_led(LED *, char *);
FUN_EXT int retorna_led(LED *, char *);
FUN_EXT int libera_led(LED *);
#endif /* FUNCOES_H */
