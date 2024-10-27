#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node node;

extern node* front_impar;
extern node* rear_impar;

extern node* front_par;
extern node* rear_par;

extern node* stack;

node* create_node(int data);
void push_fila(int data, node** front, node** rear);
void pop_fila(node** front, node** rear);
void push_pilha(int data);
void pop_pilha();
void funcao();
void print();
