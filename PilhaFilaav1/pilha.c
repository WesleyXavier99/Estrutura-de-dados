#include "pilha.h"
#include<stdio.h>
#include<stdlib.h>

struct no {
    int chave;
    struct no *prox;
};

struct pilha {
    struct no* topo;
    int tam;
};

tPilha* pilha_Cria(tPilha* pilha){
  pilha = (tPilha*)malloc(sizeof(tPilha));
  pilha->topo = NULL;
  pilha->tam = 0;
  return pilha;
}

tNo* no_Cria(){
  tNo* novo = (tNo*)malloc(sizeof(tNo));
  return novo;
}

int pilha_Vazia(tPilha* pilha){
  return (pilha->topo==NULL);
}

int pilha_Tamanho(tPilha* pilha){
  return pilha->tam;
}

int pilha_Topo(tPilha* pilha, tNo*topo){
  if(pilha->topo==NULL){
    return 0;
  }
  topo =  pilha->topo;
  return topo->chave;
}

void pilha_Empilha(tPilha* pilha, int valor){
  tNo* novo = no_Cria();
  novo->chave = valor;
  
  if(pilha_Vazia(pilha)){
    pilha->topo = novo;
    (pilha->tam)++;
  }else{
    novo->prox = pilha->topo;
    pilha->topo = novo;
    (pilha->tam)++;
  }
}

int pilha_Desempilha(tPilha* pilha){
  if(pilha_Vazia(pilha)){
    return 0;
  }
  int ret=-1;
  
  tNo* aux = pilha->topo;
  if(pilha->tam==1){
    pilha->topo = pilha->topo->prox;
    (pilha->tam)--;
    ret = aux->chave;
    free(aux);
    pilha->topo = NULL;
  }else{
    pilha->topo = pilha->topo->prox;
    (pilha->tam)--;
    ret = aux->chave;
    free(aux);
  }
  if(pilha_Vazia(pilha)){
    pilha = pilha_Cria(pilha);
  }
  return ret;
}

int pilha_Esvazia(tPilha* pilha){
  if(pilha_Vazia(pilha)){
    return 0;
  }
  tNo* aux = no_Cria();
  aux = pilha->topo;
  while(aux!=NULL){
    pilha->topo = pilha->topo->prox;
    free(aux);
    (pilha->tam)--;
    if(pilha->tam==0){
      aux = NULL;
      pilha->topo = NULL;
    }else{
      aux =pilha->topo;
    }
  }
  
  return 1;
}