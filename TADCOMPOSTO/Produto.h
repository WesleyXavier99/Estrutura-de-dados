#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include "Unidade.h"

// Representa�o do TAD: TData
//-----------
// Interface
//-----------

typedef struct produto tProduto;

tProduto *pdt_cria(char *id, char *cod, float preco, int qtd, tUnidade **unds);

void pdt_libera(tProduto *pdt);

void pdt_exibeProduto(tProduto *pdt);

int pdt_idSemelhante(tProduto *pdt, tProduto *pdt2);

void pdt_reajuste(tProduto *pdt, int perc);

int pdt_iguais(tProduto *pdt, tProduto *pdt2);

char *pdt_getId(tProduto *pdt);

char *pdt_getCodBarras(tProduto *pdt);

float pdt_getPreco(tProduto *pdt);

int pdt_getQtdUnds(tProduto *pdt);

void pdt_setId(tProduto *pdt, char *novoId);

void pdt_setCodBarras(tProduto *pdt, char *novoCod);

void pdt_setPreco(tProduto *pdt, float novoPreco);

void pdt_setQtdUnidades(tProduto *pdt, int novoQtd);