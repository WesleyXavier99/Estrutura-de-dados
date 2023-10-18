#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

int main(void) {
  tPilha *p = pilha_Cria(p);
  tNo* aux;
  pilha_Empilha(p,10);
  printf("tamanho:%d\ntopo:%d\n",pilha_Tamanho(p),pilha_Topo(p,aux));
  pilha_Empilha(p,12);
  pilha_Empilha(p,15);
  printf("tamanho:%d\ntopo:%d\n",pilha_Tamanho(p),pilha_Topo(p,aux));
  pilha_Empilha(p,50);
  pilha_Desempilha(p);
  pilha_Esvazia(p);
  printf("tamanho:%d\ntopo:%d\n",pilha_Tamanho(p),pilha_Topo(p,aux));
  return 0;
}