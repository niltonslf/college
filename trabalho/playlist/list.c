#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char nome[50];
  char artista[50];
  float duracao;
} Song;

typedef struct Node
{
  Song item;
  struct Node *next;
} * List;

List createNode(Song element, List next)
{
  // Aloca espaço em memória para um novo nó
  List item = malloc(sizeof(struct Node));
  item->item = element; // adiciona em item o elemento recebido via argumento
  item->next = next;    // Define o próximo nó
  return item;          // retorna item criado
}

void showList(List list)
{
  if (list == NULL)
    return;

  while (list != NULL)
  {
    printSong(list);
    list = list->next;
  }
}

void destroy(List *list)
{
  while (*list != NULL)
  {
    List item = *list;
    *list = item->next;
    free(item);

    printf("Song %s removed", item->item.nome);
  }
}

/**
 *  Recebe uma struct Song e realiza a impressão das informações 
 *  dessa estruura. 
 **/
void printSong(Song *song)
{
  printf("Name: %s \n", song->nome);
  printf("Author: %s \n", song->artista);
  printf("Duration: %f minutes \n", song->duracao);

  printf("\n");
}

int main()
{
  Song musicTest = {"room 409", "Bullet for my valentine", 3};
  Song musicTest2 = {"XO", "EDEN", 4.5};
  Song musicTest3 = {"JOLT", "Unlike pluto", 2};

  List playlist = createNode(musicTest, createNode(musicTest2, createNode(musicTest3, NULL)));

  List currentSong = NULL;
  int option = -1;

  while (option != 0)
  {
    printf("\n--------- MENU ---------\n");
    printf("1- Ver playlist\n");
    printf("2- Tocar playlist\n");

    if (currentSong != NULL)
    {
      printf("3- Ver música tocando\n");
      printf("4- Próxima música\n");
      printf("5- Voltar música\n");
    }
    printf("0- Fechar player\n");

    // RECEBE OPÇÃO DESEJADA PELO USUÁRIO
    printf("\nDigite o código da opção desejada: ");
    scanf("%d", &option);

    system("clear");

    /**
   *  TRATANTO OPÇÕES DO MEN
   **/
    switch (option)
    {
    case 1:
      printf("\n--------- SUA PLAYLIST ---------\n");
      showList(playlist);
      printf("---------------------------------\n");
      break;

    case 2:
      printf("\n---------INICIANDO MÚSICA ---------\n");
      currentSong = playlist;
      break;

    case 3:
      printf("\n--------- MÚSICA EM ANDAMENTO ---------\n");
      printSong(&currentSong->item);
      printf("---------------------------------\n");
      break;
    case 4:
      printf("\n--------- MÚSICA AVANÇADA ---------\n");
      if (currentSong->next == NULL || currentSong == NULL)
        printf('ÚLTIMO ITEM DA LISTA');
      else
        currentSong = currentSong->next;

      break;

    default:
      break;
    }
  }

  return 0;
}
