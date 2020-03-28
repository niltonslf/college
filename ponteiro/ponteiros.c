#include <stdio.h>

int main()
{

  // Ponteiro simples
  int *pNumero;
  int numero = 65;
  pNumero = &numero;

  printf("Numero: %d", *pNumero);

  printf("\n\n");

  // Ponteiro para vetor
  int vetor[5] = {0, 1, 2, 3, 4};
  int *pVetor = &vetor;

  printf("Primeira posição: %d", *(pVetor + 2));
  printf("\n\n");

  // ponteiro para registros (strucs)

  typedef struct
  {
    char name[25];
    int age;
  } pessoa;

  pessoa marcos = {"Marcos", 28};
  pessoa *pMarcos = &marcos;

  printf("Nome pessoa: %s \n", pMarcos->name);
  printf("Idade pessoa: %d", (*pMarcos).age);

  printf("\n\n");
  return 0;
}