struct bst;
typedef struct bst bst;

struct bst
{
   struct  bst* left;
   struct  bst* right;
   int value;
   struct bst* succ;
};


bst* insert(bst*, int);
