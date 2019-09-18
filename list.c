#include "list.h"
#include <stdio.h>

struct node {
    elem info;
    struct node *next;
};

struct list {
    Node *begin, *end;
};

void create (List **l) {
    *l = malloc(sizeof(List));
    (*l)->begin = NULL;
    (*l)->end = NULL;
    return;
}

void insert (List *l, elem x) {
    Node *aux;
    aux = malloc(sizeof(Node));
    aux->info = x;
    aux->next = NULL;
    if (l->end != NULL)
        l->end->next = aux;
    l->end = aux;
    if (l->begin == NULL)
        l->begin = aux;
    return;
}

int remove (List *l, int _id) {
    Node *actual, *prev;
    actual = l->begin;
    ant = NULL;
    while (actual != NULL) {
        if (actual->info->_id == _id) { 
            if (ant == NULL)
                l->begin = actual->next; 
            else
                ant->prox = actual->next; 
            if (actual == l->end)
                l->end = ant; 
            free(actual); 
            return 1; 
        }
        ant = actual;
        actual = actual->next;
    }
    return 0; 
}