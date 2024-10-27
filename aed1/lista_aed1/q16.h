#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

extern node* front1;
extern node* rear1;

extern node* front2;
extern node* rear2;

node* create_node(int data);
void push(int data, node** front, node** rear);
void pop();
void apaga();
void print();
