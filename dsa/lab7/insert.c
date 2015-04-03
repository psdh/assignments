#include "data.h"
#include <stdio.h>

void insert(bst* head, int val)
{
    bst* suc;

    while((head->right != NULL) && (head->left != NULL))
    {
        if(head->value > val) {
            suc = head;
            head = head->left;
        } else if(head->value < val) {
            suc = head;
            head = head->right;
        }
        else
        {
            printf("The value is already present and we currently are not handling duplicate entries");
        return;
        }
    }

    bst node = (bst node) malloc(sizeof(bst));
    node->value = val;
    node->left = NULL;
    node->right = NULL;
    if(head->value > val){
        node->succ = head;
        head->left = node;
    }
    else if(head->value < val){
        node->succ = head->succ;
        head->right = node;
    }
    


