#include "operations.c"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    bst* root = (bst*) malloc(sizeof(bst));
    root->right = root->left = root->succ = NULL;
    root->value = 3;

    root = insert(root, 1);
    root = insert(root, 2);
    
    print(root);
}
