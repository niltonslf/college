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

// Tree createTree(Tree leftTree, Item item, Tree rightTree) {
//     Tree node =  malloc(sizeof(Tree));
//     node->left = leftTree;
//     node->right = rightTree;
//     node->item = item;

//     return node;
// }

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