#include <stdio.h>
#include "PONTO.h"
//APLICAÇÂO
/*
Criar três pontos e exibi-los

*/
int main(void) {
  Ponto *pt1,*pt2,*pt3;
  char *texto;

  // pto_getPonto
  pt1=pto_cria(2,2);
  pt2=pto_cria(6,9);
  pt3=pto_cria(1,12);
  printf("Meu ponto: %s", pto_getPonto(pt1));
  pto_exibe(pt2);
  pto_exibe(pt3);
  
  

  
  
  return 0;
}