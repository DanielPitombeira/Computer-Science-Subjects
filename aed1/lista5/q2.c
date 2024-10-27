#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

node *create_node(int valor){
    node *ptr;

    ptr = malloc(sizeof(node));
    ptr->data = valor;
    ptr->next = NULL;

    return ptr;
}

node *create_list(node *head, int n){
    node *ptr;
    int valor;

    node *head_node = create_node(0);
    head = head_node;
    ptr = head;

    while(n--){
        printf("valor do no: ");
        scanf("%d", &valor);
        ptr->next = create_node(valor);
        ptr = ptr->next;
    }
    
    return head;
}

node *ordena(node *head1, node *head2){
    
}

void print(node *head){
    node *ptr = head->next;

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}