#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
  int item;
  struct No *prox;
} * Lst;

Lst no(int x, Lst p)
{
  Lst n = malloc(sizeof(struct No));
  n->item = x;
  n->prox = p;
  return n;
}

int main()
{
  Lst p = (no(1, no(2, no(3, no(4, NULL)))));
  while (p)
  {
    printf("%d\n", p->item);
    p = p->prox;
  }

  return 0;
}