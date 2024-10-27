#include <stdio.h>
#include <stdlib.h>

struct Node{
    int codigo;
    float salario;
    struct Node* next;
};

typedef struct Node Node;

void fila_vazia();
void enfileirar(int codigo, float salario);
void desenfileirar();
void imprimir();
void function_a();
void function_b();