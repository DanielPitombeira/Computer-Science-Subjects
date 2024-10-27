#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *create_node(int valor);
node *create_list(node *head, int n);
node *ordena(node *head1, node *head2);
void print(node *head);