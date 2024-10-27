#include "q1.h"

Node* front = NULL;
Node* rear = NULL;

void fila_vazia(){
    if(front == NULL){
        printf("Lista vazia\n");
    }else{
        printf("Lista nao vazia\n");
    }
}

void enfileirar(int codigo, float salario){
    Node* no = malloc(sizeof(Node));

    no->codigo = codigo;
    no->salario = salario;
    no->next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = no;
        return;
    }
    rear->next = no;
    rear = no;
}

void desenfileirar(){
    Node* temp = front;
    if(front == NULL){
        return;
    }else if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }

    free(temp);
}

void imprimir(){
    Node* temp = front;

    while(temp != NULL){
        printf("Codigo do funcionario: %d\n", temp->codigo);
        printf("Salario do funcionario: %.2f\n\n", temp->salario);
        temp = temp->next;
    }
}

void function_a(){
    Node* temp = front;
    float menor, maior, media;
    int n;

    maior = menor = temp->salario;
    n = 0;
    media = 0;

    while(temp != NULL){
        if(temp->salario > maior) 
            maior = temp->salario;
        if(temp->salario < menor)
            menor = temp->salario;
        media += temp->salario;
        n++;

        temp = temp->next;
    }

    media = media/n;

    printf("Maior salario: %.2f\nMenor salario: %.2f\nMedia salarial: %.2f\n", maior, menor, media);
}

void function_b(){
    Node* temp = front;
    float somaSalario = 0;
    int n = 0;

    while(temp != NULL){
        somaSalario += temp->salario;
        n++;

        temp = temp->next;
    }

    printf("Quantidade de salarios: %d\nSoma dos salarios: %.2f\n", n, somaSalario);
}