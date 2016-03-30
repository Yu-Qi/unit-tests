#ifndef _MERGE_H
#define MERGE_H

typedef struct List_node {
    int val;
    struct List_node *next;
} List_node;
typedef struct List_node List;

List* combine(List **head, List *list_left, List *list_right);
void mergesort(List **head);
void divide_two_node(List **head, List **left, List **right) ;		


#endif