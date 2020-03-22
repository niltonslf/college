#include <stdio.h>

int binarySearch(int vetor[], int element, int size);

int main()
{
  int vetor[10] = {0, 1, 2, 3, 4, 5, 6, 9, 7, 8};

  int element = binarySearch(vetor, 5, 10);

  printf("%d \n", element);

  return 0;
}

int binarySearch(int vetor[], int element, int size)
{
  int first = 0;
  int last = size - 1;

  while (first <= last)
  {
    int middle = (first + last) / 2;

    if (element == vetor[middle])
      return middle;

    if (element < vetor[middle])
      last = middle - 1;
    else
      first = middle + 1;
  }
  return -1;
}