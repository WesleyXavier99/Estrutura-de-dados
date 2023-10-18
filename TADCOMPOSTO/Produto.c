#pragma once
#include "Produto.h"
#include "Unidade.h"

//--------------
// Implementaï¿½o
//--------------

struct produto {
  char *id;
  char *codBarras;
  float preco;
  int qtdUnds;
  tUnidade **unds;
};

tProduto *pdt_cria(char *id, char *cod, float preco, int qtd, tUnidade **unds) {
  tProduto *pdt = (tProduto *)malloc(sizeof(tProduto));
  pdt->id = id;
  pdt->codBarras = cod;
  pdt->preco = preco;
  pdt->qtdUnds = qtd;
  pdt->unds = unds;
}
void pdt_libera(tProduto *pdt) {
  int i;
  for (i = 0; i < pdt->qtdUnds; i++) {
    free(pdt->unds[i]->dt_fabricacao);
    free(pdt->unds[i]);
  }

  free(pdt);
}
void pdt_exibeProduto(tProduto *pdt) {
  int i;
  puts(pdt->id);
  puts(pdt->codBarras);
  printf("preco:%f\n", pdt->preco);
  printf("qtd:%d\n", pdt->qtdUnds);
  for (i = 0; i < pdt->qtdUnds; i++) {
    printf("data: %d/", pdt->unds[i]->dt_fabricacao->dia);
    printf("%d/", pdt->unds[i]->dt_fabricacao->mes);
    printf("%d\n", pdt->unds[i]->dt_fabricacao->ano);
    printf("Lote: %d\n", pdt->unds[i]->lote);
  }
}
int pdt_idSemelhante(tProduto *pdt, tProduto *pdt2) {
  if (strcmp(pdt->id, pdt2->id) == 0) {
    return 1;
  }
  return 0;
}
void pdt_reajuste(tProduto *pdt, int perc) {
  pdt->preco = pdt->preco + ((pdt->preco * (perc)) / 100);
}

int pdt_iguais(tProduto *pdt, tProduto *pdt2) {

  if (strcmp(pdt->id, pdt2->id) == 0 &&
      strcmp(pdt->codBarras, pdt2->codBarras) == 0 &&
      pdt->preco == pdt2->preco && pdt->qtdUnds == pdt2->qtdUnds) {
    return 1;
  } else {
    return 0;
  }
}

char *pdt_getId(tProduto *pdt) { return pdt->id; }

char *pdt_getCodBarras(tProduto *pdt) { return pdt->codBarras; }

float pdt_getPreco(tProduto *pdt) { return pdt->preco; }

int pdt_getQtdUnds(tProduto *pdt) { return pdt->qtdUnds; }

void pdt_setId(tProduto *pdt, char *novoId) {
  free(pdt->id);
  pdt->id = novoId;
}

void pdt_setCodBarras(tProduto *pdt, char *novoCod) {
  free(pdt->codBarras);
  pdt->codBarras = novoCod;
}

void pdt_setPreco(tProduto *pdt, float novoPreco) { pdt->preco = novoPreco; }

void pdt_setQtdUnidades(tProduto *pdt, int novoQtd) { pdt->qtdUnds = novoQtd; }
