#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void mergeSort(int vetor[], int left, int right);
void merge(int vetor[], int left, int right, int middle);

int main()
{
  int vetor[5] = {7, 8, 1, 9, 70};
  mergeSort(vetor, 0, 4);

  for (int i = 0; i < 5; i++)
    printf("%d ", vetor[i]);

  return 0;
}

/**
 * INTERCALAÇÃO DOS ELEMENTOS
 **/
void merge(int vetor[], int left, int right, int middle)
{
  int *aux = (int *)malloc((right - left + 1) * sizeof(int));
  if (aux == NULL)
    abort();

  int i, j, k, tam;
  i = left;
  j = middle + 1;
  k = 0;
  tam = right - left;

  while (i <= middle && j <= right)
  {

    if (vetor[i] < vetor[j])
      aux[k++] = vetor[i++];
    else
      aux[k++] = vetor[j++];

    while (i <= middle)
      aux[k++] = vetor[i++];

    while (j <= right)
      aux[k++] = vetor[j++];
  }

  for (k = 0; k <= tam; k++)
    vetor[left + k] = aux[k];

  free(aux);
}

/**
 * SEPARAÇÃO DOS SUBCONJUNTOS
 **/
void mergeSort(int vetor[], int left, int right)
{
  if (left < right)
  {
    int middle = floor((right + left) / 2);

    mergeSort(vetor, left, middle);
    mergeSort(vetor, middle + 1, right);
    merge(vetor, left, right, middle);
  }
}