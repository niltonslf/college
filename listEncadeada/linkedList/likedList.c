#include <stdio.h>

#define fmt "%d "

typedef int Item;
typedef struct no
{
  Item item;
  struct no *prox;
} * Lista;

Lista criaNo(Item elemento, Lista L)
{
  Lista n = malloc(sizeof(struct no));
  n->item = elemento;
  n->prox = L;
  return n;
}

void exibe(Lista L)
{
  while (L != NULL)
  {
    printf("%d ", L->item);
    L = L->prox;
  }
}

void anexa(Lista *destino, Lista origem)
{
  if (origem == NULL)
    return;

  while (*destino != NULL)
    destino = &(*destino)->prox;
  *destino = origem;
}

int main(int argc, char const *argv[])
{
  Lista minhaLista = criaNo(1, criaNo(2, criaNo(3, criaNo(4, NULL))));
  exibe(minhaLista);

  return 0;
}
