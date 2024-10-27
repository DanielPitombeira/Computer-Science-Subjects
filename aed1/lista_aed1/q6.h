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

extern node* front3;
extern node* rear3;

void queue(int data, node** front, node** rear);
node* create_node(int data);
void pop(node** front, node** rear);
void print();
void new_queue();
