#include "q11.h"

node* front_impar = NULL;
node* rear_impar = NULL;

node* front_par = NULL;
node* rear_par = NULL;

node* stack = NULL;

node* create_node(int data){
    node* no;

    no = malloc(sizeof(node));
    no->data = data;
    no->next = NULL;

    return no;
}

void push_fila(int data, node** front, node** rear){
    node* no;

    no = create_node(data);

    if(*front == NULL && *rear == NULL){
        *front = *rear = no;
        return;
    }

    (*rear)->next = no;
    *rear = no;
}

void pop_fila(node** front, node** rear){
    node* temp;

    temp = *front;
    
    if(*front == NULL){
        return;
    }else if(*front == *rear){
        *front = *rear = NULL;
    }else{
        *front = (*front)->next;
    }

    free(temp);
}

void push_pilha(int data){
    node* no;

    no = create_node(data);

    no->next = stack;
    stack = no;
}

void pop_pilha(){
    node* temp = stack;

    if(stack == NULL){
        return;
    }
    stack = stack->next;

    free(temp);
}

void funcao(){
    
    while(front_impar != NULL || front_par != NULL){
        if(front_impar != NULL){
            if(front_impar->data > 0){
                push_pilha(front_impar->data);
            }else{
                pop_pilha();
            }
            pop_fila(&front_impar, &rear_impar);
        }
        if(front_par != NULL){
            if(front_par->data > 0){
                push_pilha(front_par->data);
            }else{
                pop_pilha();
            }
            pop_fila(&front_par, &rear_par);
        }
    }
}

void print(){
    node* temp = stack;

    while(temp != NULL){
        printf("%d\n", temp->data);

        temp = temp->next;
    }
}
