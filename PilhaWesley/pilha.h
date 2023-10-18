typedef struct no tNo;
typedef struct pilha tPilha;

tPilha* pilha_Cria(tPilha* pilha);
int pilha_Vazia(tPilha* pilha);
int pilha_Tamanho(tPilha* pilha);
int pilha_Topo(tPilha* pilha, tNo*topo);
void pilha_Empilha(tPilha* pilha, int valor);
int pilha_Desempilha(tPilha* pilha);
int pilha_Esvazia(tPilha* pilha);
tNo* no_Cria();