#include "retangulo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct retangulo {
  Ponto *vie;
  float altura, base;
} Retangulo;

Retangulo *ret_cria(float x, float y, float altura, float base) {
  Retangulo *c = (Retangulo *)malloc(sizeof(Retangulo));
  c->vie = pto_cria(x, y);
  c->altura = altura;
  c->base = base;

  return c;
}

void ret_libera(Retangulo *c) {
  pto_libera(c->vie);
  free(c);
}

float ret_area(Retangulo *c) { return c->altura * c->base; }

int ret_interior(Retangulo *c, Ponto *p) {
  float d = pto_distancia(c->vie, p);
  return (d < c->base);
}

void ret_exibe(Retangulo *c) {
  float x, y;
  pto_acessa(c->vie, &x, &y);
  printf("\n Base: % f  Altura: % f Vértice: (% f, % f)", c->base, c->altura, x,
         y);
  return;
}

float ret_base(Retangulo *c) { return c->base; }

float ret_altura(Retangulo *c) { return c->altura; }

Ponto *ret_vertice(Retangulo *c) { return c->vie; }

Retangulo *ret_copia(Retangulo *r) {
  float x, y;
  pto_acessa(r->vie, &x, &y);
  Retangulo *c = (Retangulo *)malloc(sizeof(Retangulo));
  c->vie = pto_cria(x, y);
  c->altura = r->altura;
  c->base = r->base;
  return c;
}

void ret_troca(Retangulo **r1, Retangulo **r2) {
  Retangulo *aux;
  Ponto *p;
  aux = *r1;
  printf("\naux");
  ret_exibe(aux);
  *r1 = *r2;
  (*r2) = aux;
  return;
}

int ret_compara(Retangulo *r1, Retangulo *r2) {
  float areaR1 = ret_area(r1);
  float areaR2 = ret_area(r2);
  float x1, x2, y1, y2;

  pto_acessa(r1->vie, &x1, &y1);
  pto_acessa(r2->vie, &x2, &y2);

  if (areaR1 == areaR2) {
    if (y1 > y2) {
      return 0;
    }
    return 1;
  }

  return areaR1 > areaR2;
}

void ret_ordena(Retangulo **ret, int tam) {
  int i;
  Retangulo *aux = (Retangulo *)malloc(sizeof(Retangulo));

  for (i = 0; i < tam; i++) {
    if (ret_compara(ret[i], ret[i + 1])) {
      aux = ret[i];
      ret[i] = ret[i + 1];
      ret[i + 1] = aux;
      i--;
    }
  }
}

