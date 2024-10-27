#include "q10.h"

node* stack;
char str[189820];

node* create_node(char ch){
    node* no;

    no = malloc(sizeof(node));
    no->letter = ch;
    no->next = NULL;

    return no;
}

void push(char string[]){
    int i = 0;

    while(string[i] != '\0'){
        node* no;

        no = create_node(string[i]);

        no->next = stack;
        stack = no;

        str[i] = string[i];
        i++;
    }

    str[i] = '\0';
}

void pop(){
    node* temp = stack;

    if(stack == NULL){
        return;
    }

    stack = stack->next;
    free(temp);
}

void palindromo(){
    int i = 0;

    while(stack != NULL){
        if(stack->letter != str[i]){
            printf("Nao e um palindromo\n");
            return;
        }

        i++;
        pop();
    }

    printf("E um palindromo\n");
}
