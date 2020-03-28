#include <stdio.h>
#include <string.h>

int main()
{

  int a = 3;
  int b = 5;

  int *p = &a;
  int *q = &b;

  *p = *p + *q; // a = 3 + 5 => 8
  *q = *p - *q; // b = 8 - 5 => 3
  *p = *p - *q; // a = 8 - 3 = 5

  printf("a = %d \nb = %d \n", a, b);

  return 0;
}