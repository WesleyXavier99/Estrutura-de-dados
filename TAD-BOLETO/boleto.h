#pragma once
#include "Data.h"
/* TAD: Folha Boleto (n�, valor, data de Vencimento) */
/* Tipo exportado */
typedef struct boleto tBoleto;

/* Fun��es exportadas */
/* Fun��o cria - Aloca e retorna um boleto*/
tBoleto* bol_cria(int n, float valor, tData* dtVenc);

/* Fun��o libera � Libera  mem�ria de um Boleto criado */
void bol_libera(tBoleto* p);

/* Fun��o acessa - Retorna os valores de um Boleto */
void bol_acessa(tBoleto* p, int* n, float* val, tData* dtVenc);

/* Fun��o atribui - Atribui novos valores ao Boleto */
void bol_atribui(tBoleto* p, int n, float val, tData* dtVenc);

/* Fun��o Exibe � Mostra os dados do Boleto na tela */
void bol_exibe(tBoleto* p1);

/* Fun��o getBoleto - Retorna uma string com os valores do boleto */
char* bol_getBoleto(tBoleto* p);
