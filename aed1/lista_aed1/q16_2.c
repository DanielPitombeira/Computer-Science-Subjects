#include "q16_2.h"
#define MAX 100000

int queue1[MAX];
int front1 = -1;
int rear1 = -1;

int queue2[MAX];
int front2 = -1;
int rear2 = -1;

void push1(int data){
    if ((rear1+1) % MAX == front1){
        printf("cheia\n");
        return;
    }else if(front1 == -1 && rear1 == -1){
        front1 = rear1 = 0;
        queue1[rear1] = data;
    }else{
        rear1 = rear1 + 1;
        queue1[rear1] = data;
    }
}

void push2(int data){
    if ((rear2+1) % MAX == front2){
        printf("cheia\n");
        return;
    }else if(front2 == -1 && rear2 == -1){
        front2 = rear2 = 0;
        queue2[rear2] = data;
    }else{
        rear2 = rear2 + 1;
        queue2[rear2] = data;
    }
}

void apaga_negativos(){
    while(front1 <= rear1){
        if(queue1[front1] >= 0)
            push2(queue1[front1]);

        front1 = front1 + 1;
    }
}

void print(){
    int front = front2;
    while(front <= rear2){
        printf("%d\n", queue2[front]);

        front = front + 1;
    }
}
