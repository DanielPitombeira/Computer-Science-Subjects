#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

node* front = NULL;
node* rear = NULL;

node* create_node(int data){
    node* no;

    no = malloc(sizeof(node));
    no->data = data;
    no->next = NULL;

    return no;
}

void push(int data){
    node* no;

    no = create_node(data);

    if(front == NULL && rear == NULL){
        front = rear = no;
        return;
    }

    rear->next = no;
    rear = no;
}

void pop(){
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

void function(){
    int* v = NULL, i = 0, count = 0;

    while(front != NULL){
        if(front->data >= 0){
            count++;
            int* temp = realloc(v, count * sizeof(int));

            v = temp;
            v[i] = front->data;
            i++;
        }
        pop();
    }

    for(int j = 0; j < i; j++)
        push(v[j]);

    free(v);
}

void print(){
    node* temp = front;

    while(temp != NULL){
        printf("%d ", temp->data);

        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int op, data, aux = 0;

    while(1){
        printf("operacoes: \n");
        printf("1- push\n");
        printf("2- sair\n");

        scanf("%d", &op);

        switch(op){
            case 1: 
                printf("valor: \n");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                aux = 1;
                break;
            default:
                printf("valor invalido\n");
        }

        if(aux == 1)
            break;
    }

    function();
    print();

    return 0;
}
