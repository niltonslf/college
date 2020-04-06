#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[50];
  char email[50];
  int ru;
} Aluno;

void showSingleStudent(Aluno aluno);

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

      int alunoIndex = binarySearch(alunos, 0, length, ru);
      showSingleStudent(alunos[alunoIndex]);

      break;
    }
  }
}

int main()
{

  Aluno aluno1 = {"Nilton Lopes", "niltonrck@gmail.com", 3232971};
  Aluno aluno2 = {"James brown", "teste1@gmail.com", 3232972};
  Aluno aluno3 = {"Charlie nunes", "teste2@gmail.com", 3232973};
  Aluno aluno4 = {"Tim berners-lee", "teste3@gmail.com", 3232974};
  Aluno aluno5 = {"Ana story", "teste4@gmail.com", 3232975};

  Aluno alunos[5] = {aluno1, aluno2, aluno3, aluno4, aluno5};
  int length = sizeof(alunos) / sizeof(alunos[0]);

  managerMenu(alunos, length);

  return 0;
}