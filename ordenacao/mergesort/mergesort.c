#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int vetor[], int comeco, int fim);
void merge(int vetor[], int comeco, int meio, int fim);

int main(void)
{

  int SIZE = 5;
  int dados[5] = {4,7,2,1,5};

  // DEBUG
  for (int i = 0; i < SIZE; i++)
    printf("%d ", dados[i]);

  mergeSort(dados, 0, SIZE);

  // DEBUG
  printf("\n");
  for (int i = 0; i < SIZE; i++)
    printf("%d ", dados[i]);

  return 1;
}

void mergeSort(int vetor[], int comeco, int fim)
{
  if (comeco < fim)
  {
    int meio = floor((comeco  + fim) / 2);

    mergeSort(vetor, comeco, meio);
    mergeSort(vetor, meio + 1, fim);
    merge(vetor, comeco, meio, fim);
  }
}

void merge(int vetor[], int comeco, int meio, int fim)
{
  int com1 = comeco, 
      com2 = meio+1, 
      comAux = 0, 
      tam = fim-comeco+1;

  int *vetAux;
  vetAux = (int*) malloc(tam * sizeof(int));

  while (com1 <= meio && com2 <= fim) 
  {

    printf("\ncom1 %d < com2 %d", vetor[com1],vetor[com2]);

    if(vetor[com1] < vetor[com2]) {
      vetAux[comAux] = vetor[com1];
      com1++;
    } else {
      vetAux[comAux] = vetor[com2];
      com2++;
    }
    comAux++;
  }
  

  while (com1 <= meio) 
  {
    vetAux[comAux] = vetor[com1];
    comAux++;
    com1++;
  }

  while (com2 <= fim) 
  {
    vetAux[comAux] = vetor[com2];
    comAux++;
    com2++;
  }
  
    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
      vetor[comAux] = vetAux[comAux-comeco];
  }
  
  free(vetAux);

}
