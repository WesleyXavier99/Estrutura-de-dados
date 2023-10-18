#include "CIRCULO.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ponto {
  float x, y;
};

struct circulo {
  Ponto *p;
  float raio;
};

/* Funções exportadas */
/* Função cria - Aloca e retorna um circulo com coordenadas e um raio (x,y,r) */
Circulo *circ_cria(float x, float y, float r) {
  Ponto *p;
  Circulo *c;
  p = (Ponto *)malloc(sizeof(Ponto));
  p->x = x;
  p->y = y;

  c = (Circulo *)malloc(sizeof(Circulo));
  c->raio = r;
  c->p = p;

  return c;
};

/* Função libera - Libera a memória de um circulo previamente criado */
void circ_destroi(Circulo *c) { free(c); };

/* Função acessa - Retorna os valores das coordenadas e do raio */
void circ_acessa(Circulo *c, float *x, float *y, float *r) {
  *y = c->p->y;
  *x = c->p->x;
  *r = c->raio;
};

/* Função compara - compara se dois circulos têm a mesma circunferência*/
int circ_compara(Circulo *c1, Circulo *c2){
  
};

/* Função clona - clona um circulo*/
Circulo *circ_clona(Circulo *c) {
  Circulo *cc;
  Ponto *pp;

  cc = (Circulo *)malloc(sizeof(Circulo));
  pp = (Ponto *)malloc(sizeof(Ponto));

  pp->x = c->p->x;
  pp->y = c->p->y;

  cc->raio = c->raio;
  cc->p = pp;

  return cc;
};

/* Função imprime - imprime um circulo na tela*/
void circ_imprime(Circulo *c) {
  printf("Circulo: (%.2f, %.2f), %f\n\n", c->p->x, c->p->y, c->raio);
};

/* Função area - calcula a area de um circulo*/
float circ_area(Circulo *c) { return 3.141 * (c->raio * c->raio); };

/* Função interior - */
float circ_interior(Circulo *c, Ponto *p){
  
};

/* Função distancia X - */
float circ_distanciaX(Circulo *c) {
  if (c->p->y < 0) {
    return -(c->p->y);
  } else {
    return c->p->y;
  }
};

/* Função distancia Y - */
float circ_distanciaY(Circulo *c) {
  if (c->p->x < 0) {
    return -(c->p->x);
  } else {
    return c->p->x;
  }
};

/* Função atribui - Atribui novos valores à coordenada x de um ponto do circulo
 */
void circ_atribuiX(Circulo *c, float x) { c->p->x = x; };

/* Função atribui - Atribui novo valor à coordenada y de um ponto do circulo*/
void circ_atribuiY(Circulo *c, float y) { c->p->y = y; };

/* Função atribui - Atribui novo valor ao raio de um circulo */
void circ_atribuiR(Circulo *c, float r) { c->raio = r; };

/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto *p1, Ponto *p2) {
  float resultado;
  float dx, dy;
  dx = ((p1->x) - (p2->x)) * ((p1->x) - (p2->x));
  dy = ((p1->x) - (p2->x)) * ((p1->x) - (p2->x));

  resultado = sqrt(dx + dy);
  return resultado;
};

/* Função distancia - Retorna a distância entre dois circulos */
float circ_distancia(Circulo *c1, Circulo *c2){
  return pto_distacia(c1->p, c2->p);
};

/* Função obtem - */
float *circ_obtemX(Circulo *c) {
  float *x;

  *x = c->p->x;

  return x;
};
