#include "q16.h"

node* front1 = NULL;
node* rear1 = NULL;

node* front2 = NULL;
node* rear2 = NULL;

node* create_node(int data){
    node* no;

    no = malloc(sizeof(node));
    no->data = data;
    no->next = NULL;

    return no;
}

void push(int data,  node** front, node** rear){
    node* no;

    no = create_node(data);

    if(*front == NULL && *rear == NULL){
        *front = *rear = no;
        return;
    }

    (*rear)->next = no;
    *rear = no;
}

void pop(){
    node* temp = front1;
    if(front1 == NULL){
        return;
    }else if(front1 == rear1){
        front1 = rear1 = NULL;
    }else{
        front1 = front1->next;
    }
    free(temp);
}

void apaga(){
    while(front1 != NULL){
        if(front1->data >= 0){
            push(front1->data, &front2, &rear2);
        }

        pop();
    }
}

void print(){
    node* temp = front2;
    while(temp != NULL){
        printf("%d\n", temp->data);

        temp = temp->next; 
    }
}
