#include "q8.h"

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

void operacao(){;
    int maior, menor;
    double sum, num;

    maior = menor = stack->data;
    num = sum = 0;

    while(stack != NULL){
        if(stack->data > maior)
            maior = stack->data;
        if(stack->data < menor)
            menor = stack->data;

        num++;
        sum += stack->data;

        pop();
    }

    printf("maior elemento: %d\n", maior);
    printf("menor elemento: %d\n", menor);
    printf("media: %.2lf\n", (sum/num));
}
