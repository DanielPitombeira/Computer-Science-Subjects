#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

extern node* stack1;
extern node* stack2;

void push(int data, node** stack);
node* create_node(int data);
void pop();
void inverter();
void print();
