#include <stdio.h>
#include<stdlib.h>
#include "ListaEncadeada.h"

int main(void){
  tLista *lst = lst_cria(1,0);
  lst_insere(lst,10);
  lst_insere(lst,20);
  lst_insere(lst,10);
  lst_insere(lst,5);
  lst_imprime(lst);
  return 0;
}