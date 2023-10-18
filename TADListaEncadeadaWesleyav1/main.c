#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int main(){
  tLista* l = lista_cria(1,1);
  tLista* lnova;
  lista_exibe(l);

  lista_inclui(l,10);
  lista_inclui(l,20);
  lista_inclui(l,15);
  lista_inclui(l,35);
  lista_inclui(l,25);
  lista_exibe(l);
  lnova = copiaKNos(l,3);
  lista_exibe(lnova);

  return 0;

  com repetição e com classificação
    1 2 4 5 7   
}