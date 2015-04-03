struct bst;

typedef struct 
{
    bst* left;
    int value;
    bst* right;
    bst* succ;
}bst;

void insert(int val);

