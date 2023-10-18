#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
  int info;
  tNo *suc;
};

struct lista {
  tNo *prim;
  int tam;
  int ehClassificada;
  int comRepeticao;
};

tNo *criaNo(int info) {
  tNo *novo = (tNo *)malloc(sizeof(tNo));
  novo->info = info;
  novo->suc = novo;
  return novo;
}

tLista *lista_cria(int classif, int ehRep) {
  tLista *l = (tLista *)malloc(sizeof(tLista));
  l->tam = 0;
  l->prim = NULL;
  l->ehClassificada = classif;
  l->comRepeticao = ehRep;
  return l;
}

int lista_classif(tLista *l) { return l->ehClassificada; }

int lista_comRep(tLista *l) { return l->comRepeticao; }

int busca(tLista *l, int chave, tNo **ant, tNo **atual) {
  int ehClassif, ehRep;

  (*atual) = l->prim;
  (*ant) = NULL;

  ehClassif = lista_classif(l);
  ehRep = lista_comRep(l);

  while ((*atual) != NULL) {
    if ((*atual)->info == chave) {
      return 1;
    } else if (ehClassif && (*atual)->info > chave) {
      return 0;
    } else {
      (*ant) = (*atual);
      (*atual) = (*atual)->suc;
    }
  }
  return 0;
}

int lista_inclui(tLista *l, int info) {
  tNo *novo, *ant, *suc;
  int ehClassif, comRep, sit;

  ehClassif = lista_classif(l);
  comRep = lista_comRep(l);

  if (!ehClassif) {
    if (!comRep && busca(l, info, &ant, &suc)) {
      // se não for classificada, sem repetição e achou o valor
      return 0;
    }
    // se não for classificada, com repetição ou não achou
    novo = criaNo(info);
    novo->suc = l->prim;
    l->prim = novo;
    (l->tam)++;
    return 1;
  } else {
    // com classificação
    sit = busca(l, info, &ant, &suc);
    if (sit && !comRep) {
      // com classificação, sem repetição e achou
      return 0;
    }
    // com classificação, com repetição ou não achou
    novo = criaNo(info);
    novo->suc = NULL;
    // novo->suc = suc;
    if (ant == NULL) {
      // caso seja o primeiro nó da lista
      l->prim = novo;
    } else {
      // caso esteja no meio ou no fim da lista
      ant->suc = novo;
    }
    novo->suc = suc;
    (l->tam)++;
    return 1;
  }
}

int lista_vazia(tLista *l) { return l->tam == 0; }

int lista_exclui(tLista *l, int chave) {
  tNo *ant, *atual;
  if (lista_vazia(l)) {
    return 0;
  }

  if (!lista_comRep(l)) {
    if (!busca(l, chave, &ant, &atual)) {
      // sem repetição e não encontrou
      return 0;
    }
    if (ant == NULL) {
      // sem repetição e é o primeiro nó
      l->prim = atual->suc;
    }
    // sem repetição e tá no meio da lista
    ant->suc = atual->suc;
    free(atual);
    (l->tam)--;
    return 1;
  }

  // com repetição
  if (lista_classif(l)) {
    // com repetição e classificada

    // acha a posição do primeiro valor
    busca(l, chave, &ant, &atual);

    // enquanto o atual for igual a chave, permanece excluindo
    while (atual->info == chave) {
      // caso esteja na primeira posição
      if (l->prim == atual) {
        l->prim = atual->suc;
        ant->suc = NULL;
        free(atual);
        atual = l->prim;
      } else {
        ant->suc = atual->suc;
        free(atual);
        atual = ant->suc;
      }
    }
    (l->tam)--;
    return 1;
  } else {
    // com repetição e sem classificação
    while (busca(l, chave, &ant, &atual)) {
      // caso esteja na primeira posição
      if (atual == l->prim) {
        l->prim = atual->suc;
        free(atual);
      } else {
        ant->suc = atual->suc;
        free(atual);
      }
    }
    (l->tam)--;
    return 1;
  }
}

void lista_exibe(tLista *l) {
  tNo *aux = l->prim;
  int cont = 1;
  printf("\nINICIO\n");
  while (aux) {
    printf("tam = %d\n", l->tam);
    printf("no: %d\ninfo: %d\n\n", cont, aux->info);
    aux = aux->suc;
    cont++;
  }
  printf("FIM\n\n");
}

tLista *copiaKNos(tLista *l, int k) {
  if (lista_vazia(l)) {
    return l;
  }

  if ((((l->tam) - k) <= 0)) {
    tLista *lcopia = lista_cria(l->ehClassificada, l->comRepeticao);
    int i;
    tNo *aux = l->prim;
    while (aux != NULL) {
      lista_inclui(lcopia, aux->info);
      aux = aux->suc;
    }
    return l;
  }
  tLista *lnova = lista_cria(l->ehClassificada, l->comRepeticao);
  tNo *aux = l->prim;
  int i;
  for (i = 1; i <= l->tam; i++) {
    if (i >= k) {
      lista_inclui(lnova, aux->info);
    }
    aux = aux->suc;
  }
  return lnova;
}