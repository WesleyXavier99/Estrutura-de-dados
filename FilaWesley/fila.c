#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "fila.h"

struct fila{
  tNo *prim;
  tNo *ult;
};

struct no{
  int chave;
  struct no *prox;
};

tNo* cria_No(){
  tNo* novo =(tNo*) malloc(sizeof(tNo));
  
  return novo;
}

void fila_Cria(tFila *fila){
  fila = (tFila*)malloc(sizeof(tFila));
  fila->prim = NULL;
  fila->ult = NULL;
}

int fila_Vazia(tFila *fila){
  return (fila->prim == NULL);
}

int fila_Esvazia(tFila *fila){
  tNo* aux = fila->prim , *aux2;
  
  if(fila_Vazia(fila)){
    return 0;
  }
  while(aux){
      aux2 = aux;
      aux = aux2->prox;
      free(aux2);
  }
  fila_Cria(fila);
  return 1;
}

void fila_Insere(tFila *fila, int chave){ 
  tNo* novo = cria_No();
  
  novo->chave;
  novo->prox = NULL;
  if(fila_Vazia(fila)){
    fila->prim = novo;
    fila->ult = novo;
  }else{
    fila->ult->prox = novo;
    fila->ult = novo;
  }
}

int fila_Remove(tFila *fila){
  tNo* removido = fila->prim;
  
  if(fila_Vazia(fila)){
    return 0;
  }
  fila->prim = fila->prim->prox;
  if(fila->prim==NULL){
    fila->ult = NULL;
  }
  free(removido);
  return 1;
}

int fila_Tamanho(tFila *fila){
  tNo* aux = fila->prim;
  
  int cont=0;
  if(fila_Vazia(fila)){
    return 0;
  }
  while(aux){
    cont++;
    aux = aux->prox;
  }
  return cont;
}

tNo* fila_Primeiro(tFila *fila){
  if(fila_Vazia(fila)){
    return NULL;
  }
  return fila->prim;
}