#include <stdio.h>
#include <stdlib.h>
#include "q7.h"

node *create_node(int valor){
    node *no;

    no = malloc(sizeof(node));
    no->data = valor;
    no->next = NULL;

    return no;
}

node *create_list(node *head, int n){
    int i, valor;
    node *ptr; 

    node *head_node = create_node(0);
    head = head_node;
    ptr = head;

    for(i = 0; i < n; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &valor);
        node *no = create_node(valor);

        ptr->next = no;
        ptr = no;
    }

    return head;
}

node *concatena(node *head1, node *head2){
    node *ptr;
    ptr = head1;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = head2->next;
    free(head2);

    return head1;
}

void print(node *head){
    node *ptr = head->next;

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}