typedef struct node tNode;
typedef struct ListaDECC tLista;

tNode* cria_node(int info);
tLista* lst_cria(int ehClassif, int comRep);
int lst_ehClassificada(tLista* lst);
int lst_comRepeticao(tLista* lst);
int busca(tLista* lst, int info, tNode** pos);
int lst_insere(tLista* lst,int info);
void lst_imprime(tLista *lst);
int lst_exclui(tLista* lst, int chave);