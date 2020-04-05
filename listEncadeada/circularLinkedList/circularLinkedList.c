#include <stdio.h>
// #include "cirularLinkedList.h"

typedef struct
{
  int matricula;
  char nome[30];
  float n1, n2, n3;
} aluno;

typedef struct elemento *Lista;

typedef struct
{
  aluno dados;
  elemento *prox;
} elemento;

Lista *cria_lista()
{
  Lista *li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL)
    *li = NULL;

  return li;
}

void libera_lista(Lista *li)
{
  if (li != NULL && *li != NULL)
  {
    elemento *aux;
    elemento *no = *li;

    while (*li != no->prox)
    {
      aux = no;
      no = no->prox;
      free(aux);
    }

    free(no);
    free(li);
  }
}

int tamanho_lista(Lista *li)
{
  if (li == NULL || *li == NULL)
    return 0;

  int cont = 0;
  elemento *no = *li;
  do
  {
    cont++;
    no = no->prox;
  } while (no != *li);

  return cont;
}

int lista_cheia(Lista *li)
{
  return 0;
}

int lista_vazia(Lista *li)
{

  if (li == NULL || *li == NULL)
    return 1;
  return 0;
}

int insere_lista_inicio(Lista *li, aluno al)
{

  // lista está vazia?
  if (li == NULL)
    return 0;

  elemento *no = (elemento *)malloc(sizeof(elemento));

  if (no == NULL) // não conseguiu alocar espaço na memória para o nó?
    return 0;

  no->dados = al;
  if (*li == NULL) // conteúdo de li está vazio? (primeiro item)
  {
    *li = no;
    no->prox = no;
  }
  else
  {
    elemento *aux = *li;

    while (aux->prox != *li)
      aux = aux->prox;

    aux->prox = no;
    no->prox = *li;
    *li = no;
  }
  return 1;
}

int insere_lista_final(Lista *li, aluno al)
{
  if (li == NULL)
    return 0;

  elemento *no = (elemento *)malloc(sizeof(elemento));
  if (no == NULL)
    return 0;

  no->dados = al;

  if (*li == NULL) // lista vazia: insere inicio
  {
    *li = no;
    no->prox = no;
  }
  else
  {
    elemento *aux = *li;
    while (aux->prox != *li)
      aux = aux->prox;

    aux->prox = no;
    no->prox = *li;
  }
}

int insere_lista_ordenada(Lista *li, aluno al)
{
  // TODO
}

int main()
{

  Lista *li = cria_lista();
  int tamanho = tamanho_lista(li);
  int cheia = lista_cheia(li);
  int vazia = lista_vazia(li);

  // int x = insere_lista_inicio(li, dados_aluno);

  libera_lista(li);

  return 0;
}