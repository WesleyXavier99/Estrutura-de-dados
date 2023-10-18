#include <stdio.h>
#include <stdlib.h>
#include "Conjunto.h"

int main(void) {
  Conjunto *c1,*c2,*c3,*intABC;
  int i;
  
  c1 = conj_Cria();
  c2 = conj_Cria(); 
  c3 = conj_Cria();

  for(i=2;i<=28;i++){
    conj_Insere(c1,i);
  }

  for(i=5;i<=30;i++){
    conj_Insere(c2,i);
  }

  for(i=1;i<=25;i++){
    conj_Insere(c3,i);
  }

  intABC = conj_Intersecao(conj_Intersecao(c1, c2), c3);

  conj_exibe(intABC);
  return 0;
}