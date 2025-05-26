#include <stdio.h>
#include <stdlib.h>

typedef struct nodeitem {
    int info;
    struct nodeitem *next;
    struct nodeitem *prev;
} node;

typedef struct {
    node *head;
    node *tail;
} dlinkedlist;

dlinkedlist *newList();
void addNode(dlinkedlist *l, int value, int pos);
node *getNode(dlinkedlist *l, int pos);
int isListEmpty(dlinkedlist *l);
void showList(dlinkedlist *l, int inv);
int length(dlinkedlist *l);
int indexOf(dlinkedlist *l, int value);
void delNodeByPosition(dlinkedlist *l, int pos);
void delNodesByValue(dlinkedlist *l, int value);

int main(){
    dlinkedlist *l = newList();
    addNode(l, 1, 1);
    addNode(l, 2, 2);
    addNode(l, 3, 3);
    addNode(l, 10, 2);
    delNodesByValue(l, 3);
    showList(l, 1);
    showList(l, 0);

    return 0;
}

dlinkedlist *newList(){
    dlinkedlist *l = (dlinkedlist *)malloc(sizeof(dlinkedlist));
    l->head = NULL;
    l->tail = NULL;
    return l;
}

int isListEmpty(dlinkedlist *l){
    return l->head == NULL;
}

int length(dlinkedlist *l){
    int size = 0;
    node *n = l->head;
    while(n != NULL){
        size++;
        n = n->next;
    }
    return size;
}

node *getNode(dlinkedlist *l, int pos){
    node *n = l->head;
    while(pos > 1){
        n = n -> next;
        pos--;
    }
    return n;
}

node *newNode(int value){
    node *n = (node *)malloc(sizeof(node));
    n->info = value;
    n->next = NULL;
    n->prev = NULL;
}

void addNode(dlinkedlist *l, int value, int pos){
    node *n, *ant, *prox;
    if(pos<0 || pos>length(l)+1){
        return;
    }
    n = newNode(value);
    if(isListEmpty(l)){
        l->head=n;
        l->tail=n;
    }else if(pos==1){
        //Inserir no inicio
        n->next = l->head;
        l->head->prev=n;
        l->head=n;
    }else if(pos==length(l)+1){
        //Inserir no final
        n->prev=l->tail;
        l->tail->next=n;
        l->tail=n;
    }else{
        //Inserir no final
        ant = getNode(l, pos-1);
        prox=ant->next;

        n ->prev=ant;
        n->next=prox;
        prox->prev=n;
        ant->next=n;
    }
}

int indexOf(dlinkedlist *l, int value){
    int pos = 1;
    node *n = l -> head;
    while(n!=NULL){
        if(n->info==value){
            return pos;
        }
        pos++;
        n=n->next;
    }
    return -1;
};

void delNodeByPosition(dlinkedlist *l, int pos){
    node *n, *ant, *prox;

    if(pos==1){
        //Excluir no inicio
        n = l-> head;
        l->head= n->next;
        if(l->head != NULL){
            l->head->prev=NULL;
        }else{
            l->tail=NULL;
        }
    } else if (pos == length(l)){
        //Excluir no final
        n = l->tail;
        l->tail=n->prev;
        l->tail->next=NULL;
    }else{
        ant = getNode(l, pos-1);
        if(ant==NULL){
            return;
        }
        n = ant->next;
        if(n==NULL){
            return;
        }
        prox = n->next;
        ant->next=prox;
        if(prox!=NULL){
            prox->prev=ant;
        }
        free(n);
    }
}

void delNodesByValue(dlinkedlist *l, int value){
    int pos = indexOf(l, value);
    while(pos>0){
        delNodeByPosition(l, pos);
        pos = indexOf(l, value);
    }
}

void showList(dlinkedlist *l, int inv){
    node *n;
    printf("Lista: ");
    if(inv != 1){
        n = l->head;
        while(n!=NULL){
            printf("%d, ", n->info);
            n = n->next;
        }
    }else{
        n = l->tail;
        while(n!=NULL){
            printf("%d, ", n->info);
            n = n->prev;
        }
    }
}
