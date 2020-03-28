#include <stdio.h>

typedef struct
{
  int item;
  struct no *prox;
} no;

int main()
{

  // int v[4] = {1, 4, 3, 70};
  // int *pV = &v;

  // for (int i = 0; i < 4; i++)
  // {
  //   printf("Item:  %d \n", *(pV + i));
  // }
  // printf("\n\n");

  no v[4] = {{3, v + 2}, {1, v + 3}, {4, NULL}, {2, v + 0}};

  for (no *p = v + 1; p != NULL; p = p->prox)
    printf("item: %d\n", p->item);

  
  return 0;
}