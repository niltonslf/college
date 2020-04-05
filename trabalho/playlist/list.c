#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  struct Node *prev;
} Node, *List;

List *createList()
{
  // Aloca espaço em memória para um novo nó
  List *list = (List *)malloc(sizeof(List));
  if (list != NULL)
    *list = NULL;

  return list;
}

void freeList(List *list)
{
  if (list != NULL && *list != NULL)
  {
    Node *aux;
    Node *node = *list;
    while (*list != node->next)
    {
      aux = node;
      node = node->next;
      free(aux);
    }
    free(node);
    free(list);
  }
}

int isFullList(List *list)
{
  return 0;
}

int isEmptyList(List *list)
{
  if (list == NULL || *list == NULL)
    return 1;
  return 0;
}

int insertListBegin(List *list, Song song)
{
  // lista está vazia?
  if (list == NULL)
    return 0;

  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) // conseguiu fazer a alocação de memória para este nó?
    return 0;

  node->item = song;

  if (*list == NULL) // O conteúdo de lista está vazia? (primeiro item)
  {
    *list = node;
    node->next = node;
    node->prev = node;
  }
  else
  {
    Node *aux = *list;
    while (aux->next != *list)
      aux = aux->next;

    aux->next = node;
    node->prev = aux;
    node->next = *list;

    node->next->prev = node;

    *list = node;
  }
  return 1;
}

int insertListEnd(List *list, Song song)
{
  if (list == NULL)
    return 0;

  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL)
    return 0;

  node->item = song;
  if (*list == NULL) // o conteúdo de list está vazio?/ é o primeiro item?
  {
    *list = node;
    node->next = node;
    node->prev = node;
  }
  else
  {
    Node *aux = *list;
    while (aux->next != *list)
      aux = aux->next;

    aux->next = node;
    node->prev = aux;
    node->next = *list;
    node->next->prev = node;
  }
  return 1;
}

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

int main()
{

  FILE *file;
  char fileData[100];

  List *playlist = createList();

  // Abre arquivo no modo leitura
  file = fopen("./playlist.txt", "r");
  if (file == NULL)
  {
    printf("Erro ao abrir arquivo");
    return -1;
  }

  // run into all songs
  while (fgets(fileData, 100, file) != NULL)
  {
    // split song line in parts
    char *song = strtok(fileData, "|");

    int i = 0;
    Song newSong;

    while (song != NULL)
    {
      // Save currente song parts
      switch (i)
      {
      case 0:
        strncpy(newSong.nome, song, 50);
        i++;
        break;
      case 1:
        strncpy(newSong.artista, song, 50);
        i++;
        break;
      case 2:
        newSong.duracao = strtof(song, NULL);
        i++;
        break;
      }
      song = strtok(NULL, "|");
    }
    insertListBegin(playlist, newSong);
  }
  fclose(file);

  int option = -1;
  while (option != 0)
  {
    printf("\n--------- MENU ---------\n");
    printf("1- Ver playlist\n");
    printf("2- Tocar playlist\n");

    if (playlist != NULL)
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

  return 0;
}
