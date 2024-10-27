#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

node* create_node(int data);
void push(int data);
void pop();
void print();