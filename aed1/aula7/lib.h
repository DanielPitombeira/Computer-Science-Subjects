#include <stdio.h>
#include <stdlib.h>

struct node{
    int dado;
    struct node *link;
};

typedef struct node node;

node *create_node(int data);
node *addend(node *head, int nos);
node *add_at_the_beginning(node *head, int data);
node *add_pos(node *head, int data, int position);
node *apaga_ini(node *head);
node *apaga_fim(node *head);
node *del_pos(node *head, int position);
node *reverse(node *head);
void count_node(node *head);
void print_dado(node *head);