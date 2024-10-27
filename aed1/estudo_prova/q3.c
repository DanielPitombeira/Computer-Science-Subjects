#include "q3.h"

node* stack = NULL;

node* create_node(int data){
    node* no;

    no = malloc(sizeof(node));
    no->data = data;
    no->next = NULL;

    return no;
}

void push(int data){
    node* no;

    no = create_node(data);

    no->next = stack;
    stack = no;
}

void pop(){
    node* temp = stack;

    if(stack == NULL){
        return;
    }

    stack = stack->next;
    free(temp);
}

void print(){
    node* temp = stack;

    while(temp != NULL){
        printf("%d\n", temp->data);

        temp = temp->next;
    }
}