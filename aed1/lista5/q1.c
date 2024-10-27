#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

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

node *del(node *head, int maior){
    node *ptr = head->next, *ptraux = head;

    while(ptr->data != maior){
        ptraux = ptr;
        ptr = ptr->next;
    }
    ptraux->next = ptr->next;
    free(ptr);

    return head;
}

node *lista_ordenada(node *head1, node *head2){
    node *ptr1 = head1->next;
    node *ptr2 = head2;
    int maior;

    while(ptr1 != NULL){
        maior = ptr1->data;
        if(ptr1 == NULL){
            maior = ptr1->data;
            head1->next = NULL;
            free(ptr1);
        }else{
            while(ptr1 != NULL){
                ptr1 = ptr1->next;
                if(ptr1->data > maior) maior = ptr1->data; 
            }
        }
        head1 = del(head1, maior);
        ptr1 = head1->next;
        
        ptr2->next = create_node(maior);
        ptr2 = ptr2->next;
    }

    return head2;
}

void print(node *head){
    node *ptr = head->next;

    while(ptr != NULL){
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}