#include "q2.h"

node* head = NULL;

int isEmpty(){
    if(head == NULL)
        return 1;
    else
        return 0;
}

node* create_node(int data){
    node* no;

    no = malloc(sizeof(node));
    no->data = data;
    no->prev = NULL;
    no->next = NULL;

    return no;
}

void pushAtBegg(int data){
    node* no;

    no = create_node(data);

    if(isEmpty()){
        head = no;
        return;
    }

    no->next = head;
    head->prev = no;
    head = no;
}

void pushAtEnd(int data){
    node* no;

    no = create_node(data);

    if(isEmpty()){
        head = no;
        return;
    }

    node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = no;
    no->prev = temp;
}

void popAtBegg(){
    if(isEmpty()){
        printf("Lista vazia\n");
        return;
    }
    if(head->next == NULL){
        head = NULL;
        return;
    }
    node* temp = head;

    head = head->next;
    free(temp);
    head->prev = NULL;
}

void popAtEnd(){
    if(isEmpty()){
        printf("Lista vazia\n");
        return;
    }
    if(head->next == NULL){
        head = NULL;
        return;
    }
    node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    node* temp2;

    temp2 = temp->prev;
    temp2->next = NULL;

    free(temp);
}

void printAtBegg(){
    node* temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);

        temp = temp->next;
    }
    printf("\n");
}

void printAtEnd(){
    node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    while(temp != NULL){
        printf("%d ", temp->data);

        temp = temp->prev;
    }
    printf("\n");
}