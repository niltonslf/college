#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void mergeSort(int vetor[], int left, int right);
void merge(int vetor[], int left, int right, int middle);

int main()
{
  int vetor[5] = {5, 4, 3, 2, 1};
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
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 = right - middle;

  /* create temp arrays */
  int Left[n1], Right[n2];

  /* Copy data to temp arrays Left[] and Right[] */
  for (i = 0; i < n1; i++)
    Left[i] = vetor[left + i];
  for (j = 0; j < n2; j++)
    Right[j] = vetor[middle + 1 + j];

  /* Merge the temp arrays back into vetor[left..right]*/
  i = 0;    // Initial index of first subarray
  j = 0;    // Initial index of second subarray
  k = left; // Initial index of merged subarray
  while (i < n1 && j < n2)
  {
    if (Left[i] <= Right[j])
    {
      vetor[k] = Left[i];
      i++;
    }
    else
    {
      vetor[k] = Right[j];
      j++;
    }
    k++;
  }

  /* Copy the remaining elements of Left[], if there 
       are any */
  while (i < n1)
  {
    vetor[k] = Left[i];
    i++;
    k++;
  }

  /* Copy the remaining elements of Right[], if there 
       are any */
  while (j < n2)
  {
    vetor[k] = Right[j];
    j++;
    k++;
  }
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