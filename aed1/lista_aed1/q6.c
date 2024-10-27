#include "q6.h"

node* front1 = NULL;
node* rear1 = NULL;

node* front2 = NULL;
node* rear2 = NULL;

node* front3 = NULL;
node* rear3 = NULL;

node* create_node(int data){
    node* no = malloc(sizeof(node));
    no->data = data;
    no->next = NULL;

    return no;
}

void queue(int data, node** front, node** rear){
    node* no;

    no = create_node(data);

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

void new_queue(){
    node* v = NULL;
    int n = 0;

    while(front1 != NULL){
        n++;
        node* temp = realloc(v, n * sizeof(node));

        v = temp;
        v[n-1].data = front1->data;

        pop(&front1, &rear1);
    }

    while(front2 != NULL){
        n++;
        node* temp = realloc(v, n * sizeof(node));

        v = temp;
        v[n-1].data = front2->data;

        pop(&front2, &rear2);
    }

    int aux;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(v[i].data > v[j].data){
                aux = v[i].data;
                v[i].data = v[j].data;
                v[j].data = aux;
            }
        }
    }

    for(int i = 0; i < n; i++){
        queue(v[i].data, &front3, &rear3);
    }

}

void print(){
    node* temp = front3;

    while(temp != NULL){
        printf("%d\n", temp->data);

        temp = temp->next;
    }
}
