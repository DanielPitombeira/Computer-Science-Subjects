#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node node;
int empty_list();
node* new_node(int data);
void insert_beginning(int data);
void insert_end(int data);
void pop_beginning();
void pop_end();
void print_from_beginnig();
void print_from_end();
