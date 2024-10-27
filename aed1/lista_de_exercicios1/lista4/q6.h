#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *create_node(int v);
node *cria_lista(node *head, int *v, int n);
void print(node *head);