#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

int isEmpty();
node* create_node(int data);
void pushAtBegg(int data);
void pushAtEnd(int data);
void popAtBegg();
void popAtEnd();
void search(int data);
void number();
void print();