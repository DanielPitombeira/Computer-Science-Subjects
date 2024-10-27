#include <stdio.h>
#include <stdlib.h>

struct node {
    double real;
    int prioridade;
    struct node* next;
};

typedef struct node node;

// Declare the extern variables in the header file
extern node* front1;
extern node* rear1;
extern node* front2;
extern node* rear2;
extern node* front3;
extern node* rear3;

// Function declarations
node* create_node(int prioridade);
void enfileirar(int prioridade, node** front, node** rear);
void pop(node** front, node** rear);
void divida_filas(int p);
void imprimir(node** front, node** rear);

