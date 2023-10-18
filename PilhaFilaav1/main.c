#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilha.h"
#include "fila.h"
#define TAM 10

int gerNumAleat(int limInf, int limSup);
void exibeV(int v[TAM]);
void preencheV(int v[TAM]);
void Insercao(int vetor[TAM], int num);
void bubble_sort (int vetor[TAM], int n);
void enche_Pilha(tPilha* p,int v[TAM]);
void retiraK(tPilha* p,tFila* f, int k);

int main(void){
  //declaração de variáveis
  int v[TAM];
  int valor;
  tPilha* p;
  tFila* f;
  pilha_Cria(p);
  fila_Cria(f);

  //preenche um vetor com valores aleatórios
  preencheV(v);
  exibeV(v);
  //ordena o vetor
  bubble_sort(v,TAM);
  exibeV(v);
  //enche a pilha com os valores do vetor auxiliar
  enche_Pilha(p,v);

  //pede o k ao usuario
  printf("\ndigite um valor:",valor);
  scanf("%d",&valor);

  //passa para a fila os valores da pilha e assim ficando na ordem inversa
  retiraK(p,f,valor);

  //exibe a fila
  fila_Exibe(f);
  
}

int gerNumAleat(int limInf, int limSup){
   int dif=(limSup-limInf)+1;
   return rand()%dif + limInf;
}

void preencheV(int v[TAM]){
  int i;
  for(i = 0;i<TAM;i++){
    v[i]=gerNumAleat(0,20);
  }
}

void exibeV(int v[TAM]){
  int i;
  for(i = 0;i<TAM;i++){
    printf("v[%d] = %d\n",i,v[i]);
  }
}

void bubble_sort (int vetor[TAM], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {

        for (j = 0; j < n - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void enche_Pilha(tPilha* p,int v[TAM]){
  int i;
  for(i=0;i<TAM;i++){
    pilha_Empilha(p,v[i]);
  }
}


void retiraK(tPilha* p,tFila* f, int k){
  int i;
  printf("\n%d",k);
  for(i=0;i<k;i++){
    fila_Insere(f,pilha_Desempilha(p));
  }
}