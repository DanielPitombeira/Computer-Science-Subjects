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

    for(i = 0; i < n; i++){
        printf("Digite um numero inteiro: ");
        scanf("%d", &valor);
        node *no = create_node(valor);

        if(head == NULL){
            head = no;
        }else{
            ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = no;
            ptr = ptr->next;
        }
    }

    return head;
}

node *concatena(node *head1, node *head2){
    node *ptr;
    ptr = head1;

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = head2;

    return head1;
}

void print(node *head){
    node *ptr = head;

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
