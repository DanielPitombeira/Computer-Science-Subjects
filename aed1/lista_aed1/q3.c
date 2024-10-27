#include "q3.h"

node* front1 = NULL;
node* rear1 = NULL;

node* front2 = NULL; // fila 1 armazena valores menores ou iguais
node* rear2 = NULL;

node* front3 = NULL; // fila 2 armazena valores maiores
node* rear3 = NULL;

node* create_node(int prioridade){
    node* no;

    no = malloc(sizeof(node));
    no->prioridade = prioridade;
    no->next = NULL;

    return no;
}

void enfileirar(int prioridade, node** front, node** rear){
    node* no;

    no = create_node(prioridade);

    if(*front == NULL && *rear == NULL){
        *front = *rear = no;
        return;
    }

    (*rear)->next = no;
    *rear = no;
}

void pop(node** front, node** rear){
    node* temp = *front;

    if(*front == NULL){
        return;
    }else if(*front == *rear){
        *front = *rear = NULL; 
    }else{
        *front = (*front)->next;
    }

    free(temp);
}

void divida_filas(int p){
    while(front1 != NULL){
        if(front1->prioridade <= p){
            enfileirar(front1->prioridade, &front2, &rear2);
        }else{
            enfileirar(front1->prioridade, &front3, &rear3);
        }

        pop(&front1, &rear1);
    }
}

void imprimir(node** front, node** rear){
    node* temp = *front;

    while(temp != NULL){
        printf("%d \n", temp->prioridade);
        temp = temp->next;
    }
}
