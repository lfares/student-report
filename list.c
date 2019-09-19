#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
    elem info;
    struct node *next;
};

struct list {
    Node *begin, *end;
};

void create_list (List **l) {
    *l = malloc(sizeof(List));
    (*l)->begin = NULL;
    (*l)->end = NULL;
    return;
}

void insert_elem (List *l, elem x) {
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

int remove_elem (List *l, int _id) {
    Node *aux, *previous_aux;
    aux = l->begin;
    previous_aux = NULL;
    while (aux != NULL) {
        if (aux->info._id == _id) { 
            if (previous_aux == NULL)
                l->begin = aux->next; 
            else
                previous_aux->next = aux->next; 
            if (aux == l->end)
                l->end = previous_aux; 
            free(aux); 
            return SUCCESS; 
        }
        previous_aux = aux;
        aux = aux->next;
    }
    return ERROR_EMPTY; 
}

int print(List *l){
    if (l->begin == NULL)
        return ERROR_EMPTY;
    Node *aux = l->begin;
    while (aux != NULL) {
        printf("ID: %d.\n", aux->info._id);
        printf("Horas de estudo: %.2f.\n", aux->info.study_hours);
        printf("Nota da prova 1: %.2f.\n", aux->info.grade1);
        printf("Nota da prova 2: %.2f.\n\n", aux->info.grade2);
        aux = aux->next;
    }
    return SUCCESS;
}

int report(List *l){
    if (l->begin == NULL)
        return ERROR_EMPTY;
    Node *aux = l->begin;
    float final_score;
    while (aux != NULL) {
        printf("ID: %d.\n", aux->info._id);
        final_score = (aux->info.grade1 + aux->info.grade2)/2;
        if (final_score > 5.0)
            printf("Aluno aprovado.\n\n");
        else
            printf("Aluno reprovado.\n\n");
        aux = aux->next;
    }
    return SUCCESS;
}

int average_study (List *l){
    if (l->begin == NULL)
        return ERROR_EMPTY;
    Node *aux = l->begin;
    float total_average;
    int count = 0;
    while (aux != NULL) {
        total_average += aux->info.study_hours;
        count++;
        aux = aux->next;
    }
    total_average = total_average/count;
    printf("Média de horas de estudo da classe: %.2f.\n", total_average);

    return SUCCESS;
}

void destroy(List **l){
    Node *aux;
    while ((*l)->begin != NULL) {
        aux = (*l)->begin;
        (*l)->begin = (*l)->begin->next;
        free(aux);
    }
    free(*l);
    *l = NULL;
    return;
}