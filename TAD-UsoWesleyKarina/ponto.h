/* TAD: Ponto (x,y) */
/* Tipo exportado */

typedef struct ponto Ponto;
/* Funções exportadas */
/* Função cria - Aloca e retorna um ponto com coordenadas (x,y) */
Ponto *pto_cria(float x, float y);
/* Função libera - Libera a memória de um ponto */
void pto_libera(Ponto *p);
/* Função acessa - Retorna as coordenadas de um ponto */
void pto_acessa(Ponto *p, float *x, float *y);
/* Função atribui - Atribui valores às coordenadas do ponto */
void pto_atribui(Ponto *p, float x, float y);
/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto *p1, Ponto *p2);