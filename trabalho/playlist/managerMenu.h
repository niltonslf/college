#include <stdio.h>
#include "linkedList.h"

/**
 *  Percorre por todos os elementos da lista, exibindo cada
 * um separadamente
 **/
void showList(List *list)
{
  if (list == NULL || *list == NULL)
    return;

  Node *aux = *list;
  do
  {
    printSong(aux->item);
    aux = aux->next;
  } while (aux != *list);
}

/**
 *  Recebe uma struct Song e realiza a impressão das informações 
 *  dessa estruura. 
 **/
void printSong(Song song)
{
  printf("Name: %s \n", song.nome);
  printf("Author: %s \n", song.artista);
  printf("Duration: %f minutes \n", song.duracao);

  printf("\n");
}

void managerMenu(List *playlist)
{
  int option = -1;
  while (option != 0) // LOOP INFINITO COM O MENU
  {
    printf("\n--------- MENU ---------\n");
    printf("1- Ver playlist\n");
    printf("2- Tocar playlist\n");
    printf("3- Ver música tocando\n");
    printf("4- Próxima música\n");
    printf("5- Voltar música\n");
    printf("0- Fechar player\n");

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
      printf("\n--------- SUA PLAYLIST ---------\n");
      showList(playlist);
      printf("---------------------------------\n");
      break;

    case 2:
      printf("\n---------TOCANDO ---------\n");
      printSong((*playlist)->item);
      break;

    case 3:
      printf("\n--------- MÚSICA EM ANDAMENTO ---------\n");
      printSong((*playlist)->item);
      printf("---------------------------------\n");
      break;

    case 4:
      printf("\n--------- MÚSICA AVANÇADA ---------\n");
      *playlist = (*playlist)->next;
      printf("\n---------TOCANDO ---------\n");
      printSong((*playlist)->item);
      break;

    case 5:
      printf("\n--------- MÚSICA VOLTADA ---------\n");
      *playlist = (*playlist)->prev;
      printf("\n---------TOCANDO ---------\n");
      printSong((*playlist)->item);
      break;

    default:
      break;
    }
  }
}