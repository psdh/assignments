#include <stdio.h>
#include "data.h"
#include <stdlib.h>

bst* insert(bst* root, int k)
{
    bst* nn = (bst*) malloc(sizeof(bst));
    nn->succ = nn->right = nn->left = NULL;
    nn->value = k;

    if(root == NULL)
        return nn;

    bst* temp = root;

    while((temp->right != NULL) || (temp->left != NULL))
    {
        if(temp->value > k)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp->value > k)
    {
        temp->left = nn;
        nn->succ = temp;
    }
    else
    {
        temp->right = nn;
        nn->succ = temp->succ;
        temp->succ = nn;
    }
    return root;
}

// Write some code that will allow you to print it in a full-er way on the console itself

// As of now this just prints in order
void print(bst* temp)
{
    while(temp->left != NULL)
        temp = temp->left;

    while(temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->succ;
    }
}
