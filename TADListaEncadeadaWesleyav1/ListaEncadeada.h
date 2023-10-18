typedef struct lista tLista;
typedef struct no tNo;

tLista *lista_cria(int classif, int ehRep);
int lista_classif(tLista *l);
int lista_comRep(tLista *l);
int busca(tLista *l, int chave, tNo **ant, tNo **atual);
int lista_inclui(tLista *l, int info);
int lista_vazia(tLista *l);
int lista_exclui(tLista *l, int chave);
void lista_exibe(tLista *l);
tLista* copiaKNos(tLista *l, int k);