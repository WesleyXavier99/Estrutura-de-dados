#include <stdio.h>
#include <stdlib.h>

//definindo tipo TMusica
typedef struct{
  int faixa;
  char *nome;
  float tempo;
  char* compositor;
  
}tMusica;

//definindo tipo TCd
typedef struct{
  int numero;
  char* nome;
  char* banda;
  char* gravadora;
  char* anoGravacao;
  int numeroFaixas;
  tMusica* musicas;
}tCd;

tMusica* criaMusica(char * nome, char * compositor, float tempo,int faixa){
  tMusica * p=(tMusica*)malloc(sizeof(tMusica));
  
  p->nome=(char*)malloc(sizeof(strlen(nome)+1));
  p->compositor=(char*)malloc(sizeof(strlen(compositor)+1));
  p->tempo=tempo;
  p->faixa=faixa;
  strcpy(p->nome,nome);
  strcpy(p->compositor,compositor);
  
  return p;
  }

tCd* criaCd(tCd* acervo){
  //variaveis
  int i,nFaixas=2;
  tMusica**musicas = (tMusica**) malloc(sizeof(tMusica)*nFaixas);
  char* nome;
  char* compositor;
  tCd* cd =(tCd*) malloc(sizeof(tCd));
  
  
  //musica 1
  strcpy(nome,"Caminhos");
  strcpy(compositor,"BK'");
  
  musicas[0] = criaMusica(nome, compositor,2.33,1);
  //musica 2
  strcpy(nome,"Quadros");
  strcpy(compositor,"BK'");
  musicas[1] = (tMusica*) malloc(sizeof(tMusica));
  musicas[1] = criaMusica(nome, compositor,3.26,2);

  cd->musicas = musicas;
  
  return cd ;
}

void exibeCd(tCd acervo,int qt){
  int i;

  for(i=0;i<qt;i++){
    printf("",acervo[i]->)
  }
}

int main(void) {

  //variaveis
  tCd* *acervo;
  int nCDs,i;

  
  printf("Digite qunatos cds:\n");
  scanf("%d", &nCDs);

  for(i=0;i<nCDs;i++){
    acervo[i]=(tCd*)malloc(sizeof(tCd));
    acervo[i] = criaCd(acervo);
  }

  
  return 0;
}