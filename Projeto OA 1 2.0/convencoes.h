/* Trava de inclus�es m�ltiplas */
#ifndef CONVENCOES
#define CONVENCOES

/* Constantes de tamanho */
#define TAM_CHAVEPRI 31 /* Tamanho de uma chave primaria */
#define TAM_CHAVESEC 8 /* Tamanho de uma chave secundaria */
#define TAM_INDSECUND 3 /* Tamanho de um registro de chave secundaria de tamanho fixo */
#define TAM_REGCHAVE 37 /* Tamanho de um registro de chave primaria de tamanho fixo */
#define TAM_REGLISTA 68 /* Tamanho de um registro de lista de tamanho fixo */

#define TAM_MATRICULA 7 /* Tamanho de um campo de matricula */
#define TAM_NOME 41 /* Tamanho de um campo de nome */
#define TAM_OP 3 /* Tamanho de um campo de op */
#define TAM_CURSO 2 /* Tamanho de um campo de curso */
#define TAM_TURMA 2 /* Tamanho de um campo de turma */

/* Constantes de padroniza��o */
#define CTE_OPPADRAO 127
#define CTE_FIMLISTA "-999" /* Para ocupar 4 bytes precisa ser uma string */
#define CTE_FIMLISTAI -999 /* defini��o inteira de fim de lista */
#define CTE_INATIVO "-001"

/* C�digos de sucesso */
#define SUC_FUNCAO 0 /* Final de funcao bem sucedido */
#define SUC_REGISTRO 1 /* Registro efetivado */

/* C�digos de inexist�ncia */
#define INX_ARQUIVO -1 /* Arquivos inexistentes */
#define INX_REGISTRO -2 /* Registros inexistentes */
#define JEX_REGISTRO -2 /* Registros j� existentes */

/* C�digos de erro */

#endif /* CONVENCOES */
