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

/**
 *  Cria uma nova lista vazia 
 **/
List *createList()
{
  // Aloca espaço em memória para um novo nó
  List *list = (List *)malloc(sizeof(List));
  if (list != NULL)
    *list = NULL;

  return list;
}

/**
 * Limpa todos os items da lista fornecida 
 **/
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

/**
 * Verifica se uma lista está cheia
*/
int isFullList(List *list)
{
  return 0; // nunca retorna 1, pois a quantidade de itens é igual a quantidade de memória disponível na máquina do usuário
}

/**
 * Verfica se list está vazia, retornando 1 para sim e  para não 
*/
int isEmptyList(List *list)
{
  if (list == NULL || *list == NULL)
    return 1;
  return 0;
}

/**
 * Insere um novo item no início da lista
*/
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
    while (aux->next != *list) // percorre a lista até o último item
      aux = aux->next;

    // define os apontamentos de cada nó
    aux->next = node;
    node->prev = aux;
    node->next = *list;

    node->next->prev = node;

    *list = node;
  }
  return 1;
}

/**
 * Insere um novo item ao final da lista
*/
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
    while (aux->next != *list) // percorre a lista até o último item
      aux = aux->next;

    // define os apontamentos de cada nó
    aux->next = node;
    node->prev = aux;
    node->next = *list;
    node->next->prev = node;
  }
  return 1;
}

#endif /*LINKEDLIST*/