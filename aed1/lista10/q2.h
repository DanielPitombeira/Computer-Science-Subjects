#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node Node;

void pilha_vazia();
void empilhar(int data, int *tam);
void desempilhar(int *tam);
void imprimir();