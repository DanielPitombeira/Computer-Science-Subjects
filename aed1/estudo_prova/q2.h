#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

typedef struct node node;

int isEmpty();
node* create_node(int data);
void pushAtBegg(int data);
void pushAtEnd(int data);
void popAtBegg();
void popAtEnd();
void printAtBegg();
void printAtEnd();