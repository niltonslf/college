#include <stdio.h>

int binary_search(int x, int data[], int n);

void main(void)
{
  int data[10] = {5, 7, 8, 14, 24, 29, 56, 77, 78, 88};

  binary_search(78, data, 7);
}

int binary_search(int x, int data[], int n)
{
  int first = 0;
  int last = n - 1;
  while (first <= last)
  {
    printf("ITERAÇÃO\n");
    int mid = (first + last) / 2;
    if (x == data[mid])
      return 1;

    if (x < data[mid])
      last = mid - 1;
    else
      first = mid + 1;
  }
}