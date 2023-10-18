//--------------
// Implementa�o
//--------------
#pragma once
#include "Unidade.h"
#include "Data.h"

struct unidade {
  tData *dt_fabricacao;
  int lote;
};

void und_setData(tUnidade *und, tData *dt) {
  dta_libera(und->dt_fabricacao);
  und->dt_fabricacao = dt;
}

void und_setLote(tUnidade *und, int lote) { und->lote = lote; }

tData *und_getData(tUnidade *und) { return und->dt_fabricacao; }

int und_getLote(tUnidade *und) { return und->lote; }

void und_exibe(tUnidade *und) {
  dta_exibe(und->dt_fabricacao);
  printf("\nlote:%d \n", und->lote);
}

tUnidade *und_cria(tData *dt, int lote) {
  tUnidade *und = (tUnidade *)malloc(sizeof(struct unidade));

  und->lote = lote;
  und->dt_fabricacao = dt;
  return und;
}

void und_libera(tUnidade *u) { free(u); }