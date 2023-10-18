/* TAD: Circulo (x,y,r) */
/* Tipo exportado */
typedef struct circulo Circulo;
typedef struct ponto Ponto;

/* Funções exportadas */
/* Função cria - Aloca e retorna um circulo com coordenadas e um raio (x,y,r) */
Circulo *circ_cria(float x, float y, float r);

/* Função libera - Libera a memória de um circulo previamente criado */
void circ_destroi(Circulo *c);

/* Função acessa - Retorna os valores das coordenadas e do raio */
void circ_acessa(Circulo *c, float *x, float *y, float *r);

/* Função compara - compara se dois circulos têm a mesma circunferência*/
int circ_compara(Circulo *c1, Circulo *c2);

/* Função clona - clona um circulo*/
Circulo *circ_clona(Circulo *c);

/* Função imprime - imprime um circulo na tela*/
void circ_imprime(Circulo *c);

/* Função area - calcula a area de um circulo*/
float circ_area(Circulo *c);

/* Função interior - */
float circ_interior(Circulo *c, Ponto *p);

/* Função distancia X - */
float circ_distanciaX(Circulo *c);

/* Função distancia Y - */
float circ_distanciaX(Circulo *c);

/* Função atribui - Atribui novos valores à coordenada x de um ponto do circulo
 */
void circ_atribuiX(Circulo *c, float x);

/* Função atribui - Atribui novo valor à coordenada y de um ponto do circulo*/
void circ_atribuiY(Circulo *c, float y);

/* Função atribui - Atribui novo valor ao raio de um circulo */
void circ_atribuiR(Circulo *c, float r);


/* Função distancia - Retorna a distância entre dois pontos */
float pto_distancia(Ponto *p1, Ponto *p2);

/* Função distancia - Retorna a distância entre dois círculos */
float circ_distancia(Circulo *c1, Circulo *c2);

/* Função getPonto - Retorna uma string com os valores do ponto formato(x,y)*/
char *pto_getPonto(Ponto *p);

/* Função obtem - */
float *circ_obtemX(Circulo *c);