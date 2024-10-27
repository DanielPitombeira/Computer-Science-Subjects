#include <stdio.h>
#include <stdlib.h>
#include "q6.h"

node *create_node(int v){
    node *no = malloc(sizeof(node));
    no->data = v;
    no->next = NULL;

    return no;
}

node *cria_lista(node *head, int *v, int n){
    node *no, *ptr;
    int i;

    node *head_node = create_node(0);
    head = head_node;
    ptr = head;

    for(i = 0; i < n; i++){
        no = create_node(v[i]);
        ptr->next = no;
        ptr = no;
    }

    return head;
}

void print(node *head){
    node *ptr = head->next;

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}   
