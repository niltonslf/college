#include <stdio.h>

int linearSearch(int element, int arr[], int size);

int main()
{

  int arr[10] = {5, 6, 12, 9, 8, 55, 7, 19, 20, 1000};
  int size = sizeof(arr) / sizeof(arr[0]);

  int response = linearSearch(55, arr, size);

  printf("index do elemento: %d \n", response);

  return 0;
}

int linearSearch(int element, int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == element)
      return i;
  }
  return -1;
}