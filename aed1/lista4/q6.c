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

    for(i = 0; i < n; i++){
        no = create_node(v[i]);
        
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

void print(node *head){
    node *ptr = head;

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}   
