#include "Data.h"
#include "Produto.h"
#include "Unidade.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void und_venc(tProduto *pdt, tData *dt);
void aplicaDesconto(tProduto **pdts, int tam, tData *dt);
int main() {
  tProduto **pdts = (tProduto **)malloc(sizeof(tProduto **) * 2);
  tData *dt = (tData *)malloc(sizeof(tData *));
  int dia, mes, ano;

  tProduto *pdt;
  tData *dt1;
  tData *dt2;
  tUnidade *und;
  tUnidade *und2;
  tUnidade **unds = (tUnidade **)malloc(sizeof(tUnidade **));
  char *id = (char *)malloc(sizeof(char) * 10);
  char *cod = (char *)malloc(sizeof(char) * 10);
  ;
  float preco = 16.30;
  int qtd = 2;

  tProduto *pdt2;
  tData *dt3;
  tData *dt4;
  tUnidade *und3;
  tUnidade *und4;
  tUnidade **unds2 = (tUnidade **)malloc(sizeof(tUnidade **));
  char *id2 = (char *)malloc(sizeof(char) * 10);
  char *cod2 = (char *)malloc(sizeof(char) * 10);
  ;
  float preco2 = 10.0;
  int qtd2 = 2;
  int tam = 2;

  // pdt1
  strcpy(id, "12345");
  strcpy(cod, "7777777");
  dt1 = dta_cria(10, 10, 2010);
  und = und_cria(dt1, 123456);
  dt2 = dta_cria(11, 11, 2011);
  und2 = und_cria(dt2, 246810);
  unds[0] = und;
  unds[1] = und2;
  pdt = pdt_cria(id, cod, preco, qtd, unds);

  // pdt2
  strcpy(id2, "12345");
  strcpy(cod2, "888888");
  dt3 = dta_cria(01, 01, 1001);
  und3 = und_cria(dt, 11111);
  dt4 = dta_cria(22, 02, 2222);
  und4 = und_cria(dt2, 22222);
  unds2[0] = und3;
  unds2[1] = und4;
  pdt2 = pdt_cria(id2, cod2, preco2, qtd2, unds2);

  pdts[0] = pdt;
  pdts[1] = pdt2;

  printf("Digite uma data:\ndia:");
  scanf("%d", &dia);
  printf("mes:");
  scanf("%d", &mes);
  printf("ano:");
  scanf("%d", &ano);

  dt = dta_cria(dia, mes, ano);

  und_venc(pdt[0], tam, dt);

  aplicaDesconto(pdts, tam, dt);
}
void und_venc(tProduto *pdt, tData *dt) {
  int i;
  for (i = 0; i < pdt_getQtdUnds(pdt[i]); i++) {
    if (pdt->unds[i]->dt_fabricacao->dia == dt->dia &&
        pdt->unds[i]->dt_fabricacao->mes == dt->mes &&
        pdt->unds[i]->dt_fabricacao->ano == dt->ano) {
      und_exibe(pdt->unds[i]);
    }
  }

  void aplicaDesconto(tProduto * *pdts, int tam, tData *dt) {
    int i, j;
    for (i = 0; i < tam; i++) {
      if (pdts[i]->QtdUnds > 0) {
        for (j = 0; j < pdts[i]->QtdUnds; j++) {
          if ()
          // NÃO TEM DATA DE VENCIMENTO PRA APLICAR DESCONTO NOS PRODUTOS QUE
          // VENCEM EM 3 DIAS
        }
      }
    }
  }
