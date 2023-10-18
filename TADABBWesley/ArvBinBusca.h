// Adaptado de Alexandre Xavier Falcao -Instituto de Computacão - UNICAMP
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX(a,b) ((a > b)?a:b)
#define TAM_MAX 100

/* Arvore Binaria de Busca com valores menores na subarvore esquerda e
   maiores ou iguais na subarvore direita de cada no */

typedef struct NoABBusca NoABBusca, ABBusca;

/* cria no folha (insercao eh sempre de no folha) */

NoABBusca *CriaNovoNo(int info); 

/* Esta função deve inserir o valor da variável "valor" na árvore
   binária de busca representada pela variável "ab". Note que valores
   iguais devem ser inseridos sempre à direita. */

void InsereValor(ABBusca **ab, int valor); 

/* Esta função deve percorrer a árvore ab em pré-ordem e gerar uma
   cadeia de caracteres s com os valores visitados em pré-ordem
   separados por um espaço em branco. */

void VisitaPreOrdem(ABBusca *ab, char **s); 

/* Esta função deve percorrer a árvore ab em in-ordem e gerar uma
   cadeia de caracteres s com os valores visitados em in-ordem
   separados por um espaço em branco. */

void VisitaInOrdem(ABBusca *ab, char **s); 

/* Esta função deve percorrer a árvore ab em pós-ordem e gerar uma
   cadeia de caracteres s com os valores visitados em pós-ordem
   separados por um espaço em branco. */

void VisitaPosOrdem(ABBusca *ab, char **s);  

/* Esta função deve remover o valor da variável "valor" da árvore
   binária de busca representada pela variável "ab". Note que no caso
   de remoção de nó de grau 2, seu valor deve ser substituído pelo
   valor do menor sucessor (no a esquerda com menor valor da subarvore
   direita), e o no sucessor deve ser removido. Isso porque a arvore
   resolve a igualdade inserindo o no na subarvore direita. Este
   sucessor nao tem filho a esquerda, mas pode ter filho a
   direita. Portanto, o no pai do sucessor deve apontar para o seu
   filho a direita antes da remocao do sucessor. Se a igualdade fosse
   resolvida com insercao na subarvore esquerda, deveriamos procurar o
   maior antecessor para substituicao. Neste caso, ele nao teria filho
   a direita, mas poderia ter filho a esquerda e o seu no pai deveria
   apontar para o filho a esquerda antes da remocao. */

void RemoveValor(ABBusca **ab, int valor); 

/* Esta função deve liberar todo espaço de memória alocado para a
   árvore */

void DestroiABBusca(ABBusca **ab); 

/* Esta função deve calcular e retornar o número de nós da árvore
   ab */

int  NumerodeNos(ABBusca *ab); 

/* Esta função deve calcular e retornar a altura da árvore ab */

int  Altura(ABBusca *ab); 

/* Esta função deve calcular os k maiores valores armazenados na
   árvore ab e retorná-los em ordem decrescente e separados por um
   espaço em branco na cadeia de caracteres s */

void MaioresValores(ABBusca *ab, char **s, int *k); 

/* Esta função deve calcular os k menores valores armazenados na
   árvore ab e retorná-los em ordem crescente e separados por um
   espaço em branco na cadeia de caracteres s */

void MenoresValores(ABBusca *ab, char **s, int *k); 

/* Esta função supõe que a árvore ab armazena apenas valores não
   negativos. Ela deve calcular o maior valor K armazenado na árvore e
   criar um vetor de freqüência f de tamanho n=K+1. Depois ela deve
   calcular e armazenar em f[i] o número de ocorrências do valor i na
   árvore ab. Por fim, ela deve retornar o vetor f e seu tamanho n. */

void Frequencia(ABBusca *ab, int **f, int *n); 

/* Esta função deve remover da árvore ab todos os valores repetidos
   deixando apenas uma ocorrência de cada valor. */

void EliminaRepetidos(ABBusca **ab); 

/* Imprime arvore binaria na tela onde h (altura do no) indica que ele
   sera precedido de h caracteres '-' antes de sua impressao. A funcao
   e chamada com h=0. */

void ImprimeABBusca(ABBusca *ab, int h, int altura);

/* Arvore Equilibrada: aquela que os numeros de nos das subarvores
   direita e esquerda nao diferem mais do que 1 para qualquer no. */

char Equilibrada(ABBusca *ab, int *N); 


//-> dado um valor, retorne o nível do nó que contém o valor
int NivelNo(ABBusca *ab, int chave,int *nivel);

 //--> dado um valor, retorne a quantidade de nós da árvore maior que o valor
int NosMaiores(ABBusca *ab, int chave, int *qtd);







