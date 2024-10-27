#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

extern node* stack1;
extern node* stack2;

node* create_node(int data);
void push(int data, node** stack);
void pop();
void copia();
void print();
