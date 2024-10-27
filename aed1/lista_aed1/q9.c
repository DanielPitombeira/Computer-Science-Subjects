#include "q9.h"

node* stack1 = NULL;
node* stack2 = NULL;

node* create_node(int data){
    node* no;

    no = malloc(sizeof(node));
    no->data = data;
    no->next = NULL;

    return no;
}

void push(int data, node** stack){
    node* no;

    no = create_node(data);

    no->next = *stack;
    *stack = no;
}

void pop(){
    node* temp = stack1;

    if(stack1 == NULL){
        return;
    }

    stack1 = stack1->next;
    free(temp);
}

void inverter(){
    while(stack1 != NULL){
        push(stack1->data, &stack2);
        
        pop();
    }
}

void print(){
    node* temp = stack2;
    while(temp != NULL){
        printf("%d\n", temp->data);
        
        temp = temp->next;
    }
}

