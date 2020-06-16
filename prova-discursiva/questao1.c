#include <stdio.h>

void ler(x, y, z)
{
  int n = 10;
  int vet[n];
  for (int i = 0; i < n; i++)
  {
    if (x == y)
    {
      vet[i] = x;
    }
    else
    {
      vet[i] = y;
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (x > 0)
    {
      vet[i] = z;
      if (z == y)
      {
        vet[i] = y;
      }
    }
  }

  return vet;
}

int main()
{

  ler(2, 2, 2);

  return 0;
}