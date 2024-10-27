#include "q7.h"

node* stack;

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

void top(){
    node* temp = stack;

    if(stack == NULL){
        printf("\nPilha vazia\n");
        return;
    }
    printf("\n%d\n", stack->data);
    stack = stack->next;

    free(temp);
}
