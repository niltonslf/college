#include <stdio.h>

#include "./tree.h";

int main()
{

    // Root test = createTree(createTree(createTree(NULL,4,NULL), 2, createTree(NULL,5,NULL)),1,createTree(NULL,3,createTree(NULL,6,NULL)));

    Tree *root = createTree();
    insertNode(root, 3);

    insertNode(root, 2);
    insertNode(root, 5);
    insertNode(root, 8);
    insertNode(root, 10);
    insertNode(root, 15);
    insertNode(root, 1);

    printf("debug: %d\n", (*root)->left->left->item);

    printf("\n FIM \n");

    return 0;
}