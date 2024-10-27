//implementacao dinamica
#include "q15.h"

node* front = NULL;
node* rear = NULL;

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

    if(front == NULL && rear == NULL){
        front = rear = no;
        return;
    }

    rear->next = no;
    rear = no;
}

void pop(){
    node* temp = front;

    if(front == NULL){
        return;
    }else if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }

    free(temp);
}

void push_stack(int data){
    node* no;

    no = create_node(data);
    
    no->next = stack;
    stack = no;
}

void inverta(){
    while(front != NULL){
        push_stack(front->data);

        pop();
    }
}

void print(){
    node* temp = stack;
    while(temp != NULL){
        printf("%d\n", temp->data);

        temp = temp->next;
    }
}
