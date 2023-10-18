#include "Data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Representa�o do TAD: TData
//-----------
// Interface
//-----------

typedef struct unidade tUnidade;

void und_setData(tUnidade *und, tData *dt);

void und_setLote(tUnidade *und, int lote);

tData *und_getData(tUnidade *und);

int und_getLote(tUnidade *und);

void und_exibe(tUnidade *und);

tUnidade *und_cria(tData *dt, int lote);

void und_libera(tUnidade *u);