/* TAD:Retangulo */
/* Dependência de módulos */
#include "ponto.h"

/* Tipo exportado */
typedef struct retangulo Retangulo;
/* Funções exportadas */
/* cria - Aloca e retorna um círculo com centro(x,y) e raio r */
Retangulo *ret_cria(float x, float y, float altura, float base);
/* libera - Libera a memória de um círculo previamente criado */
void ret_libera(Retangulo *c);
/* area - Retorna o valor da área do círculo */
float ret_area(Retangulo *c);
/* interior - Verifica se um ponto p está dentro do círculo */
int ret_interior(Retangulo *c, Ponto *p);
/* mostra os valores de um circulo */
void ret_exibe(Retangulo *c);
/* copia - Aloca e retorna um círculo com dados iguais a outro retangulo */
Retangulo *ret_copia(Retangulo *r);
/* Troca conteudo de ponteiros para Retangulos */
void ret_troca(Retangulo **r1, Retangulo **r2);
/* Acessa elementos do retangulo */
float ret_base(Retangulo *c);
float ret_altura(Retangulo *c);
Ponto *ret_vertice(Retangulo *c);

int ret_compara(Retangulo *r1, Retangulo *r2);
void ret_ordena(Retangulo **ret, int tam);