#include <stdio.h>
#include <stdlib.h>

#define fmt "%d " // formato de exibição dos itens

typedef int Item;

typedef struct tree
{
  Item item;
  struct tree *left;
  struct tree *right;
} * Tree;

Tree *createTree()
{
  Tree *node = (Tree *)malloc(sizeof(Tree));
  if (node != NULL)
    *node = NULL; // malloc funcionou
  return node;
}

int insertNode(Tree *node, Item item)
{

  if (node == NULL)
    return 0; // arvore não existe

  Tree newNode = malloc(sizeof(Tree));
  if (newNode == NULL)
    return 0; // não conseguiu alocar newNode na memória :/

  if (*node == NULL)
  { // árvore está vazia?

    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    *node = newNode;

    return 1;
  }

  if (item < (*node)->item)
  { // inserir à esquerda
    printf("\nelemento: %d é menor que %d. inserindo à esquerda.\n", item, (*node)->item);
    insertNode(&(*node)->left, item);
  }

  else
  { // inserir à direita
    printf("\nelemento: %d é maior que %d. inserindo à direita.\n", item, (*node)->item);
    insertNode(&(*node)->right, item);
  }
}

int removeNode(Tree *node, Item item)
{
  if (node == NULL)
    return 0; // arvore não existe

  if (*node == NULL) // àrvore está vaziaw
    return 0;

  // achou o elemento a ser removido?
  if (item == (*node)->item)
  {
    printf("\nRemoção - elemento: %d encontrado.\n", item);

    // -- é um nó folha?
    if ((*node)->left == NULL && (*node)->right == NULL)
    {
      printf("\nRemoção - elemento: %d é um nó folha.\n", item);
      *node = NULL;
      return 1;
    }
    else if ((*node)->left != NULL && (*node)->right == NULL)
    { // HÁ ELEMENTOS SOMENTE À ESQUERDA
      printf("\nRemoção - elemento: %d é um possui 1 filho à esquerda.\n", item);

      *node = (*node)->left;
      return 1;
    }
    else if ((*node)->left == NULL && (*node)->right != NULL)
    { // HÁ ELEMENTOS SOMENTE À DIREITA
      printf("\nRemoção - elemento: %d é um possui 1 filho à direita.\n", item);

      *node = (*node)->right;
      return 1;
    }
    else
    {
      printf("\nRemoção - elemento: %d é um possui 2 filhos.\n", item);

      Tree aux = (*node)->left; // pega o filho à esquerda
      Tree auxPrev = (*node)->left;

      while (aux->right != NULL) // pegar o ultimo elemento mais a direita
      {
        auxPrev = aux;
        aux = aux->right;
      }

      auxPrev->right = NULL;       // remove apontamento do elemento anterior ao último elemento (aux)
      aux->right = (*node)->right; // aux->right aponta para o filho a direita do elemento que será removido
      aux->left = (*node)->left;   // aponta para o filho à esquerda do elemento que será removido
      *node = aux;                 // remove elemento trocando o apontamento para o novo elemento
      return 1;
    }

    // -- árvore com único nó
  }

  if (item < (*node)->item)
  { // ESQUERDA
    removeNode(&(*node)->left, item);
  }
  else
  { // DIREITA
    removeNode(&(*node)->right, item);
  }
}