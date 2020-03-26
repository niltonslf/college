#include <stdio.h>

int binarySearch(int vetor[], int low, int high, int element);

int main()
{
  int vetor[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
  int element = binarySearch(vetor, 0, 9, 0);

  printf("%d \n", element);
  return 0;
}

int binarySearch(int arr[], int low, int high, int element)
{

  if(high >= low) {
    int mid = low + (high - low) / 2 ;

    if(arr[mid] == element) return mid;
    if(arr[mid] > element) return binarySearch(arr, low, mid -1, element);

    return binarySearch(arr, mid +1, high, element);
  }

  return -1;
}