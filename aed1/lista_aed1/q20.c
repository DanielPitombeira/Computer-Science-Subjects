#include "q20.h"

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

void copia(){
    int *v = NULL, i = 0;

    while(stack1 != NULL){
        i++;
        int *temp = realloc(v, i * sizeof(int));

        v = temp;
        v[i-1] = stack1->data;

        pop();
    }

    for(int j = i-1; j >= 0; j--){
        push(v[j], &stack2);
    }
}

void print(){
    node* temp = stack2;
    while(temp != NULL){
        printf("%d\n", temp->data);

        temp = temp->next;
    }
}
