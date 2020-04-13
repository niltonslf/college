#include <stdlib.h>
#include <stdio.h>

typedef int Itemp;

typedef struct pilha
{
  int max;
  int topo;
  Itemp *item;
} * Pilha;

Pilha criaPilha(int m)
{

  Pilha P = malloc(sizeof(struct pilha));
  P->max = m;
  P->topo = -1;
  P->item = malloc(m * sizeof(Itemp));

  return P;
}

int vazia(Pilha P)
{
  if (P->topo == -1)
    return 1;
  return 0;
}

int cheia(Pilha P)
{
  if (P->topo == P->max - 1)
    return 1;
  return 0;
}

void empilha(Itemp elemento, Pilha P)
{
  if (cheia(P))
  {
    puts("Pilha cheia caralho!");
    abort();
  }
  P->topo++;
  P->item[P->topo] = elemento;
}

Itemp desempilha(Pilha P)
{
  if (vazia(P))
  {
    puts("Pilha vazia caralho!");
    abort();
  }

  Itemp res = P->item[P->topo];
  P->topo--;
  return res;
}

Itemp topo(Pilha P)
{
  if (vazia(P))
  {
    puts("Pilha vazia caralho!");
    abort();
  }

  return P->item[P->topo];
}

void destroi(Pilha *P)
{
  free((*P)->item);
  free(P);

  *P = NULL;
}
