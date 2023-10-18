#include <stdlib.h>
#include <stdio.h>
#include "Matriz.h"
struct matriz {
   int lin;
   int col;
   float* v;
};
Matriz* mat_cria (int m, int n) {
  Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
  if (mat == NULL) {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  mat->lin = m;
  mat->col = n;
  mat->v = (float*) malloc(m*n*sizeof(float));
  return mat;
}
  
void mat_libera (Matriz* mat){
  free(mat->v);
  free(mat);
}

float mat_acessa (Matriz* mat, int i, int j) {
  int k; /* índice do elemento no vetor – armazenamento por linha*/
  if (i<1 || i>mat->lin || j<1 || j>mat->col) {
    printf("Acesso inválido!\n");
    exit(1);
  }
  k = (i-1)*mat->col + j - 1;
  return mat->v[k];
}


void mat_atribui (Matriz* mat, int i, int j, float v) {
  int k; /* índice do elemento no vetor */
  if (i<1 || i>mat->lin || j<1 || j>mat->col) {
    printf("Atribuição inválida!\n");
    exit(1);
  }
  k = (i-1)*mat->col + j -1;
  mat->v[k] = v;
}
int mat_linhas (Matriz* mat) {
  return mat->lin;
}
int mat_colunas (Matriz* mat) {
  return mat->col;
}
void mat_exibe(Matriz* mat){
  int i,j;
  float el;
  printf("\n---------------------------- \n");
  for(i = 1; i <= mat->lin; i++) {        
		for(j = 1; j <= mat->col; j++) {
      printf("\t%5.1f", el=mat_acessa(mat,i,j));
		}
		printf("\n");
	}
  printf("---------------------------- \n");
}

Matriz* mat_multiplica (Matriz* mA, Matriz* mB) {
  Matriz*mC;
  int i,j,x;
  float aux;
  if (mA->col != mB->lin) {
    printf("Multiplicação inválida!\n");
    exit(1);
  }
  mC=mat_cria(mA->lin,mB->col);
  for(i = 1; i <=mA->lin; i++) {
		for(j = 1; j <= mB->col; j++) {
			
			aux = 0;
			for(x = 1; x <= mB->lin; x++) 
				aux +=  mat_acessa(mA,i,x) *mat_acessa(mB,x,j);
			mat_atribui(mC,i,j, aux);
			
		}
	}
  return mC;
}
Matriz* mat_soma (Matriz* mA, Matriz* mB) {
  Matriz*mC;
  int i,j,x;
  float aux;
  if (mA->lin != mB->lin || mA->col != mB->col) {
    printf("Soma inválida!\n");
    exit(1);
  }
  mC=mat_cria(mA->lin,mA->col);
  for(i = 1; i <=mA->lin; i++) {
		for(j = 1; j <= mA->col; j++) {
			aux = mat_acessa(mA,i,j) +mat_acessa(mB,i,j);
			mat_atribui(mC,i,j, aux);
			
		}
	}
  return mC;
}
Matriz* mat_subtrai (Matriz* mA, Matriz* mB) {
  Matriz*mC;
  int i,j,x;
  float aux;
  if (mA->lin != mB->lin || mA->col != mB->col){
    printf("Subtração inválida!\n");
    exit(1);
  }
  mC=mat_cria(mA->lin,mA->col);
  for(i = 1; i <=mA->lin; i++) {
		for(j = 1; j <= mA->col; j++) {
			aux = mat_acessa(mA,i,j) - mat_acessa(mB,i,j);
			mat_atribui(mC,i,j, aux);
			
		}
	}
  return mC;
}

float mat_somaLin (Matriz* mat, int l){
  int i,j,x;
  float aux=0;
    
	for(j = 1; j <= mat->col; j++) {
			aux +=  mat_acessa(mat,l,j) ;
	}
	return aux;
}
/* Função mat_somaCol - Retorna a soma dos elementos da coluna recebida */
float mat_somaCol (Matriz* mat, int c){
  int i,j,x;
  float aux=0;
    
	for(i = 1; i <= mat->lin; i++) {
			aux +=  mat_acessa(mat,i,c) ;
	}
	return aux;
}
