#include "q3.h"

Node* stack = NULL;

void push(Produto produto){
    Node* no;

    no = malloc(sizeof(Node));
    no->produto = produto;
    no->next = NULL;

    if(stack == NULL){
        stack = no;
        return;
    }

    no->next = stack;
    stack = no;
}

Produto pop(){
    Node* temp = stack;
    Produto produto;

    if(stack == NULL){
        printf("Estoque vazio\n");
        exit(0);
    }else{
        produto = stack->produto;
        stack = stack->next;
        free(temp);
    }

    return produto;
}

int isEmpty(){
    Node* temp = stack;

    if(stack == NULL){
        return 1;
    }else{
        return 0;
    }
}

void top(){
    if(stack == NULL){
        printf("Estoque vazio\n");
    }else{
        printf("Codigo: %d\n", stack->produto.codigo);
        printf("Nome: %s\n", stack->produto.nome);
        printf("Quantidade: %d\n", stack->produto.quantidade);
    }
}