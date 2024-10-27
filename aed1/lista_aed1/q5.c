#include "q5.h"

node* front;
node* rear;

int decolar(){
    node* temp = front;

    if(front == NULL){
        printf("fila vazia\n");
        return 0;
    }else if(front == rear){
        front = rear = NULL;
        return 0;
    }else{
        front = front->next;
        return 1;
    }

    free(temp);
}

void adicionar(char nome[], int identificador){
    node* no;

    no = malloc(sizeof(node));
    strcpy(no->nome, nome);
    no->identificador = identificador;
    no->next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = no;
        return;
    }

    rear->next = no;
    rear = no;
}

void print(){
   node* temp = front;

   while(temp != NULL){
        printf("identificador: %d\n", temp->identificador);
        printf("nome: %s\n", temp->nome);

        temp = temp->next;
   }
}

void top(){
    node* temp = front;

    if(front == NULL){
        printf("fila vazia\n");
        return;
    }

    printf("nome: %s\n", front->nome);
    printf("identificador: %d\n", front->identificador);

}
