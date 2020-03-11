#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void mergeSort(int vetor[], int comeco, int fim);
void merge(int vetor[], int comeco, int meio, int fim);

int main(void)
{

  int SIZE = 15;
  int dados[15] = {5,4,3,2,1,39,6,8,9,10,11,12,13,50,80};

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
    int meio = floor((comeco  + fim) / 2); // (0 + 9) / 2 = 4.5
    mergeSort(vetor, comeco, meio);
    mergeSort(vetor, meio + 1, fim);
    merge(vetor, comeco, meio, fim);
  }
}

void merge(int vetor[], int comeco, int meio, int fim)
{
  int comecoParte1 = comeco;
  int fimParte1 = 0;

  int comecoParte2 = meio + 1;
  int fimParte2 = 0;

  int tamanho = fim - comeco + 1;

  int *temp; // vetor auxiliar temporário
  temp = (int *) malloc(tamanho * sizeof(int));

  if(temp != NULL){
    for (int i = 0; i < tamanho; i++) {
      if (!fimParte1 && !fimParte2) { // enquanto não chegar no final dos vetores 
        // Faz a ordenação
        if (vetor[comecoParte1] < vetor[comecoParte2]) {
          temp[i] = vetor[comecoParte1];
          comecoParte1++;
        } else {
          temp[i] = vetor[comecoParte2];
          comecoParte2++;
        }
        // Verifica se chegou no fim das duas metades
        if (comecoParte1 > meio) fim = 1;
        if (comecoParte2 > fim) fimParte2 = 1;
      } else {
        if (!fimParte1) {
          temp[i] = vetor[comecoParte1];
          comecoParte1++;
        } else {
          temp[i] = vetor[comecoParte2];
          comecoParte2++;
        }
      }
    }
  }

  int j, k;
  for (j = 0, k = comeco; j < tamanho; j++, k++)
  {
    vetor[k] = temp[j];
  }

  free(temp);
}
