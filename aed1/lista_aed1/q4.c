#include "q4.h"

node* front = NULL;
node* rear = NULL;

void queue(int registro, int tempo){
    node* no;

    no = malloc(sizeof(node));
    no->registro = registro;
    no->tempo = tempo;
    no->next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = no;
        return;
    }

    rear->next = no;
    rear = no;
}

void unqueue(){
    node* temp = front;

    if(front == NULL){
        return;
    }else if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }

    free(temp);
}

void top(){
    printf("registro: %d\ntempo: %d\n", front->registro, front->tempo);
    unqueue();
}

void print(){
    node* temp = front;
    while(temp != NULL){
        printf("registro: %d\n", temp->registro);
        printf("tempo: %d\n", temp->tempo);

        temp = temp->next;
    }
}

void time(){
    node* v = NULL;
    int i = 0;

    while(front != NULL){
        i++;
        node* temp = realloc(v, i*sizeof(node));

        v = temp;
        v[i-1].registro = front->registro;
        v[i-1].tempo = front->tempo + 1;

        unqueue();
    }

    for(int j = 0; j < i; j++){
        queue(v[j].registro, v[j].tempo);
    }
}
