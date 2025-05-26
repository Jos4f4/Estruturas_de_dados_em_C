#include <stdio.h>
#include <stdlib.h>

typedef struct nodeitem {
    int info;
    struct nodeitem *next;
} node;

typedef struct {
    node *first;
} linkedlist;

linkedlist *newList();
int isListEmpty(linkedlist *l);
void addList(linkedlist *l, int value, int pos);
void showList(linkedlist *l);
int length(linkedlist *l);
int indexOf(linkedlist *l, int value);
node *getNode(linkedlist *l, int pos);
void delNodeByPosition(linkedlist *l, int pos);
void delNodeByValue(linkedlist *l, int value);

/*
- Nova lista
- Inserir (inicio, meio e fim)
- Mostrar lista
- Tamanho
- Buscar (por posição e por valor)
- Remover(por posição e por valor)
*/
int main(){
    linkedlist *l = newList();
    addList(l, 1, 1);
    addList(l, 2, 2 );
    addList(l, 3, 3);
    addList(l, 2, 3);
    delNodeByPosition(l, 2);
    printf("Tamanho: %d\n", length(l));
    showList(l);

    printf("Posicao do valor 2: %d\n", indexOf(l, 3));

    return 0;
}

int indexOf(linkedlist *l, int value){
    int pos=1;
    node *n=l->first;
    while(n!=NULL){
        if(n->info==value){
            return pos;
        }
        pos++;
        n=n->next;
    }
    return -1;
};

node *getNode(linkedlist *l, int pos){
    node *n;
    if(pos<0 || pos>length(l)){
        return NULL;
    }
    n = l ->first;
    while(pos>1){
        n = n -> next;
        pos--;
    }
    return n;
};

void delNodeByPosition(linkedlist *l, int pos){
    node *ant, *n;
    ant = getNode(l, pos-1);
    if(ant == NULL){
        return;
    }
    n = ant -> next;
    if(n != NULL){
        ant -> next = n-> next;
        free(n);
    }
};

void delNodeByValue(linkedlist *l, int value){

};

linkedlist *newList(){
    linkedlist *l = (linkedlist *)malloc(sizeof(linkedlist));
    l->first = NULL;
}

int isListEmpty(linkedlist *l){
    return l->first == NULL;
}

node *newNode(int value){
    node *n = (node *)malloc(sizeof(node));
    n->info = value;
    n->next = NULL;
    return n;
}

void addList(linkedlist *l, int value, int pos){
    int i;
    node *n, *ant;
    if(pos<1||pos>length(l)+1){
        return;
    }
    n = newNode(value);
    if(pos == 1){
        //Inserir no inicio
        n->next = l->first;
        l->first = n;
    } else {
        //Inserir no meio ou final
        ant = getNode(l, pos-1);
        n->next = ant->next;
        ant->next = n;
    }
}

void showList(linkedlist *l){
    node *n;
    n = l->first;

    if(isListEmpty(l)){
        printf("Lista vazia!");
    } else {
        printf("Lista: \n");
    }
    while(n!=NULL){
        printf("%d, ", n->info);
        n = n->next;
    }
    printf("\n");
}

int length(linkedlist *l){
    int size = 0;
    node *n;
    n = l->first;
    while(n!=NULL){
        size++;
        n = n->next;
    }
    return size;
}
