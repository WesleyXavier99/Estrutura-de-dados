#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
struct node {
  int info;
  struct node *ant,*suc;
};

struct ListaDECC{
  tNode* prim;
  int ehClassif;
  int comRep;
};

tNode* cria_node(int info){
  tNode* novo = (tNode*)malloc(sizeof(tNode));
  novo->info = info;
  novo->ant= NULL;
  novo->suc= NULL;
  return novo; 
  }

tLista* lst_cria(int ehClassif, int comRep){
  tLista* lst = (tLista*)malloc(sizeof(tLista));
  lst->ehClassif= ehClassif;
  lst->comRep= comRep;
  lst->prim = cria_node(0);
  lst->prim->ant = lst->prim;
  lst->prim->suc = lst->prim;
  return lst;
}

int lst_ehClassificada(tLista* lst){
  return lst->ehClassif;
}

int lst_comRepeticao(tLista* lst){
  return lst->comRep;
}

int busca(tLista* lst, int info, tNode** pos){
  tNode* aux = lst->prim->suc;
  lst->prim->info = info;
  
  while(aux!=lst->prim){
      if(aux->info>=info){
        (*pos) = aux;
        if(aux->info==info){
          return 1;
        }
        return 0;
      }
    aux= aux->suc;
  }
  (*pos) = lst->prim;
  return 0;
}

int lst_insere(tLista* lst,int info){
  tNode* novo = cria_node(info);
  int sit;
  tNode* pos;

  sit = busca(lst,info,&pos);
  if(!lst_ehClassificada(lst)){
    if(!lst_comRepeticao(lst)&&sit){
      return 0;
    }else{
      novo->ant = lst->prim->ant;
      novo->suc = lst->prim;
      lst->prim->ant->suc=novo;
      lst->prim->ant = novo;
    }
  }else{
    if(!lst_comRepeticao(lst)&&sit){
      return 0;
    }else{
      novo->ant = pos->ant;
      novo->suc = pos;
      pos->ant->suc=novo;
      pos->ant = novo;
    }
  }
}            


void lst_imprime(tLista *lst){
  tNode* aux=lst->prim->suc;
  int i=1;
  while(aux!=lst->prim){
    printf("no: %d\ninfo: %d\n",i,aux->info);
    aux = aux->suc;
    i++;
  }
}

//criada para a exclusão
int lst_vazia(tLista *lst){
  if(lst->prim==lst->prim->suc){
    return 1;
  }
  return 0;
}

int lst_exclui(tLista* lst, int chave){
  int sit;
  tNode* pos,*aux;
  
  if(lst_vazia(lst)){
    return 0;
  }
  
   sit = busca(lst,chave,&pos);
  if(sit){
    return 0;
  }
  
  if(!lst_ehClassificada(lst)){
    if(!lst_comRepeticao(lst)){
        pos->ant->suc = pos->suc;
        pos->suc->ant = pos->ant;
        free(pos);
        return 1;
    }else{
      do{
        pos->ant->suc = pos->suc;
        pos->suc->ant = pos->ant;
        free(pos);
      }while(busca(lst,chave,&pos));
      return 1;
    }
  }else{
    if(lst_comRepeticao(lst)){
      aux = pos;
      while(aux->info == chave){
        pos->ant->suc = pos->suc;
        pos->suc->ant = pos->ant;
        aux = pos->suc;
        free(pos);
        return 1;
      }
    }else{
        pos->ant->suc = pos->suc;
        pos->suc->ant = pos->ant;
        free(pos);
      return 1;
    }
  }
}