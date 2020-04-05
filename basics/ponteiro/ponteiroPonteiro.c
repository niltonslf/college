#include <stdio.h>

int main()
{

  int x = 10;
  int *p = &x;
  int **p2 = &p;

  printf("p2: %d\n", p2);     // p2 aponta para o endereço de memória de *p   | &p
  printf("*p2: %d\n", *p2);   // *p2 aponta para o endereço de meória de x  | &x
  printf("**p2: %d\n", **p2); // valor de x

  printf("\n");

  char letra = 'a';
  char *l = &letra;
  char **l2 = &l;
  char ***l3 = &l2;

  printf("*l: %c \n", *l);
  printf("**l2: %c \n", **l2);
  printf("***l: %c \n", ***l3);

  printf("\n\n");

  printf("Teste: %c \n\n", *l);
  return 0;
}