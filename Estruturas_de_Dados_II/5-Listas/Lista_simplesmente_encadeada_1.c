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
    addList(l, 3, 1);
    printf("Tamanho: %d\n", length(l));
    showList(l);

    return 0;
}

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
        ant = l -> first;
        for(i=1; i<pos-1; i++ ){
            ant = ant->next;
        }
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
};
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
