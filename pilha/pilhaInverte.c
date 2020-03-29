#include <stdio.h>
#include <stdlib.h>

#include "./pilha.h"

int main()
{
  char texto[15] = "Apenas um teste";
  Pilha P = criaPilha(15);
  Pilha PAux = criaPilha(15);

  for (int i = 14; i >= 0; i--)
    printf("%c\n", texto[i]);
  // empilha(texto[i], P);

  // while (!vazia(P))
  // {
  //   printf("%c", desempilha(P));
  // }

  printf("\n\n");

  return 0;
}