#include <stdio.h>
#include <stdlib.h>

#define filaAvanca(i) (i = (i + 1) % F->max)

typedef char Itemf;

typedef struct fila
{
  int max;
  int total;
  int inicio;
  int final;
  Itemf *item;
} * Fila;

Fila criaFila(int size)
{
  Fila F = malloc(sizeof(struct fila));
  F->max = size;
  F->total = 0;
  F->inicio = 0;
  F->final = 0;
  F->item = malloc(size * sizeof(Itemf));
  return F;
}

int filaVazia(Fila F)
{
  return (F->total == 0);
}

int filaCheia(Fila F)
{
  return (F->total == F->max);
}

Itemf filaEnfileira(Itemf elemento, Fila F)
{
  if (filaCheia(F))
  {
    puts("Pilha cheia!");
    abort();
  }

  F->item[F->final] = elemento;
  filaAvanca(F->final);
  F->total++;
}

Itemf FilaDesenfileira(Fila F)
{
  if (filaVazia(F))
  {
    puts("Fila Vazia");
    abort();
  }

  Itemf res = F->item[F->inicio];
  filaAvanca(F->inicio);
  F->total--;
  return res;
}

void FilaDestroi(Fila *F)
{
  free((*F)->item);
  free(*F);
  *F = NULL;
}

int main(int argc, char const *argv[])
{

  Fila filaDaputa = criaFila(3);
  filaEnfileira(2, filaDaputa);
  filaEnfileira(1, filaDaputa);
  filaEnfileira(4, filaDaputa);

  printf("%d\n", FilaDesenfileira(filaDaputa));
  filaEnfileira(4, filaDaputa);
  printf("%d\n", FilaDesenfileira(filaDaputa));
  printf("%d\n", FilaDesenfileira(filaDaputa));
  printf("%d\n", FilaDesenfileira(filaDaputa));

  return 0;
}