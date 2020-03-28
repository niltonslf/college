#include <stdio.h>
#include <string.h>

typedef struct
{
  char valor[10];
} Str;

int main()
{

  Str x = {"Um"};
  Str y = {"dois"};

  puts(x.valor);
  printf("\n");

  x = y;

  puts(x.valor);
  printf("\n");

  return 0;
}