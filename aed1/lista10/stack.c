#include "q2.h"

Node* stack = NULL;

void pilha_vazia(){
    if(stack == NULL){
        printf("Pilha vazia\n");
    }else{
        printf("Pilha nao vazia\n");
    }
}

void empilhar(int data, int *tam){
    Node* no = malloc(sizeof(Node));
    no->data = data;
    no->next = NULL;

    if(stack == NULL){
        stack = no;
        return;
    }
    
    no->next = stack;
    stack = no;

    *tam = *tam + 1;
}

void desempilhar(int *tam){
    Node* temp = stack;

    if(stack == NULL){
        printf("pilha vazia\n");
    }else{
        stack = stack->next;
        free(temp);
    }

    *tam = *tam - 1;
}

void imprimir(){
    Node* temp = stack;

    printf("%d\n", temp->data);
}