#include <stdio.h>
#include <stdlib.h>

// #include "./pilha.h"
#include "./pilhaFloat.h"

int main()
{
  // Pilha P = criaPilha(3);
  // empilha('a', P);
  // empilha('b', P);

  // printf("dado: %c \n", desempilha(P));
  // printf("dado: %c \n", desempilha(P));
  // printf("dado: %c \n", desempilha(P));

  // printf("\n\n");

  Pilha P = criaPilha(1000);
  empilha(8, P);

  while (topo(P) > 0)
    empilha(topo(P) / 2, P);

  int i = 0;
  while (!vazia(P))
    printf("i: %d - Valor: %f \n", i++, desempilha(P));
  return 0;
}