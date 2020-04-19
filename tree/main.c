#include <stdio.h>

#include "./tree.h";

int main()
{

    // Root test = createTree(createTree(createTree(NULL,4,NULL), 2, createTree(NULL,5,NULL)),1,createTree(NULL,3,createTree(NULL,6,NULL)));

    Tree *root = createTree();
    insertNode(root, 30);
    insertNode(root, 15);
    insertNode(root, 20);
    insertNode(root, 7);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 31);
    insertNode(root, 35);
    insertNode(root, 39);

    removeNode(root, 7);
    removeNode(root, 40);

    printf("DEBUG LEFT: %d \n", (*root)->right->left->item);
    printf("DEBUG RIGHT: %d \n", (*root)->right->right->item);

    printf("\n FIM \n");

    return 0;
}