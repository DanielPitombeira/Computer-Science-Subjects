#include "q5.h"

struct node* head = NULL;

int empty_list(){
    if(head == NULL){
        printf("lista vazia\n");
        return 1;
    }
    return 0;
}

node* new_node(int data){
    node* new_node;

    new_node = malloc(sizeof(node));
    new_node->data = data;

    return new_node;
}

void insert_beginning(int data){
    node* no;
    no = new_node(data);

    no->next = head;
    no->prev = NULL;

    if(head != NULL){
        head->prev = no;
    }

    head = no;
}

void insert_end(int data){
    node* no;
    no = new_node(data);
    no->next = NULL;

    if(head == NULL){
        no->prev = NULL;
        head = no;
    }else{
        node* aux = head;

        while(aux->next != NULL){
            aux = aux->next;
        }

        aux->next = no;
        no->prev = aux;
    }
}

void pop_beginning(){
    if(empty_list == 1){
        return;
    }

    node* aux = head;

    head = aux->next;
    aux->next->prev = head;

    free(aux);
}

void pop_end(){
    if(empty_list == 1){
        return;
    }

    node* aux = head;

    while(aux != NULL){
        aux = aux->next;
    }

    aux->prev->next = NULL;
    free(aux);
}

void print_from_beginnig(){
    node* aux = head;

    while(aux != NULL){
        printf("valor: %d\n", aux->data);
        aux = aux->next;
    }
}

void print_from_end(){
    node* aux = head;

    while(aux != NULL){
        aux = aux->next;
    }

    while(aux != head){
        printf("valor: %d\n", aux->data);
        aux = aux->prev;
    }
}