/** 
  KARINA E WESLEY
**/

#include "PONTO.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/* TAD: Ponto (x,y) */
/* Tipo exportado */
struct ponto {
  float x, y;
};

/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto *pto_cria(float x, float y) {
  Ponto *p;
  p = (Ponto *)malloc(sizeof(Ponto));
  p->x = x;
  p->y = y;
  return p;
}

/* Função libera - Libera a memória de um ponto previamente criado */
void pto_libera(Ponto *p) { free(p); };

/* Função acessa - Retorna os valores das coordenadas de um ponto */
void pto_acessa(Ponto *p, float *x, float *y) {
  *x = p->x;
  *y = p->y;
};

/* Função atribui - Atribui novos valores às coordenadas de um ponto */
void pto_atribui(Ponto *p, float x, float y) {
  p->x = x;
  p->y = y;
};

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto *p1, Ponto *p2) {
  float resultado;
  float dx, dy;
  dx = ((p1->x) - (p2->x)) * ((p1->x) - (p2->x));
  dy = ((p1->x) - (p2->x)) * ((p1->x) - (p2->x));

  resultado = sqrt(dx + dy);
  return resultado;
};

/* Função compara - compara se dois pontos têm as mesmas coordenadas*/
int pto_compara(Ponto *p1, Ponto *p2) {
  return ((p1->x) == (p2->x) && (p1->y) == (p2->y));
}

/* Função copia -   cria um novo ponto com as coordenadas do ponto recebido */
Ponto *pto_copia(Ponto *p) {
  Ponto *novo = (Ponto *)malloc(sizeof(Ponto));

  novo->x = p->x;
  novo->y = p->y;

  return novo;
};

/* Função menorque - compara dois pontos e retorna 1, se o primeiro é mais
 * próximo da origem  ou 0  cc
 */
int pto_menorque(Ponto *p1, Ponto *p2) {
  Ponto *origem = (Ponto *)malloc(sizeof(Ponto));
  origem->x = 0;
  origem->y = 0;

  return (pto_distancia(origem, p1) < pto_distancia(origem, p2));
};

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char *pto_getPonto(Ponto *p) {

  char *pt;
  pt = (char *)malloc(sizeof(*p) + 8);
  sprintf(pt, "( %.2f , %.2f )", p->x, p->y);
  return pt;
}

/* Função exibe -Escreve na tela o ponto no formato  (xxx.xx,yyy.yy)*/
void pto_exibe(Ponto *p) { printf("\n(%.2f,%.2f)", p->x, p->y); }
