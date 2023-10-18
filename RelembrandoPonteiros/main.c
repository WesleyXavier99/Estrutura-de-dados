#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *criaPonteiro(int **pp, int *tam, int pos, int x, int y, int z);
int main() {
  int capacidade = 3;
  int tam = 0, pos;
  int i;
  int x;
  int **y = (int **)malloc(sizeof(int) * (capacidade * 2));

  for (pos = 0; pos < capacidade; pos++) {
    criaPonteiro(y, &tam, pos, 100 * (pos + 1), 200 * (pos + 1),
                 300 * (pos + 1));
  }

  return 0;
}

int *criaPonteiro(int **pp, int *tam, int pos, int x, int y, int z) {

  int **p = (int *)malloc(sizeof(int) * (3 * 2));

  p[0] = x;
  p[1] = y;
  p[2] = z;

  pp[pos] = p;
  (*tam)++;
  return p;
}