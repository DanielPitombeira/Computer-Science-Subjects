#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *insere_pos(node *head, int pos){
    node *ptr = head, *no;
    int valor;

    if(head == NULL && pos < 0){
        printf("Lista vazia\n");
        return head;
    }

    printf("Valor do no: ");
    scanf("%d", &valor);
    no = malloc(sizeof(node));
    no->data = valor;
    no->next = NULL;

    --pos;
    while(--pos){
        ptr = ptr->next;
    }
    ptr->next = no;

    return head;
}

node *retira_last(node *head){
    node *ptr1 = head, *ptr2;

    ptr2 = ptr1;
    ptr1 = ptr1->next;
    while(ptr1 != NULL){
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
    free(ptr1);
    ptr1 = NULL;

    return ptr1;
}

int busca(int valor, node *head){
    node *ptr = head;
    int pos = 0;

    while(ptr->data != valor){
        pos++;
        ptr = ptr->next;
    }

    return pos;
}

node *remove(node *head){
    node *ptr1, *ptr2;

    if(head == NULL){
        printf("Lista vazia\n");
    }

    ptr1 = head;
    ptr2 = head->next;
    while(ptr1 != NULL){
        ptr1 = ptr1->next;
    }

    return head;
}