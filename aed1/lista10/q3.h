#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    int codigo;
    char nome[50];
    int quantidade;
}Produto;

typedef struct Node {
    Produto produto;
    struct Node* next;
}Node;

void push(Produto produto);
Produto pop();
int isEmpty();
void top();