#ifndef LINKEDLIST // Previne que esse arquivo seja carregado duas vezes
#define LINKEDLIST

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

#endif /*LINKEDLIST*/