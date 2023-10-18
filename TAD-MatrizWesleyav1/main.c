#include <stdio.h>
#include"Matriz.h"

void preencheMatA(Matriz* matA);
void preencheMatB(Matriz* matB);
Matriz* matCompara(Matriz* matA,Matriz* matB);

int main(void) {
  Matriz* matA = mat_cria(3,5);
  Matriz* matB = mat_cria(3,5);

  preencheMatA(matA);

  mat_exibe(matA);
  preencheMatB(matB);
  mat_exibe(matB);
  mat_exibe(mat_subtrai(matA,matB));
}



void preencheMatA(Matriz* matA){
  int i,j;
  float l1[5] = {0,2,3,1,5};
  float l2[5] = {0,1,2,5,3};
  
  for(i=1;i<mat_linhas(matA);i++){
    for(j=1;j<mat_colunas(matA);j++){
      if(i==1){
        mat_atribui(matA, i, j, l1[j]);
      }else{
        if(i==2){
          mat_atribui(matA, i, j, l2[j]);
        }
      }
    }
  }
}

void preencheMatB(Matriz* matB){
  int i,j;
  float l1[5] = {0,3,0,2,3};
  float l2[5] = {0,4,2,4,5};
  
  for(i=1;i<mat_linhas(matB);i++){
    for(j=1;j<mat_colunas(matB);j++){
      if(i==1){
        mat_atribui(matB, i, j, l1[j]);
      }else{
        if(i==2){
          mat_atribui(matB, i, j, l2[j]);
        }
      }
    }
  }
}
