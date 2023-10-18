#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int faixa;
  char *nome;
  int tempo;
  char *compositor;
} tMusica;

typedef struct {
  int numero;
  char *nome;
  char *banda;
  char *gravadora;
  int ano;
  int numFaixas;
  tMusica *faixas;
} tCD;

tMusica addMusica();
tCD *addCD();
tCD** addAcervo(tCD **, int *);
void addAcervo2(tCD **, int *);
void exibirAcervo(tCD **acervo, int tam);

int main(void) {
  int tamanho = 0, i, j;
  tCD **acervo;

  acervo = addAcervo(acervo, &tamanho);
  
  exibirAcervo(acervo,tamanho);
  
  return 0;
}

tMusica addMusica() {
	tMusica musica;
	char* aux; 
	int t1=0,faixa;
	float tempo;
	char nome[45],comp[45];
	
	//obtendo informações do cd
	printf("\n----Digite as informações da Musica----\n");
	
	printf("\nfaixa:");
	scanf("%d",&faixa);
	musica.faixa = faixa;
	
	printf("\nnome:");
	fflush(stdin);
	gets(nome);
	aux = (char*)malloc((sizeof(char)*(strlen(nome)+1)));
	strcpy(aux,nome);
	musica.nome = aux;
	
	printf("\ntempo:");
	scanf("%d",&tempo);
	musica.tempo = tempo;
	
	printf("\ncompositor:");
	fflush(stdin);
	gets(comp);
	aux = (char*)malloc((sizeof(char)*(strlen(comp)+1)));
	strcpy(aux,comp);
	musica.compositor = aux;
	
	return musica;
}

tCD *addCD(tCD** acervo, int* tam) {
	int i,aux;
	char *n;
	char nome[40],banda[40],grav[40];
	tCD *c;
	
	//aloca memoria para o cd
	c = (tCD *)malloc(sizeof(tCD));
	
	//obtendo informações do cd
	printf("\n----Digite as informações do CD----\n");
	
	printf("\nnumero:");
	scanf("%d",&aux);
	c->numero = aux;
	
	printf("\nano:");
	scanf("%d",&aux);
	c->ano = aux;
	
	printf("\nnome:");
	fflush(stdin);
	gets(nome);
	n = (char*)malloc((sizeof(char)*(strlen(nome)+1)));
	strcpy(n,nome);
	c->nome = n;
	
	printf("\nbanda:");
	fflush(stdin);
	gets(banda);
	n = (char*)malloc((sizeof(char)*(strlen(banda)+1)));
	strcpy(n,banda);
	c->banda = n;
	
	printf("\ngravadora:");
	fflush(stdin);
	gets(grav);
	n = (char*)malloc((sizeof(char)*(strlen(grav)+1)));
	strcpy(n,grav);
	c->gravadora = n;
	
	printf("\nNumero de faixas: ");
	scanf("%d", &aux);
	c->numFaixas = aux;
	
	//alocando memoria para as nfaixas
	c->faixas = (tMusica*)malloc(sizeof(tMusica)*aux);
	
	//criando as musicas
	for (i = 0; i < aux; i++) {
		c->faixas[i] = addMusica();
	}
	
	//apontando o acervo para o CD novo
	acervo[(*tam)] = c;
	
	//atualizando o tamanho do acervo
	(*tam)++;
	
	return c;
}

tCD** addAcervo(tCD ** acervo, int *tam) {
	int aux=0, i;
	tCD* cdaux;
	
	printf("Digite o numero de CDs:\n");
	scanf("%d",&aux);
	

	//aloca memoria para o CD
	acervo = (tCD**)malloc(sizeof(tCD)*aux);
	  
	//alocando auxiliar para o CD
	cdaux = (tCD*)malloc(sizeof(tCD)*aux);
	  
	//incluindo o(s) cd(s) no acerco
	for (i = 0; i < aux; i++) {
		cdaux= addCD(acervo, tam);
		acervo[i] =cdaux ;
	}
	
	//atualizando o tamanho do acervo
	*tam = aux;
  
  return acervo;
}

void exibirAcervo(tCD** acervo,int tam){
	int i,j;
	printf("\t\ttempo: %d\n",acervo[i][0].faixas[j].tempo );
	
	for(i=0;i<tam;i++){
		printf("\t\tCD %d\n",i+1 );
		printf("\t\tNumero: %d\n", acervo[i][0].numero);
		printf("\t\tNome: %s\n", acervo[i][0].nome);
		printf("\t\tBanda: %s\n", acervo[i][0].banda);
		printf("\t\tGravadora: %s\n", acervo[i][0].gravadora);
		printf("\t\tAno: %d\n", acervo[i][0].ano);
		printf("\t\tNumero de Faixas: %d\n", acervo[i][0].numFaixas);
		for(j=0;j<(acervo[i][0].numFaixas);j++){
			printf("\t\tFaixa: %d\n",acervo[i][0].faixas[j].faixa );
			printf("\t\tNome: %s\n",acervo[i][0].faixas[j].nome );
			printf("\t\tTempo: %d\n",acervo[i][0].faixas[j].tempo );
			printf("\t\tCompositor: %s\n",acervo[i][0].faixas[j].compositor );
		}
	}
}