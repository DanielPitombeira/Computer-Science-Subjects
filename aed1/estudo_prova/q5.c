#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void push(int data){
    if((rear + 1) % MAX == front){
        printf("fila cheia\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = data;
    }
    else{
        rear = (rear + 1) % MAX;
        queue[rear] = data;
    }
}

void pop(){
    if(front == -1 && rear == -1){
        printf("fila vazia\n");
        return;
    }else if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % MAX;
    }
}

void function(){
    int n = rear - front + 1;
    int v[n], i = 0;

    while(front != rear){
        if(queue[front] >= 0)
            v[i++] = queue[front];

        pop();
    }

    if(front == rear){
        v[i++] = queue[front];
        pop();
    }

    for(int j = 0; j < i; j++)
        push(v[j]);
}

void print(){
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);

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