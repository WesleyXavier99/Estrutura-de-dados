typedef struct no tNo;
typedef struct fila tFila;

void fila_Cria(tFila *fila);
int fila_Vazia(tFila *fila);
void fila_Insere(tFila *fila, int chave);
int fila_Remove(tFila *fila);
int fila_Tamanho(tFila *fila);
tNo* fila_Primeiro(tFila *fila);
tNo* cria_No();