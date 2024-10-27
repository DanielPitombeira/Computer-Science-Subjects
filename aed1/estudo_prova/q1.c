#include "q1.h"

node* tail = NULL;

int isEmpty(){
    if(tail == NULL){
        return 1;
    }else{
        return 0;
    }
}

node* create_node(int data){
    node* no;

    no = (node* )malloc(sizeof(node));
    no->data = data;
    no->next = NULL;

    return no;
}

void pushAtBegg(int data){
    node* no;

    no = create_node(data);

    if(isEmpty()){
        no->next = no;
        tail = no;
        return;
    }

    no->next = tail->next;
    tail->next = no;
}

void pushAtEnd(int data){
    node* no;

    no = create_node(data);

    if(isEmpty()){
        no->next = no;
        tail = no;
        return;
    }

    no->next = tail->next;
    tail->next = no;
    tail = tail->next;
}

void popAtBegg(){
    if(isEmpty()){
        return;
    }

    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return;
    }

    node* temp = tail->next;
    tail->next = temp->next;
    free(temp);
}

void popAtEnd(){
    if(isEmpty()){
        return;
    }

    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return;
    }

    node* temp = tail->next;

    while(temp->next != tail){
        temp = temp->next;
    }

    temp->next = tail->next;
    free(tail);
    tail = temp;
}

void search(int data){
    node* temp = tail->next;

    do{
        printf("%d\n", temp->data);
        temp = temp->next;
    }while(temp != tail->next);
}

void number(){
    node* temp = tail->next;
    int count = 0;

    do{
        count++;
        temp = temp->next;
    }while(temp != tail->next);

    printf("%d\n", count);
}

void print(){
    node* temp = tail->next;

    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != tail->next);

    printf("\n");
}