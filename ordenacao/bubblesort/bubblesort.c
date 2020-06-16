#include <stdio.h>
#include "./bubblesort.h"

/**
 *  Complexidade assintótica de O(n²)
 */

int main(void)
{

  int SIZE = 5;
  int vetor[5] = {8, 10, 2, 5, 9};

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE - 1; j++)
    {
      int atual = vetor[j];
      int proximo = vetor[j + 1];

      if (proximo < atual)
      {
        vetor[j] = proximo;
        vetor[j + 1] = atual;
      }
    }
  }

  for (int k = 0; k < SIZE; k++)
  {
    printf("valor: %d \n", vetor[k]);
  }

  return 1;
}