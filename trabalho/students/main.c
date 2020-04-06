#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Aluno
{
  char name[50];
  char email[50];
  int ru;
} Aluno;

void showSingleStudent(Aluno aluno);
void showStudents(Aluno alunos[], int length);
void managerMenu(Aluno alunos[], int length);

int binarySearch(Aluno arr[], int low, int high, int element);

void merge(Aluno vetor[], int left, int right, int middle);
void mergeSort(Aluno vetor[], int left, int right);

/**
 *  Busca binária
 **/
int binarySearch(Aluno arr[], int low, int high, int element)
{

  if (high >= low)
  {
    int mid = low + (high - low) / 2;

    if (arr[mid].ru == element)
      return mid;
    if (arr[mid].ru > element)
      return binarySearch(arr, low, mid - 1, element);

    return binarySearch(arr, mid + 1, high, element);
  }

  return -1;
}

/**
 * INTERCALAÇÃO DOS ELEMENTOS
 **/
void merge(Aluno vetor[], int left, int right, int middle)
{
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 = right - middle;

  /* cria arrays temporarios */
  Aluno Left[n1], Right[n2];

  /* Copia os dados para cada array temporário (esquerdo e direito) */
  for (i = 0; i < n1; i++)
    Left[i] = vetor[left + i];
  for (j = 0; j < n2; j++)
    Right[j] = vetor[middle + 1 + j];

  /* faz o merge dos dos lados do array com o vetor */
  i = 0;    // index iniciado do primeiro subvetor
  j = 0;    // index iniciado do segundo subvetor
  k = left; // index iniciado do subvetor mergeado

  while (i < n1 && j < n2)
  {
    if (Left[i].ru <= Right[j].ru) // *especifico para struct Aluno. Verifica se o Ru presenta na esquerda é menor ou igual ao da direita
    {
      vetor[k] = Left[i];
      i++;
    }
    else
    {
      vetor[k] = Right[j];
      j++;
    }
    k++;
  }

  /* ser houver algum, copia os itens restantes do vetor left */
  while (i < n1)
  {
    vetor[k] = Left[i];
    i++;
    k++;
  }
  /* ser houver algum, copia os itens restantes do vetor right */
  while (j < n2)
  {
    vetor[k] = Right[j];
    j++;
    k++;
  }
}

/**
 * SEPARAÇÃO DOS SUBCONJUNTOS
 **/
void mergeSort(Aluno vetor[], int left, int right)
{
  if (left < right)
  {
    int middle = floor((right + left) / 2);

    mergeSort(vetor, left, middle);
    mergeSort(vetor, middle + 1, right);
    merge(vetor, left, right, middle);
  }
}

void showStudents(Aluno alunos[], int length)
{
  for (int i = 0; i < length; i++)
  {
    showSingleStudent(alunos[i]);
  }
}

void showSingleStudent(Aluno aluno)
{

  printf("=======================\n");
  printf("Aluno: %s \n", aluno.name);
  printf("E-mail: %s \n", aluno.email);
  printf("RU: %d \n", aluno.ru);
  printf("=======================\n");
}

void managerMenu(Aluno alunos[], int length)
{
  int option = -1;
  while (option != 0) // LOOP INFINITO COM O MENU
  {
    printf("\n--------- MENU ---------\n");
    printf("1- ver todos os alunos\n");
    printf("2- Buscar por um aluno\n");
    printf("0- Fechar programa\n");

    // RECEBE OPÇÃO DESEJADA PELO USUÁRIO
    printf("\nDigite o código da opção desejada: ");
    scanf("%d", &option);

    system("clear");

    /**
   *  TRATANTO OPÇÕES DO MENU
   **/
    switch (option)
    {

    case 1:
      printf("\n--------- ALUNOS ---------\n");
      showStudents(alunos, length);
      break;

    case 2:
      printf("\n---------BUSQUE POR UM ALUNO ---------\n");
      printf("Digite o RU do aluno: ");
      int ru;
      scanf("%d", &ru);
      // salva o indice do aluno encontrado
      int alunoIndex = binarySearch(alunos, 0, length, ru);

      if (alunoIndex == -1)
      {
        printf("\n---------ALUNO NÃO ENCONTRADO ---------\n");
      }
      else
      {
        printf("\n---------ALUNO ENCONTRADO ---------\n");
        showSingleStudent(alunos[alunoIndex]);
      }

      break;
    }
  }
}

int main()
{

  Aluno aluno1 = {"Nilton Lopes", "niltonrck@gmail.com", 3232971};
  Aluno aluno2 = {"James brown", "teste1@gmail.com", 2232971};
  Aluno aluno3 = {"Charlie nunes", "teste2@gmail.com", 3232970};
  Aluno aluno4 = {"Tim berners-lee", "teste3@gmail.com", 1112971};
  Aluno aluno5 = {"Ana story", "teste4@gmail.com", 3232960};
  Aluno aluno6 = {"Maria", "teste4@gmail.com", 3232571};
  Aluno aluno7 = {"Joaquina", "teste4@gmail.com", 1100971};
  Aluno aluno8 = {"Carla", "teste4@gmail.com", 3230971};
  Aluno aluno9 = {"Thiago", "teste4@gmail.com", 1000005};
  Aluno aluno10 = {"joana", "teste4@gmail.com", 2000007};

  // Cria um vetor (propositalmente) desornedado com os alunos
  Aluno alunos[10] = {aluno1, aluno2, aluno3, aluno4, aluno5, aluno6, aluno7, aluno8, aluno9, aluno10};
  // garante que o vetor esteja ordenado
  mergeSort(alunos, 0, 9);
  // salva o tamanho do vetor numa variável
  int length = sizeof(alunos) / sizeof(alunos[0]);
  // executa função responsável por exibir as funções menu
  managerMenu(alunos, length);

  return 0;
}