#include <stdio.h>
#include <stdlib.h>

#include "./pilha.h"

int main()
{
  Pilha P = criaPilha(3);
  empilha('a', P);
  empilha('b', P);

  printf("dado: %c \n", desempilha(P));
  printf("dado: %c \n", desempilha(P));
  printf("dado: %c \n", desempilha(P));

  printf("\n\n");

  return 0;
}