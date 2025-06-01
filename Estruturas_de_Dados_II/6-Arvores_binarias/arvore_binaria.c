#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype{
    int info;
    struct nodetype *father;
    struct nodetype *left;
    struct nodetype *right;
} node;

node *makeTree(int val);
int info(node *n);
node *left(node *n);
node *right(node *n);
node *father(node *n);
node *brother(node *n);
int isLeft(node *n);
int isRight(node *n);

node *addLeft(node *tree, int val);
node *setNodeLeft(node *tree, node *n);
node *addRight(node *tree, int val);
node *setNodeRight(node *tree, node *n);
void freeTree(node *n);

void preOrdem(node *n);
void emOrdem(node *n);
void posOrdem(node *n);

int main(){
    node *tree;

    tree = makeTree(14);
    addLeft(addLeft(tree, 4), 3);
    addRight(left(tree), 10);
    addLeft(addRight(tree, 22), 18);
    addRight(right(tree), 25);

    printf("\nPre-ordem: ");
    preOrdem(tree);
    printf("\nEm-ordem: ");
    emOrdem(tree);
    printf("\nPos-ordem: ");
    posOrdem(tree);
    printf("\n");

    return 0;
}

void preOrdem(node *n){
    if(n != NULL){
        printf("[%d]", info(n));
        preOrdem(left(n));
        preOrdem(right(n));
    }
};

void emOrdem(node *n){
    if(n != NULL){
        emOrdem(left(n));
        printf("[%d]", info(n));
        emOrdem(right(n));
    }
};

void posOrdem(node *n){
    if(n != NULL){
        posOrdem(left(n));
        posOrdem(right(n));
        printf("[%d]", info(n));
    }
};

node *addLeft(node *tree, int val){
    return setNodeLeft(tree, makeTree(val));
};

node *setNodeLeft(node *tree, node *n){
    tree->left=n;
    n->father=tree;
    return n;
};

node *addRight(node *tree, int val){
    return setNodeRight(tree, makeTree(val));
};

node *setNodeRight(node *tree, node *n){
    tree->right=n;
    n->father=tree;
    return n;
};

void freeTree(node *n){
    node *parent;
    if(n != NULL){
        parent = father(n);
        if(parent != NULL){
            if(isLeft(n)){
                parent->left=NULL;
            }else{
                parent->right=NULL;
            }
        }

        freeTree(left(n));
        freeTree(right(n));
        free(n);
    }
};

int info(node *n){
    return n->info;
};

node *left(node *n){
    return n->left;
};

node *right(node *n){
    return n->right;
};

node *father(node *n){
    return n->father;
};

int isLeft(node *n){
    if(father(n) == NULL) return 0;
    if(n == left(father(n))){
        return 1;
    }else{
        return 0;
    }
};

int isRight(node *n){
    if(father(n) == NULL) return 0;
    return n == right(father(n));
};

node *brother(node *n){
    if(father(n) == NULL) return NULL;
    if(isLeft(n)) return right(father(n));
    else return left(father(n));
};


node *makeTree(int val){
    node *n = (node *)malloc(sizeof(node));
    n->info=val;
    n->father=NULL;
    n->left=NULL;
    n->right=NULL;
    return n;
}
